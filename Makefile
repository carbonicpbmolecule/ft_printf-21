all:
	gcc main.c src/*.c libft/libft.a -o ft_printf

mod_tests:
	gcc test/main.c src/*.c libft/libft.a -o mod_tests

clean:
	rm -f ft_printf mod_tests

mod_tests_re: clean
	gcc test/main.c src/*.c libft/libft.a -o mod_tests