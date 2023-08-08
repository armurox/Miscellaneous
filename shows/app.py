from flask import Flask, render_template, redirect, jsonify, request
import sqlite3

app = Flask(__name__)
# Ensure templates are autoreloaded
app.config["TEMPLATES_AUTO_REALOAD"] = True
con = sqlite3.connect("shows.db", check_same_thread = False)
con.row_factory = sqlite3.Row
db = con.cursor()

@app.route("/", methods = ["GET"])
def index():
    return render_template("index.html")

@app.route("/search", methods = ["GET"])
def search():
    q = request.args.get("q")
    if q:
        rows = db.execute("SELECT * FROM shows WHERE title LIKE (?) LIMIT 50", ('%' + q + '%',)).fetchall()
        # Convert rows to a list of dictionaries
        SHOWS = [dict(row) for row in rows]
    else:
        SHOWS = []
    return jsonify(SHOWS)