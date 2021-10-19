from flask import Flask,render_template,request,redirect,send_from_directory,send_file

app = Flask(__name__)
from firebase import *

# uploads_dir = tempfile.gettempdir()

# os.makedirs(os.path.join(uploads_dir,"steno"), exist_ok=True)
# uploads_dir = os.path.join(uploads_dir,"steno")
variable = "-"
@app.route('/',methods=['GET'])
def check():
    if request.method == 'GET':
        return readState()

@app.route('/modify',methods=['GET'])
def modify():
    if request.method == 'GET':
        variable = request.args.get("move")
        return modifyState(variable)
        # profile = request.files['file']
        # path = os.path.join(uploads_dir, secure_filename(profile.filename))
        # path = os.path.join(uploads_dir, profile.filename)

        # # print(request.args)
        # message = request.form['message']
        
        # profile.save(path)
        # # print("Saved")
    
        # audio = wave.open(path,mode="rb")
        # # print("Opened")
        
        # encode(audio,profile.filename,message)
        # # print("Encoded")
        
        # return send_file(os.path.join(uploads_dir,profile.filename+"encoded"),
        #     mimetype = 'wav',
        #     attachment_filename= profile.filename+"_encoded.wav",
        #     as_attachment = True)
        # return send_from_directory(os.path.join(uploads_dir, 'sampleStego.wav'),filename="encoded.wav",as_attachment=True)

