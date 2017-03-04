#include "includes/ft_ls.h"

int	ft_ls0(int flag, int len, char *flname)
{
	struct	stat	statis;
	struct	winsize	w;
	int		cpt;

	ioctl(0, TIOCGWINSZ, &w);
	cpt = w.ws_col;
	if (flag == 0 && flname[0] != '.')
	{
		len = ft_strlen(flname) + 2; // seulement pour windows
		if (cpt - len < 0)
		{
			printf("\n");
			cpt = w.ws_col;
		}
		stat(flname, &statis);
		if (S_ISREG(statis.st_mode) == 0)
			printf("\033[36;01m%-*s\033[0m", len, flname);
		else if (S_IEXEC & statis.st_mode)
			printf("\033[31m%-*s\033[0m", len, flname);
		else
			printf("%-*s", len, flname);
		cpt -= len;
	}
	return (1);
}
