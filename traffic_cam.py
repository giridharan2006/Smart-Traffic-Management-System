import cv2
import serial
import time
ser = serial.Serial('COM3', 115200)
time.sleep(2)

cam1 = cv2.VideoCapture(0)
cam2 = cv2.VideoCapture(1)

def count_vehicles(frame):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray, (5,5), 0)
    _, thresh = cv2.threshold(blur, 60, 255, cv2.THRESH_BINARY)

    contours, _ = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    count = 0
    for cnt in contours:
        if cv2.contourArea(cnt) > 800:  # adjust if needed
            count += 1
    return count

while True:
    ret1, frame1 = cam1.read()
    ret2, frame2 = cam2.read()

    if not ret1 or not ret2:
        break

    c1 = count_vehicles(frame1)
    c2 = count_vehicles(frame2)

    # Send to ESP32
    data = f"{c1},{c2}\n"
    ser.write(data.encode())

    print("Lane1:", c1, "Lane2:", c2)

    cv2.imshow("Lane 1", frame1)
    cv2.imshow("Lane 2", frame2)

    if cv2.waitKey(1) == 27:
        break

cam1.release()
cam2.release()
cv2.destroyAllWindows()
ser.close()
