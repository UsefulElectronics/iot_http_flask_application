from flask import Flask, redirect, url_for, render_template
app = Flask(__name__)
#In order to find the page below it should have a root
#"/" This is the path we are going to use to reach the page below
@app.route("/")         
#Define a home page
def home():         
    #What the page is going to display    
    return render_template("index.html")
#pass a value through URL <val> for a new page
@app.route("/<value>")
#define a new page that uses value as a parameter
def user(value):
    #f is necessary to indicate that this page is going to use value
    #the value to be used must be put within brackets{}
    return f"hello {value} !"

@app.route("/admin")
def admin():
    #redirecting from a admin route to the home page
    return redirect(url_for("home"))
if __name__ == "__main__":
    app.run()