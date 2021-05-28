CC = gcc
CFLAGS = -Wall -Werror
CPPFLAGS = -I src -MMD
DEBUG = -g3 -O0

BIN = bin
OBJ = obj
SRC = src

APP_NAME = geometry
LIB_NAME = libgeometry
TEST_NAME = geometry-test

PATH_TO_APP = $(BIN)/$(APP_NAME)
PATH_TO_LIB = $(OBJ)/$(SRC)/$(LIB_NAME)/$(LIB_NAME).a
PATH_TO_TEST = $(BIN)/$(TEST_NAME)

APP_SOURCES = $(shell find $(SRC)/$(APP_NAME) -name "*.c")
APP_OBJECTS = $(APP_SOURCES:$(SRC)/%.c=$(OBJ)/$(SRC)/%.o)

LIB_SOURCES = $(shell find $(SRC)/$(LIB_NAME) -name "*.c")
LIB_OBJECTS = $(LIB_SOURCES:$(SRC)/%.c=$(OBJ)/$(SRC)/%.o)

TEST_SOURCES = $(shell find $(TEST) -name "*.c")
TEST_OBJECTS = $(TEST_SOURCES:$(TEST)/%.c=$(OBJ)/$(TEST)/%.o)

DEP =  $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

.PHONY: all
all: $(PATH_TO_APP)

-include $(DEP)

$(PATH_TO_APP): $(APP_OBJECTS) $(PATH_TO_LIB)
	$(CC) $(CFLAGS) $(DEBUG) $(CPPFLAGS) -o $@ $^ -lm

$(PATH_TO_LIB): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ)/%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) $(CPPFLAGS) -c -o $@ $<

.PHONY: test
test: $(PATH_TO_TEST)

$(PATH_TO_TEST): $(TEST_OBJECTS) $(PATH_TO_LIB)
	$(CC) $(CFLAGS) $(CPPFLAGS_TEST) -o $@ $^

$(OBJ)/$(TEST)/%.o: $(TEST)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS_TEST) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(PATH_TO_APP) $(PATH_TO_LIB)
	rm -rf $(DEP) $(APP_OBJECTS) $(LIB_OBJECTS)