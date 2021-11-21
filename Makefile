## Variables ##

CC = gcc
CFLAGS = -Wall\
				 -ansi\
				 -lgraph
OFILES = damier.o \
				 menu.o \
				 choix.o \
				 end.o \
				 jeu.o \
				 bot.o \
				 blocus.o

EXE = blocus

##-------------------------------------------------------------------------------------------------------------------##

all : $(EXE)

bot.o : bot.h
jeu.o : jeu.h
damier.o : damier.h
menu.o : menu.h
choix.o : choix.h
end.o : end.h
blocus.o : $(OFILES)

$(EXE) : $(OFILES)
		$(CC) $(CFLAGS) -o $(EXE) $(OFILES)

##-------------------------------------------------------------------------------------------------------------------##

## Règles optionnelles ##

clean :
	-rm -f $(OFILES)

run :
	-./blocus
