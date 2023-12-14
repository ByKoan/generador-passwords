import random #Importamos "random" para poder mezclar la lista "caracteres" entre si de forma aleatoria.

print("Generador de contraseñas, made by Koan")

try: #Prueba a hacer el input de abajo
    longitud =int(input("Que logintud quieres que tenga su contraseña?: ")) #Pedimos que nos introduzcan un numero que lo usaremos para la longitud de la contraseña
except ValueError: #Si ha introducido algo que no sea un numero:
    print("Eso no es un numero, porfavor introduce un numero valido.") #Se imprime esta frase

contraseña = "" #Creamos la variable contraseña donde se guardara la contraseña
    
caracteres = [ #Creamos una lista de caracteres con letras en minusculas, en mayusculas, numeros y algunos caracteres especiales
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 
    'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', 
    '5', '6', '7', '8', '9', '0', '!', '@', '#', '$', '%', '&', '*', '?'
]

for i in range(longitud): #Creamos un bucle for que recorra en un rango la variable longitud
    contraseña = contraseña + random.choice(caracteres)[0] 
""" Desde el modulo "random" hacemos un "random.choice" a la variable caracteres para cojer los caracteres 
    aleatoriamente pedidos en la variable longitud y los metemos en la variable contraseña """
print("Tu contraseña es: " + contraseña) #Imprimimos la variable contraseña
