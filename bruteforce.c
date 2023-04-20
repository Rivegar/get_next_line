#include <unistd.h>
#include <time.h>
#include <stdlib.h>
int	main(int nargs, char **args)
{
	int		sz, i;
	float	dec_word, dec_line;
	float	lim_word, lim_line;
	char	c[2];
	c[0] = 'a';
	c[1] = '\0';
	sz = 1;
	if (nargs > 1)
		sz = 1024;
	srand(time(NULL));
	dec_word = 0.9;
	dec_line = 0.99;
	lim_line = RAND_MAX;
	while (sz--)
	{
		i = 0;
		while (i < 1048576)
		{
			lim_word = RAND_MAX;
			while (rand() < lim_word)
			{
				c[0] = 'a' + rand()/82595524;
				write(1, c, 1);
				lim_word *= dec_word;
				i++;
			}
			if (rand() > lim_line)
			{
				write(1, "\n", 1);
				lim_line = RAND_MAX;
			}
			else
			{
				write(1, " ", 1);
				lim_line *= dec_line;
			}
			i++;
		}
	}
	return (0);
}
