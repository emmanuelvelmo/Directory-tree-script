import os

def mostrar_directorios(ruta, nivel = 0):
    # Verificar si la ruta existe
    if not os.path.exists(ruta):
        print("Directory not found")
        
        return

    # Obtener el nombre del directorio o archivo
    nombre = os.path.basename(ruta)

    # Mostrar el nombre con indentación según el nivel
    print("  " * nivel + "─ " + nombre if os.path.isdir(ruta) else "  " * nivel + "└ " + nombre)

    # Si es un directorio, recorrer su contenido
    if os.path.isdir(ruta):
        for elemento in os.listdir(ruta):
            # Llamada recursiva para mostrar subdirectorios y archivos
            mostrar_directorios(os.path.join(ruta, elemento), nivel + 1)

# Solicitar la ruta al usuario
ruta_usuario = input("Enter directory: ")

# Mostrar el contenido de manera jerárquica
mostrar_directorios(ruta_usuario)

# Mantener la consola abierta
input()