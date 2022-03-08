NAME	=	ex00

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

CPFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

.cpp.o:		whatever.hpp
			clang++ $(CPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			clang++ $(CPFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)
			
.PHONY:		all clean fclean re