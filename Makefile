# Colours (only used with printf, safe in dash)
RESET  = \033[0m
GREEN  = \033[32m
BLUE   = \033[34m
YELLOW = \033[33m
RED    = \033[31m

# Executable
NAME   = minirt

# Compiler / flags
CC        = cc
CFLAGS    = -Wall -Wextra -Werror -lXext -lX11 -lm -g -I./include -I./libft
LIBFT     = -L./libft -lft

# Directories
SRCDIR = ./src
OBJDIR = obj

# Find all .c files recursively in src directory
SRCS = $(shell find $(SRCDIR) -name "*.c" -type f)

# Generate object files automatically with same directory structure
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Rules
all: $(NAME)

# Create object directory and subdirectories dynamically
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(sort $(dir $(OBJS)))

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@printf "$(BLUE)Compiling $<...$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@printf "$(BLUE)Building libft...$(RESET)\n"
	@$(MAKE) -C libft --no-print-directory > /dev/null 2>&1
	@printf "$(GREEN)✓ libft built.$(RESET)\n"

$(NAME): libft $(OBJS)
	@printf "$(BLUE)Linking $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)✓ $(NAME) created.$(RESET)\n"

clean:
	@printf "$(RED)Cleaning object files...$(RESET)\n"
	@$(RM) -rf $(OBJDIR)
	@$(MAKE) -C libft clean --no-print-directory > /dev/null 2>&1
	@printf "$(GREEN)✓ Objects removed.$(RESET)\n"

fclean: clean
	@printf "$(RED)Removing $(NAME)...$(RESET)\n"
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean --no-print-directory > /dev/null 2>&1
	@printf "$(GREEN)✓ Full clean done.$(RESET)\n"

re: fclean all


# Help rule
help:
	@printf "$(BLUE)Available targets:$(RESET)\n"
	@printf "  $(GREEN)make$(RESET)        - Build the minirt program\n"
	@printf "  $(GREEN)make clean$(RESET)  - Remove object files\n"
	@printf "  $(GREEN)make fclean$(RESET) - Remove all generated files\n"
	@printf "  $(GREEN)make re$(RESET)     - Rebuild everything (clean build)\n"
	@printf "  $(GREEN)make libft$(RESET)  - Build libft\n"
	@printf "  $(GREEN)make help$(RESET)   - Show this help message\n"

.PHONY: all clean fclean re help libft
