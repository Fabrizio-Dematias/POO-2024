from fastapi import FastAPI, HTTPException
from pymongo import MongoClient
from pydantic import BaseModel

client = MongoClient("mongodb://localhost:27017/")
db = client["POO"]
collection = db["POO"]

app = FastAPI()


class User(BaseModel):
    nombre: str
    apellido: str
    usuario: str
    clave: str


@app.get("/users/")
async def get_all_users():
    cursor = collection.find()
    users = []
    for user in cursor:
        user["_id"] = str(user["_id"])
        users.append(user)
    return users

