from flask import Flask, render_template, request, jsonify
import Pins

app = Flask(__name__)

# return index page when IP address of RPi is typed in the browser
@app.route("/")
def Index():
	return render_template("index.html")

# ajax GET call this function to set led state
# depeding on the GET parameter sent
@app.route("/_led")
def _led():
	state = request.args.get('state')
	if state=="on":
		Pins.LEDon()
	else:
		Pins.LEDoff()
	return ""


# ajax GET call this function periodically to read button state
# the state is sent back as json data
#@app.route("/_button")
#def _button():
#    if Pins.ReadButton():
#        state = "pressed"
#    else:
#        state = "not pressed"
#    return jsonify(buttonState=state)
	
# run the webserver on standard port 80, requires sudo
if __name__ == "__main__":
	Pins.Init()
	app.run(host='0.0.0.0', port=8080, debug=False)
