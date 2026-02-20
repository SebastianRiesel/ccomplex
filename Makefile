CFLAGS+=-Wall -Werror -Wextra -fsanitize=address -O3
LDLIBS+=-lm
clean:
	$(RM) *.o

ccomplex.o: ccomplex.h



