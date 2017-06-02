NAME			:=	basket
CC			:=	@gcc
RM			:= 	@rm -f

SRC_DIR			:= 	src
OBJ_DIR			:=	obj
INC_DIR			:=	inc

CFLAGS			:=	-Wextra -Wall -Werror -pedantic
#CFLAGS			+=	-g
CFLAGS			+=	-I$(INC_DIR)

LDFLAGS			:=	-lncurses

SRC			:=	main.c\
				tools.c

SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ			:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c
				$(CC) $(CFLAGS) -c -o $@ $<
				@echo "Compile $< in $@"
all:				$(NAME)


$(NAME): 			$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
				@echo "Compile program $(NAME) with $(OBJ) files"
clean:
				$(RM) $(OBJ)
				@echo "Remove $(OBJ) files"
				$(RM) $(OBJ_DIR)/*~
				$(RM) $(OBJ_DIR)/*\#
				@echo "Remove tmp files from obj dir"
				$(RM) $(SRC_DIR)/*~
				$(RM) $(SRC_DIR)/*\#
				@echo "Remove tmp files from src dir"
				$(RM) $(INC_DIR)/*\#
				$(RM) $(INC_DIR)/*~
				@echo "Remove tmp files from inc dir"
				$(RM) *~
				$(RM) *\#

fclean: 			clean
				$(RM) $(NAME)
				@echo "Remove $(NAME)"

re:				fclean all

.PHONY:				all clean fclean re
