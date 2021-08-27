SERVER = server
CLIENT = client
SRC_SERVER	= 	server.c
SRC_CLIENT	=	client.c
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)
# FLAGS = -Wall -Wextra -Werror

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

.PHONY : all clean fclean re
