
NAME = simplex

$(NAME).so: $(NAME)_f.o
		gcc -shared -fPIC -o lib/$(NAME).so $(NAME).o -lm
        
$(NAME)_f.o: src/$(NAME).c src/$(NAME).h
		gcc -fPIC -c $^

$(NAME).o: src/$(NAME).c src/$(NAME).h
		gcc -c $^
        

clean:
		rm -f *.o $(NAME)
		rm -f bin/$(NAME)_test
		rm -f lib/$(NAME).so

test: tests/$(NAME)_unit.c $(NAME).o
		gcc -c tests/$(NAME)_unit.c
		gcc -o bin/$(NAME)_test $(NAME).o $(NAME)_unit.o -lm
		bin/$(NAME)_test
