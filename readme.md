### ESP32Thing For AWSIoT
---

ตัว repository นี้ผมสร้างขึ้นมาประกอบใช้กับบทความ [มาเล่น AWS IoT กันเถอะ EP.3 Rule engine & Rule action](https://iamteam.me/%E0%B8%A1%E0%B8%B2%E0%B9%80%E0%B8%A5%E0%B9%88%E0%B8%99-aws-iot-%E0%B8%81%E0%B8%B1%E0%B8%99%E0%B9%80%E0%B8%96%E0%B8%AD%E0%B8%B0-ep-3-rule-engine-rule-action-db583213f84d) สามารถ Download เพื่อนำศึกษาการทำงานได้

![Overview](/images/Overview.jpg)

#### การตั้งค่าตัวแปร
ใน file `network_config.h` ที่อยู่ใน folder `include/` อย่าลืมกำหนดค่าให้กับตัวแปรเหล่านี้ด้วยนะครับ

```
#define SSID "Your SSID"
#define PASS "Your PASSWORD"

#define AWS_HOST "YOUR AWS HOST"
```

#### การตั้งค่า Certificate

ใน folder `data/` ผมได้นำ file certificate ของผมออกไป ดังนั้นตามบทความ [มาเล่น AWS IoT กันเถอะ EP.1](https://iamteam.me/%E0%B8%A1%E0%B8%B2%E0%B9%80%E0%B8%A5%E0%B9%88%E0%B8%99-aws-iot-%E0%B8%81%E0%B8%B1%E0%B8%99%E0%B9%80%E0%B8%96%E0%B8%AD%E0%B8%B0-ep-1-e7fcdbbeed37) ผมได้พูดถึงการ Download certificate มาแล้ว และทำการ flash ข้อมูลไปยัง File System ใน ESP32

ดังนั้น ภายใน folder `data` ควรจะมี file certificate ตามด้านล่าง
```
data
  |_ CA.pem
  |_ certificate.crt
  |_ private_key.key
```

ติดปัญหาสงสัยอะไรสามารถสอบถามได้ที่ [Facebook](https://facebook.com/TeamKungElectronic) ผมได้เลยครับ

สุดท้ายนี้ก็ขอขอบคุณ แล้วก็ฝากติดตามที่ blog [I AM {TEAM}](https://iamteam.me) เพื่อเป็นกำลังใจและติดตามบทความใหม่ ๆ ครับ