SERVER = server
CLIENT = client

SRC_SERVER	= 	server.c utils.c ft_itoa.c
SRC_CLIENT	=	client.c utils.c ft_itoa.c
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS	=	$(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS	=	$(SRC_CLIENT_BONUS:.c=.o)

 FLAGS = -Wall -Wextra -Werror

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ_SERVER)
	gcc $(FLAGS) $(OBJ_SERVER) -o $@

$(CLIENT) : $(OBJ_CLIENT)
	gcc $(FLAGS) $(OBJ_CLIENT) -o $@

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean : clean
	@rm -f $(SERVER) $(CLIENT)

re : fclean all

bonus:

.PHONY : all clean fclean re bonus
