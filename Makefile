SERVER = server
CLIENT = client
SRC_SERVER	= 	src/server.c src/utils.c src/ft_itoa.c src/ft_atoi.c
SRC_CLIENT	=	src/client.c src/utils.c src/ft_itoa.c src/ft_atoi.c
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
SRC_SERVER_BONUS = src/server_bonus.c src/utils.c src/ft_itoa.c src/ft_atoi.c
SRC_CLIENT_BONUS = src/client_bonus.c src/utils.c src/ft_itoa.c src/ft_atoi.c
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
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean : clean
	@rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re : fclean all

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS) : $(OBJ_SERVER_BONUS)
	gcc $(FLAGS) $(OBJ_SERVER_BONUS) -o $@

$(CLIENT_BONUS) : $(OBJ_CLIENT_BONUS)
	gcc $(FLAGS) $(OBJ_CLIENT_BONUS) -o $@

.PHONY : all clean fclean re bonus
