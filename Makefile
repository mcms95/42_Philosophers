NAME		= philo

SRCS		= main.c clean.c forks.c philo_actions.c parsing.c logger.c singleton.c time.c 

OBJS		= $(SRCS:.c=.o)

RM		= rm -f

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -g -O1
SANITIZE	= -fsanitize=thread

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) $(SANITIZE) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

sanitize:	CFLAGS += $(SANITIZE)
sanitize:	re

.PHONY:		all clean re fclean sanitize