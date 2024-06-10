import pymongo

# Conexión a MongoDB
client = pymongo.MongoClient("mongodb+srv://fabriziodematias:Fabrizio99@poo.ap6sxmq.mongodb.net/")
db = client["usuariosdb"]
collection = db["usuarios"]

# Insertar usuarios
usuarios = [
    {"nombre": "Juan", "apellido": "Perez", "usuario": "juan123", "clave": "password123"},
    {"nombre": "María", "apellido": "Gomez", "usuario": "maria456", "clave": "qwerty456"},
    {"nombre": "Pedro", "apellido": "Martinez", "usuario": "pedrito", "clave": "abc123"}
]

collection.insert_many(usuarios)