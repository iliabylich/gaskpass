CFLAGS += -std=c23 -O3 -g -Wall -Wextra

CFLAGS += `pkg-config --cflags gtk4`
LDFLAGS += `pkg-config --libs gtk4`

gaskpass: main.c
	$(CC) main.c $(CFLAGS) $(LDFLAGS) -o gaskpass

compile_commands.json:
	# pipx install compiledb
	compiledb make gaskpass

clean:
	rm -f gaskpass
