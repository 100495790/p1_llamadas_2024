//P1-SSOO-23/24

#include <stdio.h>		// Header file for system call printf
#include <unistd.h>		// Header file for system call gtcwd
#include <sys/types.h>	// Header file for system calls opendir, readdir y closedir
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[]) {
	char *dirname;

	/* Si no no especifican ningún directorio, trabajamos sobre el actual */
	if (argc < 2) {
		char dir_actual[1024];
		dirname = getcwd(dir_actual, sizeof(dir_actual));
	} else {
		dirname = argv[1];
	}
	
	DIR *dirp = opendir(dirname);	// Abrimos el directorio

	if (dirp == NULL) {
		perror("Error al abrir el directorio\n");
		return -1;
	}
	
	struct dirent *entry;
	while ((entry = readdir(dirp)) != NULL) {
        // Imprime el nombre de cada entrada
        printf("%s\n", entry->d_name);
    }
	

	closedir(dirp);	// Cerramos el directorio
	return 0;
}

