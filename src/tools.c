#include "basket.h"

void	init_data(t_data *data)
{
  data->pos = 5;
  data->score = 0;
  data->bell[0].y = 0;
  data->bell[0].x = rand() % 10;
  data->level = 200000;
}

void	timer(t_data *data, int	*time)
{
  if (*time + data->level <= clock())
    {
      *time = clock();
      ++data->bell[0].y;
    }
}
