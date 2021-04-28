##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##

all:
	@ make -C ./generator/
	@ make -C ./solver/

clean:
	@ make clean -C ./generator/
	@ make clean -C ./solver/
	$(RM) *.txt

fclean:
	@ make fclean -C ./generator/
	@ make fclean -C ./solver/

re:	fclean all