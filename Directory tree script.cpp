#include <iostream>
#include <filesystem>
#include <string>

void mostrar_directorios(const std::string& ruta, int nivel = 0)
{
    // Verificar si la ruta existe
    if (!std::filesystem::exists(ruta))
    {
        std::cout << "Directory not found" << std::endl;
        
        return;
    }

    // Obtener el nombre del directorio o archivo
    std::string nombre = std::filesystem::path(ruta).filename().string();

    // Mostrar el nombre con indentación según el nivel
    std::cout << std::string(nivel * 2, ' ') << (std::filesystem::is_directory(ruta) ? "─ " : "└ ") << nombre << std::endl;

    // Si es un directorio, recorrer su contenido
    if (std::filesystem::is_directory(ruta))
    {
        for (const auto& elemento : std::filesystem::directory_iterator(ruta))
        {
            // Llamada recursiva para mostrar subdirectorios y archivos
            mostrar_directorios(elemento.path().string(), nivel + 1);
        }
    }
}

int main()
{
    // Solicitar la ruta al usuario
    std::string ruta_usuario;
    std::cout << "Enter directory: ";
    std::getline(std::cin, ruta_usuario);

    // Mostrar el contenido de manera jerárquica
    mostrar_directorios(ruta_usuario);

    // Mantener la consola abierta
    std::cin.get();

    return 0;
}