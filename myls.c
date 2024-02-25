//P1-SSOO-23/24

#include <stdio.h>		// Header file for system call printf
#include <unistd.h>		// Header file for system call gtcwd
#include <sys/types.h>	// Header file for system calls opendir, readdir y closedir
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[]) {
	char *dirname;

	// Si no se especifica ningún directorio, trabajamos sobre el actual
	if (argc < 2) {
		char dir_actual[1024];
		// Usamos la funcion getcwd para obtener el directorio actual
		dirname = getcwd(dir_actual, sizeof(dir_actual));
	} else {
		dirname = argv[1];
	}
	
	DIR *dirp = opendir(dirname);	// Abrimos el directorio

	// Si no se encuentra el directorio imprimimos un error y devolvemos -1
	if (dirp == NULL) {
		perror("Error al abrir el directorio\n");
		return -1;
	}
	
	// Leemos las entradas del directorio una por una e imprimimos su nombre
	struct dirent *entry;
	while ((entry = readdir(dirp)) != NULL) {
        printf("%s\n", entry->d_name);
    }
	
	closedir(dirp);	// Cerramos el directorio
	return 0;
}
