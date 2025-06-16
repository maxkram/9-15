CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = ../../
BUILD_DIR = ../../build

IO = $(SRC_DIR)data_libs/data_io.c
STAT = $(SRC_DIR)data_libs/data_stat.c
PROCESS = $(SRC_DIR)data_libs/data_process.c
DECISION = $(SRC_DIR)data_libs/decision.c
MAIN = main_executable_module.c

OBJS = $(MAIN) $(IO) $(STAT) $(PROCESS) $(DECISION)

all: $(BUILD_DIR)/Quest_3

$(BUILD_DIR)/Quest_3: $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lm

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all
