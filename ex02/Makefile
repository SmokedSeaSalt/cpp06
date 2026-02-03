################################################################################
# Basics                                                                       #
################################################################################

NAME = classtype
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -MMD
CCDEBUG = -g

################################################################################
# Source files                                                                 #
################################################################################

BUILD_DIR = build

SRC = 	main.cpp \
		Base.cpp

OBJ = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC))
DEP = ${OBJ:.o=.d}

################################################################################
# Rules                                                                        #
################################################################################

all: $(NAME)
	@printf "$(COLOUR_GREEN)Compilation done👍\n$(COLOUR_END)"

$(NAME): $(OBJ) Makefile
	@printf "$(COLOUR_BLUE)Compiling executable: $(NAME)\n$(COLOUR_END)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $@

$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)
	@printf "$(COLOUR_BLUE)Compiling $@ \n$(COLOUR_END)"
	@$(CPP) $(CPPFLAGS) -c $< -o $@ -MF $(basename $@).d

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) --no-print-directory

$(BUILD_DIR):
	mkdir -p $@

-include $(DEP)

.PHONY:	clean fclean re all

################################################################################
# Terminal beautification                                                      #
################################################################################

# Colours
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

# Formatting
FORMAT_BOLD=\033[1mBold
FORMAT_NORMAL=\033[0mNormal
