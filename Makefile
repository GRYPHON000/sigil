CFLAGS = -Wall -Wextra -g

# 2. AUTOMATICALLY finds all .c files in core/ and tests/
CORE_SRCS = $(wildcard core/*.c)
TEST_SRCS = $(wildcard tests/*.c)

TEST_BINS = $(TEST_SRCS:.c=)

all: $(TEST_BINS)
	@echo "All files compiled. Running tests..."
	@for test in $(TEST_BINS); do ./$$test; done

tests/%: tests/%.c $(CORE_SRCS)
	gcc $(CFLAGS) $^ -o $@

clean:
	rm -f $(TEST_BINS)
