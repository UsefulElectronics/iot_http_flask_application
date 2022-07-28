# from crypt import methods
from flask import Flask, redirect, url_for, render_template, request
from flask_sqlalchemy import SQLAlchemy
from requests import session
from sqlalchemy import Column, null
app = Flask(__name__)
#dataTable is the name of data base table
#Configuring SQLALCHEMY parameters
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///dataTable.sqlite3'
app.config['SQLALCHEMY_TRACK_MODAFICATIONS'] = False

db = SQLAlchemy(app)
#configure a database module
class dataTable(db.Model):
    #Columns are information types and rows are the unique data
    #every row will have a unique "value" and this id is an integer (db.Integer) and activate that adressing feature (primary_key=True)
    id      = db.Column(db.Integer, primary_key=True) 
    Remote  = db.Column(db.String(50))
    def __INIT__(self,Remote):
        self.Remote = Remote

# newValue = dataTable(id = 1, Remote = "hi")

# db.session.add
# db.session.commit()

#In order to find the page below it should have a root
#"/" This is the path we are going to use to reach the page below
@app.route("/", methods = ["GET","POST"])         
#Define a home page
def home():
    if request.method == "POST":   
        value = request.form["obtained"]
        # newValue = dataTable(id = 1, Remote = value)
        # newValue = dataTable(id = 1)
        newValue = dataTable.query.filter_by(id = 1).first()
        print(newValue.Remote)
        print(newValue.id)
        newValue.Remote = value
        print(newValue.Remote)
        print(newValue.id)
        
        # db.session.add(newValue)
        db.session.commit()
        #What the page is going to display    
        return render_template("index.html", value = newValue.Remote)
    else:

        memValue = dataTable.query.filter_by(id = 1).first()
        print(memValue.Remote)
        return render_template("index.html", value= memValue.Remote)

@app.route("/test")         
def test():         
    return render_template("test.html")

if __name__ == "__main__":
    db.create_all()
    app.run(host="0.0.0.0")