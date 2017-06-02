#include <curses.h>
#include <unistd.h>
#include "basket.h"

static int	game_over()
{
  int	c;

  erase();
  printw("\t GAME OVER !\n\n");
  printw("Press 'R' to restart,\n");
  printw("\t'Esc' to quit.");
  while ((c = getch()) != 'r' && c != 27);
  if (c == 'r')
    return (1);
  else
    return (0);
}

static void	printer(t_data *data)
{
  int		i;
  int		j;

  printw("Score : %d\n\n", data->score);
  i = -1;
  while (++i < 11)
    {
      j = -1;
      while (++j < 10)
	{
	  if (j == data->bell[0].x && i == data->bell[0].y)
	    {
	      printw("o");
	      ++j;
	    }
	  if (j == data->pos && i == 10)
	    {
	      printw("\\_/");
	      j += 3;
	    }
	  (j < 10) ? printw(".") : printw("");
	}
      printw("\n");
    }
}

static int	collider(t_data *data)
{
  if (data->bell[0].y == 10 &&
      (data->pos == data->bell[0].x
       || data->pos + 1 == data->bell[0].x
       || data->pos + 2 == data->bell[0].x))
    {
      data->score++;
      data->bell[0].x = rand() % 10;
      data->bell[0].y = 0;
      data->level -= (data->level - 1000 > 0 && data->score % 7 == 0) ?
	10000 : 0;
      return (0);
    }
  else if (data->bell[0].y == 10)
      return (1);
  else
    return (0);
}

static int	launcher()
{
  int		c;
  WINDOW	*win;
  t_data	data;
  int		time;

  init_data(&data);
  win = initscr();
  nodelay(win, 1);
  noecho();
  keypad(win, 1);
  time = clock();
  while ((c = getch()) != ESC && !collider(&data))
    {
      erase();
      printer(&data);
      if (c == KEY_RIGHT && data.pos + 3 < 10)
	data.pos += 1;
      if (c == KEY_LEFT && data.pos > 0)
	data.pos -= 1;
      curs_set(0);
      timer(&data, &time);
      /* if (time + data.level <= clock()) */
      /* 	{ */
      /* 	  time = clock(); */
      /* 	  data.bell[0].y += 1; */
      /* 	} */
    }
  return ((c == ESC) ? 0 : game_over());
}

int	main()
{
  srand(time(0));
  while (launcher() != 0);
  endwin();
  return (0);
}
