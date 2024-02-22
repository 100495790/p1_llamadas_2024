//P1-SSOO-23/24

#include <stdio.h>


int main(int argc, char *argv[])
{
	/*If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error y return -1*/
	if(argc < 2)
	{
		printf("Too few arguments\n");
		return -1;
	}

    int *archivo = open(const char argv[1], int 0_RDONLY); // abrimos el archivo en modo lectura

    if(NULL == archivo){
        perror("No se pudo abrir el archivo");
        return -1;
    }

    int byte = 0;	
    int contador_bytes = 0;
	int contador_palabras = 0;
	int contador_lineas = 0;

    while ((byte = getc(archivo)) != EOF) {
		printf("%d\n", byte);
        contador_bytes ++;
		if (byte == '\n') {
			contador_lineas ++; 
			contador_palabras ++; 
		}
		if (byte == ' ' || byte =='\t') {
			contador_palabras ++; 
		}

    }

    int close(int archivo);
    printf("Contador bytes: %d\n", contador_bytes); 
	printf("Contador palabras: %d\n", contador_palabras); 
	printf("Contador lonst ch
}
