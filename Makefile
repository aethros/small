# Directories
BUILD_DIR = ./.build
SRC_DIR   = ./src

# Commands
OBJCOPY   = objcopy
STRIP     = strip

# Flags
COPYFLAGS = --remove-section .comment --remove-section .note.GNU-stack
SYS_FLAGS = -fomit-frame-pointer -fno-asynchronous-unwind-tables -fno-unwind-tables -Daarch64=TRUE
CFLAGS    = -g -static -nostdlib -ffreestanding -Os -flto -ffunction-sections -fdata-sections
LDFLAGS   = -g -static -nostdlib -s -flto -Wl,--gc-sections
STRIPFLAGS= --strip-all --remove-section .eh_frame --remove-section .note.GNU-stack \
			--remove-section .comment

# Objects and Files
SRCS = $(filter-out syscall.c,$(notdir $(wildcard $(SRC_DIR)/*.c)))
OBJS = $(SRCS:.c=.o)

# Recipes
.PHONY: all clean $(BUILD_DIR)

all: $(BUILD_DIR) syscall.o $(OBJS:%=$(BUILD_DIR)/%)
	$(CC) $(LDFLAGS) $(BUILD_DIR)/syscall.o $(OBJS:%=$(BUILD_DIR)/%) -o $(BUILD_DIR)/small
	$(STRIP) $(STRIPFLAGS) $(BUILD_DIR)/small

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

syscall.o: $(SRC_DIR)/syscall.c $(SRC_DIR)/syscall.h | $(BUILD_DIR)
	$(CC) $(SYS_FLAGS) -c $< -o $(BUILD_DIR)/$@
	$(OBJCOPY) $(COPYFLAGS) $(BUILD_DIR)/$@

clean:
	$(RM) -rf $(BUILD_DIR)/*
