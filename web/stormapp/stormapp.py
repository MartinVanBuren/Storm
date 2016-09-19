from flask import Flask, render_template, request, jsonify

app = Flask(__name__)

# return index page when IP address of RPi is typed in the browser
@app.route("/", methods=['GET'])
def Index():
	return render_template("index.html")

@app.route("/api/test")
def Test():
	print("This is a test! :D")
	return ""

	
if __name__ == "__main__":
	app.run(host='0.0.0.0', port=8080, debug=True)
