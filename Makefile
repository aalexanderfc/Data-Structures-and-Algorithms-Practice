PROG = programmet
TEST = check
SRC = start.cpp calculatePrice.c
CC = gcc  # Use gcc for C files
CXX = clang++
CFLAGS = -Wall -Werror
CXXFLAGS = -std=c++14

DEBUG = 1
OUTPUTDIR = bin
GTEST = /usr/local/include/gtest
LIBGTEST = /usr/local/lib/libgtest_main.a /usr/local/lib/libgtest.a

ifeq ($(DEBUG), 1)
    CFLAGS += -g
    CXXFLAGS += -g
    OUTPUTDIR := $(OUTPUTDIR)/debug
    PROG := programmet-debug
else
    CFLAGS += -g0 -O3
    CXXFLAGS += -O3
    OUTPUTDIR := $(OUTPUTDIR)/release
endif

OBJS = $(addprefix $(OUTPUTDIR)/,$(SRC:.c=.o))
DEPS =  # Add your dependencies if needed

$(PROG): $(OUTPUTDIR) $(OBJS)
    $(CXX) $(CXXFLAGS) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: %.c $(DEPS)
    $(CC) $(CFLAGS) -o $@ -c $<

clean:
    $(RM) -r "$(OUTPUTDIR)"
    $(RM) $(PROG) $(TEST)

$(OUTPUTDIR):
    @mkdir -p "$(OUTPUTDIR)"

$(TEST): calculatePrice.o priceCalTest.cpp
    $(CXX) $(CXXFLAGS) $(CFLAGS) -o $(TEST) $^ -I$(GTEST) $(LIBGTEST)

test: $(TEST)
    ./$(TEST)

.PHONY: clean test
