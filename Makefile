###########################################################################
#                                                                  MAKEFILE
###########################################################################

# Construye el makefile utilizando cmake
make:
	@mkdir -p build
	@cd build && cmake .. 


# Construye los ejecutables 
.PHONY: build
build: make
	@cd build && make


# Ejecuta los tests
check: build
	./build/test/test


# Limpia el espacio de trabajo
.PHONY: clean
clean:
	@rm -rf build

# Genera documentación.
.PHONY: docs
docs: make
	@cd build && make docs
	@cd doc && make html
