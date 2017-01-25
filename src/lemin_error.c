# include "main.h"

int		lerror_parse(int n)
{
	if (n == 0)
		ft_putendl("error 10 - ant number undefined or less than 1.");
	if (n == 1)
		ft_putendl("error 11 - two rooms can't have the same name");
	if (n == 2)
		ft_putendl("error 12 - trying to link an undefinded room");
	if (n == 3)
		ft_putendl("error 13 - undefined parsing error.");
	ft_putendl("Stoping parsing.");
	return (0);
}

int		lem_error(int n)
{
	if (!n)
		return (1);
	if (n == 1)
		ft_putendl(" - STOPPING PROCESS - ");
	if (n <= 19)
		lerror_parse(n - 10);
	return (0);
}
