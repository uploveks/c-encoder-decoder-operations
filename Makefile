CFLAGS += -c -g -Wall -Wextra -Wpedantic \
                  -Wformat=2 -Wno-unused-parameter \
                  -Wshadow -Wwrite-strings -Wstrict-prototypes \
                  -Wold-style-definition -Wredundant-decls \
                  -Wnested-externs -Wmissing-include-dirs \
                  -Wjump-misses-init -Wlogical-op -O2

PATH_TO_FILES += ../src

.PHONY: build clean

build: encoder opernum decoder

encoder: encoder.o
	@gcc encoder.o -o encoder

encoder.o: $(PATH_TO_FILES)/encoder.c
	@gcc $(CFLAGS) $(PATH_TO_FILES)/encoder.c

opernum: opernum.o
	@gcc opernum.o -o opernum

opernum.o: $(PATH_TO_FILES)/opernum.c
	@gcc $(CFLAGS) $(PATH_TO_FILES)/opernum.c

decoder: decoder.o
	@gcc decoder.o -o decoder

decoder.o: $(PATH_TO_FILES)/decoder.c
	@gcc $(CFLAGS) $(PATH_TO_FILES)/decoder.c

clean:
	@find . -type f -not -name 'Makefile' -delete