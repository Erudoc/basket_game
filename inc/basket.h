#ifndef __BASKET_H_
#define __BASKET_H_

#include <stdlib.h>
#include <time.h>

#define ESC 27

typedef struct	s_bell
{
  int	x;
  int	y;
}		t_bell;

typedef	struct	s_data
{
  int		pos;
  int		score;
  struct s_bell	bell[3];
  int		level;
}		t_data;

void	init_data(t_data *);
void	timer(t_data *, int *);

#endif
