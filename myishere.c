//P1-SSOO-23/24

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{
	/* If less than three arguments (argv[0] -> program, argv[1] -> directory to search, argv[2] -> file to find) print an error y return -1 */
	if(argc < 3)
	{
		printf("Too few arguments\n");
		return -1;
	}

	char *dirname = argv[1];
	DIR *dirp = opendir(dirname);	// Abrimos el directorio
	char *nombre_archivo = argv[2];

	// Si no se encuentra el directorio imprimimos un error y devolvemos -1
	if (dirp == NULL) {
		perror("Error al abrir el directorio\n");
		return -1;
	}

	struct dirent *entry;
	// Leemos todas las entradas del directorio
	while ((entry = readdir(dirp)) != NULL) {
		// Si la entrada actual es la buscada, imprimimos un mensaje y terminamos el programa, devolviendo 0
		if (strcmp(nombre_archivo, entry->d_name) == 0) {	// comparamos ambos nombres con la funcion strcmp
			printf("File %s is in directory %s\n", nombre_archivo, dirname);
			closedir(dirp);	// Cerramos el directorio
			return 0;
		}
	}

	// Si el archivo no está, imprimimos un mensaje y devolvemos 0, ya que no ha habido errores
	printf("File %s is not in directory %s\n", nombre_archivo, dirname);
	closedir(dirp);	// Cerramos el directorio
	return 0;
}
