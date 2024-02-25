//P1-SSOO-23/24

#include <fcntl.h>
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

	if (dirp == NULL) {
		perror("Error al abrir el directorio\n");
		return -1;
	}

	struct dirent *entry;
	while ((entry = readdir(dirp)) != NULL) {
		if (entry->d_name == nombre_archivo) {
			printf("File %s is in directory %s", nombre_archivo, entry->d_name);
			closedir(dirp);	// Cerramos el directorio
			return 0;
		}
	}
	// Si el archivo no está
	printf("File %s is not in directory %s", nombre_archivo, entry->d_name);
	closedir(dirp);	// Cerramos el directorio
	return 0;
}
