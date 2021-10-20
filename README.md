# Over-the-Internet-controlled arduino bot
- Its the part of project component of embedded systems.

## Tech Stack
- Arduino UNO
- ESP8266 Wifi module
- l293d motor drivers
- motors
- few jumper cables and chasis
- laptop
- Arduino IDE
- Flask
- HTML/CSS/JS
- Firebase(Realtime database)
- Heroku(for hosting)

## ENDPOINTS
- open `https://arduinoiotbot.herokuapp.com/control` to quickly access the bot control.
- GET `https://arduinoiotbot.herokuapp.com/` to get the current state of the bot (`w` forward, `a` left, `d` right, `s` reverse)
- GET `https://arduinoiotbot.herokuapp.com/modify?move=x` change x to one of the (`w` forward, `a` left, `d` right, `s` reverse) to change the direction of bot.
