

.PHONY: all
all: make_package compile

.PHONY: make_package
make_package: package_build package_library



.PHONY: package_build
package_build:
	mkdir -p build/

.PHONY: package_library
package_library:
	mkdir -p build/include
	mkdir -p build/lib
	mkdir -p build/src

.PHONY: compile
compile:
	cc -Wall -Wextra -Werror -pedantic -std=c11 -fPIC -shared -Wl,-soname,libekonomi.so.1 -o libekonomi.so.1.0 src/ekonomi.c 
	cc -Wall -Wextra -Werror -pedantic -std=c11 -c -o libekonomi.o src/ekonomi.c
	ar rcs libekonomi.a libekonomi.o
	chmod 644 libekonomi.a
	rm -f libekonomi.o
	ln -sf libekonomi.so.1.0 libekonomi.so
	install -m 644 src/ekonomi.c build/src
	install -m 644 src/ekonomi.h build/include
	mv libekonomi.so.1.0 libekonomi.so libekonomi.a build/lib

.PHONY: install
install:
	mkdir -p /usr/local/src /usr/local/lib /usr/local/include 
	cp -R build/include build/lib build/src /usr/local
	ldconfig /usr/local/lib

FOLDER_INCLUDE = /usr/local/include/
FOLDER_SRC = /usr/local/src/
FOLDER_LIB = /usr/local/lib/

POST_CLEAN = $(addprefix $(FOLDER_INCLUDE), ekonomi*) \
			 $(addprefix $(FOLDER_SRC), ekonomi*) \
			 $(addprefix $(FOLDER_LIB), libekonomi*) \

.PHONY: uninstall
uninstall:
	rm -f $(POST_CLEAN)

# rm -f /usr/local/include/ekonomi.h
# rm -f /usr/local/src/ekonomi.c
# rm -f /usr/local/lib/libekonomi.so /usr/local/lib/libekonomi.so.1 /usr/local/lib/libekonomi.so.1.0 /usr/local/lib/libekonomi.a

FOLDER_BUILD = build/

.PHONY: clean
clean: uninstall
	rm -rf $(FOLDER_BUILD)
	rm -f test

.PHONY: version
version:
	@echo 1.0

.PHONY: run
run:
	@gcc -o test tests/test.c -lekonomi -lm
	@./test
