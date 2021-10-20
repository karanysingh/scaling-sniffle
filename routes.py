from flask import Flask,render_template,request,redirect,send_from_directory,send_file,make_response

app = Flask(__name__)
from firebase import *

# uploads_dir = tempfile.gettempdir()

# os.makedirs(os.path.join(uploads_dir,"steno"), exist_ok=True)
# uploads_dir = os.path.join(uploads_dir,"steno")
variable = "-"
@app.route('/',methods=['GET'])
def check():
    if request.method == 'GET':
        resp1 = make_response(readState())
        resp1.headers['Access-Control-Allow-Origin'] = '*'
        return resp1

@app.route('/modify',methods=['GET'])
def modify():
    if request.method == 'GET':
        variable = request.args.get("move")
        resp2 = make_response(modifyState(variable))
        resp2.headers['Access-Control-Allow-Origin'] = '*'
        return resp2