//P1-SSOO-23/24

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
	/*If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error y return -1*/
	if(argc < 2)
	{
		printf("Too few arguments\n");
		return -1;
	}

    // Abrimos el archivo en modo lectura
    char *nombre_archivo = argv[1];
    int fd = open(nombre_archivo, O_RDONLY);

	// Si no se encuentra el archivo imprimimos un error y devolvemos -1
    if(fd == -1){
        perror("No se pudo abrir el archivo");
        return -1;
    }
    
    int contador_lineas = 0;
    int contador_palabras = 0;
    int contador_bytes = 0;

    // Leemos el archivo byte por byte
    char c;
    while (read(fd, &c, sizeof(c)) > 0) {
        // Añadimos cada byte leído al contador
    	contador_bytes ++;
        // Si el byte es un salto de línea añadimos una línea al contador
    	if (c == '\n') {
    		contador_lineas ++;
    		contador_palabras ++;
    	}
    	if (c == ' ' || c == '\t') {
    		contador_palabras ++;
    	}
    }

    // Si el último byte no es un espacio, no se tiene en cuenta la última palabra, por lo que hay que añadirla al contador
    char ultimoByte;
    if (lseek(fd, -1, SEEK_END) != -1 && read(fd, &ultimoByte, 1) == 1) {
        if (ultimoByte != ' ') {
            contador_palabras ++;
        }
    }
    
    // Cerramos el archivo e imprimimos la salida
    close(fd);
    printf("%d %d %d %s\n", contador_lineas, contador_palabras, contador_bytes, nombre_archivo);
    return 0;
}
