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
    
    int contador_lineas = 0;
    int contador_palabras = 0;
    int contador_bytes = 0;
    char c;
    int bytes;
    
    while ((bytes = read(fd, &c, sizeof(c))) > 0) {
    	contador_bytes ++;
    	if (c == '\n') {
    		contador_lineas ++;
    		contador_palabras ++;
    	}
    	if (c == ' ' || c == '\t') {
    		contador_palabras ++;
    	}
    }
    
    close(fd);
    printf(" %d %d %d %s\n", contador_lineas, contador_palabras, contador_bytes, nombre_archivo);
    return 0;
}
