#include "shell.h"
#include <stdio.h>


int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		prompt(av,env);
		return (0);
	}

	return (1);
}
