#include "shell.h"

/**
 *
 */

char *_getenv(const char *name)
{
	extern char **environ;
	char **env;
	for (env = environ; *env != NULL; env++)
	{
		char *env_var = *env;
		size_t name_len = _strlen(name);
		size_t env_var_len = _strlen(env_var);

		if (name_len <= env_var_len)
		{
			size_t i;
			for (i = 0; i < name_len; i++)
			{
				if (name[i] != env_var[i])
				{
					break;
				}
			}

			if (i == name_len && env_var[i] == '=')
			{
				return (&env_var[name_len + 1]);
			}
		}
	}

	return (NULL);
}
