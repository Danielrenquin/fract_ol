


#include	"mlx_int.h"

#include	<unistd.h>
#include <X11/extensions/Xrandr.h>

/* global for independant extension */

RRMode	saved_mode = 0;


int			mlx_ext_fullscreen(t_xvar *xvar, t_win_list *win, int fullscreen)
{
  XWindowAttributes	watt;
  int			i;
  int			j;
  XRRScreenResources	*res;
  XRROutputInfo		*o_info;
  XRRCrtcInfo		*crtc;
  RRMode		mode_candidate;
  int			idx_output;
  int			idx_candidate;

  if (!XGetWindowAttributes(xvar->display, win->window, &watt))
    return (0);

  res = XRRGetScreenResources(xvar->display, xvar->root);
  o_info = NULL;
  idx_output = -1;
  i = res->noutput;
  while (i--)
    {
      o_info = XRRGetOutputInfo(xvar->display, res, res->outputs[i]);
      if (o_info->connection == RR_Connected)
	{
	  idx_output = i;
	  i = 0;
	}
      else
	XRRFreeOutputInfo(o_info);
    }
  if (!o_info)
    {
      XRRFreeScreenResources(res);
      return (0);
    }
  
  idx_candidate = -1;
  i = o_info->nmode;
  while (i--)
    {
      j = res->nmode;
      while (j--)
	if (res->modes[j].id == o_info->modes[i])
	  if (res->modes[j].width >= watt.width && res->modes[j].height >= watt.height &&
	      (idx_candidate == -1 || res-Chapter III
Overview
Here are the things you need to know if you want to succeed this assignment:
• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
• There are also forks on the table. There are as many forks as philosophers.
• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
• Every philosopher needs to eat and should never starve.
• Philosophers don’t speak with each other.
• Philosophers don’t know if another philosopher is about to die.
• No need to say that philosophers should avoid dying!
5
Chapter IV
Global rules
You have to write a program for the mandatory part and another one for the bonus part
(if you decide to do the bonus part). They both have to comply with the following rules:
• Global variables are forbidden!
• Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
◦ number_of_philosophers: The number of philosophers and also the number
of forks.
◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.
• Each philosopher has a number ranging from 1 to number_of_philosophers.
• Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.
6
Philosophers I never thought philosophy would be so deadly
About the logs of your program:
• Any state change of a philosopher must be formatted as follows:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.
• A displayed state message should not be mixed up with another message.
• A message announcing a philosopher died should be displayed no more than 10 ms
after the actual death of the philosopher.
• Again, philosophers should avoid dying!
Your program must not have any data races.
7
Chapter V
Mandatory part
Program name philo
Turn in files Makefile, *.h, *.c, in directory philo/
Makefile NAME, all, clean, fclean, re
Arguments number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
External functs. memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
Libft authorized No
Description Philosophers with threads and mutexes
The specific rules for the mandatory part are:
• Each philosopher should be a thread.
• There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.
• To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.
8
Chapter VI
Bonus part
Program name philo_bonus
Turn in files Makefile, *.h, *.c, in directory philo_bonus/
Makefile NAME, all, clean, fclean, re
Arguments number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
External functs. memset, printf, malloc, free, write, fork, kill,
exit, pthread_create, pthread_detach, pthread_join,
usleep, gettimeofday, waitpid, sem_open, sem_close,
sem_post, sem_wait, sem_unlink
Libft authorized No
Description Philosophers with processes and semaphores
The program of the bonus part takes the same arguments as the mandatory program.
It has to comply with the requirements of the Global rules chapter.
The specific rules for the bonus part are:
• All the forks are put in the middle of the table.
• They have no states in memory but the number of available forks is represented by
a semaphore.
• Each philosopher should be a process. But the main process should not be a
philosopher.
The bonus part will only be assessed if the mandatory part is
PERFECT. Perfect means the mandatory part has been integrally done
and works without malfunctioning. If you have not passed ALL the
mandatory requirements, your bonus part will not be evaluated at all.
9
Chapter VII
Submission and peer-evaluation
Turn in your assignment in your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don’t hesitate to double check the names of
your files to ensure they are correct.
Mandatory part directory: philo/
Bonus part directory: philo_bonus/
V L ( L p aW 8
) * q fx 2 u L 5 kt 6 ::/ .
? p x >g 0 Jb n R V
7 vo
v c p t g j
S 4 H .
I 6 < )
A2 5 ) E ? d
B f - Z ‘
* v
, ; I I
s C :
10>modes[idx_candidate].width > res->modes[j].width ||
	       res->modes[idx_candidate].height > res->modes[j].height) )
	    idx_candidate = i;
    }
  if (idx_candidate < 0)
    {
      XRRFreeOutputInfo(o_info);
      XRRFreeScreenResources(res);
      return (0);
    }
  if (!fullscreen && saved_mode == -1)
    idx_candidate = 0; /* if no clue, uses first mode, usually part of npreferred */
  mode_candidate = o_info->modes[idx_candidate];
  if (!fullscreen)
    mode_candidate = saved_mode;

  crtc = XRRGetCrtcInfo(xvar->display, res, o_info->crtc);
  saved_mode = crtc->mode;

  i = XRRSetCrtcConfig(xvar->display, res, o_info->crtc, CurrentTime, 0, 0, mode_candidate,
		       crtc->rotation, &res->outputs[idx_output], 1);
  if (fullscreen)
    printf("found mode : %d x %d\n Status %d\n", res->modes[idx_candidate].width, res->modes[idx_candidate].height, i);
  else
    printf("back previous mode\n");
  
  XMoveWindow(xvar->display, win->window, 0, 0);
  XMapRaised(xvar->display, win->window);

  if (fullscreen)
    {
      //      XGrabPointer(xvar->display, win->window, True, 0, GrabModeAsync, GrabModeAsync, win->window, 0L, CurrentTime);
      XGrabKeyboard(xvar->display, win->window, False, GrabModeAsync, GrabModeAsync, CurrentTime);
    }
  else
    {
      XUngrabPointer(xvar->display, CurrentTime);
      XUngrabKeyboard(xvar->display, CurrentTime);
    }

  XSync(xvar->display, False);
  sleep(1);

  XRRFreeCrtcInfo(crtc);
  XRRFreeOutputInfo(o_info);
  XRRFreeScreenResources(res);
}
