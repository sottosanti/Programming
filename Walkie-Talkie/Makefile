shell_source_files := $(shell find src/impl/shell -name "*.c")
shell_object_files := $(patsubst src/impl/shell/%.c, build/walkie-talkie/%.o, $(shell_source_files))

Api_source_fiels := $(shell find src/impl/api -name "*.c")
Api_object_files := $(patsubst src/impl/api/%.c, build/walkie-talkie/%.o, $(Api_source_fiels))

$(shell_object_files): build/walkie-talkie/%.o : src/impl/shell/%.c
	mkdir -p $(dir $@) && \
	gcc -c -I src/intf $(patsubst build/walkie-talkie/%.o, src/impl/shell/%.c, $@) -o $@

$(Api_object_files): build/walkie-talkie/%.o : src/impl/api/%.c
	mkdir -p $(dir $@) && \
	gcc -c -I src/intf $(patsubst build/walkie-talkie/%.o, src/impl/api/%.c, $@) -o $@

.PHONY: walkie-talkie
walkie-talkie: $(shell_object_files) $(Api_object_files) 
	mkdir -p dist/walkie-talkie && .
	gcc -I src/intf -Wall $(shell_object_files) $(Api_object_files) -o dist/walkie-talkie/walkie-talkie

.PHONY: clean
clean:
	rm dist/walkie-talkie/walkie-talkie && \
	rm build/walkie-talkie/*.o && \
	rmdir dist/walkie-talkie && \
	rmdir build/walkie-talkie && \
	rmdir build && \
	rmdir dist