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

# Quest 3 — обычная сборка
all: $(BUILD_DIR)/Quest_3

$(BUILD_DIR)/Quest_3: $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lm

# Quest 4 — сборка с макросами
build_with_macro: $(MAIN) $(STAT) $(PROCESS) $(DECISION)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -DUSE_MACRO_IO $^ -o $(BUILD_DIR)/Quest_4 -lm

# Quest 5 — сборка статической библиотеки
$(BUILD_DIR)/data_stat.a: $(SRC_DIR)data_libs/data_stat.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)/data_stat.o
	ar rcs $(BUILD_DIR)/data_stat.a $(BUILD_DIR)/data_stat.o

build_with_static: $(MAIN) $(IO) $(PROCESS) $(DECISION) $(BUILD_DIR)/data_stat.a
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(MAIN) $(IO) $(PROCESS) $(DECISION) $(BUILD_DIR)/data_stat.a -o $(BUILD_DIR)/Quest_5 -lm

# Quest 6 — сборка динамической библиотеки
$(BUILD_DIR)/data_process.so: $(SRC_DIR)data_libs/data_process.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -fPIC -shared $< -o $@

build_with_dynamic: $(MAIN) $(IO) $(STAT) $(DECISION) $(BUILD_DIR)/data_process.so
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -DUSE_DYNAMIC $(MAIN) $(IO) $(STAT) $(DECISION) -o $(BUILD_DIR)/Quest_6 -ldl -lm

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all
