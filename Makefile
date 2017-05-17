.PHONY: all

all: compile

compile:
	@if [ ! -d build ]; then mkdir -p build ; fi;\
	cd examples; ./make_all.sh

clean:
	@if [ ! -d build ]; then mkdir -p build ; fi;\
	cd examples; ./clean_all.sh

test: compile
	@cd tests; ./test_all.sh
