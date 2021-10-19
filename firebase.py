from firebase_admin import db
import firebase_admin
import json
value = "-"
databaseURL = "https://wireless-arduino-bot-default-rtdb.firebaseio.com/"
cred_object = firebase_admin.credentials.Certificate('./wireless-arduino-bot-firebase-adminsdk-jj79n-8b088d8efc.json')
default_app = firebase_admin.initialize_app(cred_object, {
    'databaseURL':databaseURL
    })

ref = firebase_admin.db.reference("/")


def readState():
    value = ref.get("mode")[0]["mode"]
    return str(value)

def modifyState(newVal):
    ref.set({"mode":str(newVal)})
    return readState()
    