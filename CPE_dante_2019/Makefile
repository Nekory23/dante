##
## EPITECH PROJECT, 2020
## dante
## File description:
## makefile root
##

GENERATOR =	generator/

SOLVER	=	solver/

all	:	$(OBJ)
		make -C $(GENERATOR)
		make -C $(SOLVER)

clean	:
		make clean -C $(GENERATOR)
		make clean -C $(SOLVER)

fclean	:	clean
		make fclean -C $(GENERATOR)
		make fclean -C $(SOLVER)

re	:	fclean all

.PHONY	:	all clean fclean re
