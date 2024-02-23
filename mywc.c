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
    char *nombre_archivo = argv[1];
    int fd = open(nombre_archivo, O_RDONLY); // abrimos el archivo en modo lectura

    if(fd == -1){
        perror("No se pudo abrir el archivo");
        return -1;
    }
    
    off_t contador_bytes = lseek(fd, 0, SEEK_END);
    
    if (contador_bytes == -1) {
    	perror("Error al obtener el tamaño del archivo");
    	close(fd);
    	return -1;
    }
    
    printf("El tamaño del archivo es: %ld bytes\n", contador_bytes);

    close(fd);
    // printf(" %d %d %d %s\n", contador_lineas, contador_palabras, contador_bytes, nombre_archivo);

    return 0;
}
