# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:47:44 by evogel            #+#    #+#              #
#    Updated: 2021/01/07 11:38:44 by dapinto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-Printing-#
#No Color
NO_COLOR    = \033[m
#Black
BLACK       = \033[0;30m
#Red
ERROR_COLOR = \033[0;31m
#Green
OK_COLOR    = \033[0;32m
#Yellow
WARN_COLOR  = \033[0;33m
#Blue
BLUE        = \033[0;34m
#Purple
COM_COLOR   = \033[0;35m
#Cyan
OBJ_COLOR   = \033[0;36m
#White
WHITE       = \033[0;37m

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	$(RM) $@.log; \
	exit $$RESULT
endef

OK_STRING    = "[DONE]"
ERROR_STRING = "[OHSHIT]"
WARN_STRING  = "[HOLDUP]"
COM_STRING   = "[PROJECT]"

#-Make-#
FRAC_NAME = fractol
FRAC_NAMEDEB = fractoldeb
FRAC_NAME_LIN = Fractol_linux
FRAC_NAMEDEB_LIN = Fractol_linuxdeb
CC = clang
GCC = gcc
WFG = -Wall -Wextra -Werror
COMP = $(CC) -fPIE -c
COMPL = $(GCC) -c
DEBUG = $(CC) -g -fsanitize=address -fno-omit-frame-pointer
DEBUGLIN = $(GCC) -g -fsanitize=address -fno-omit-frame-pointer
ANALYZE = $(DEBUG) -analyze
MINILIBLINUX = -lmlx -lXext -lX11 -L $(MLX_DIR)
MINILIBMAC = -lmlx -framework OpenGL -framework AppKit -L $(MLX_DIR)
MKDIR = mkdir -p
DSYM = *.dSYM
MKE = make -C
RMRF = rm -rf

#-Libraries, includes, and paths-#
#-Directories-#
MLX_DIR = ./minilibx/
DEBUG_DIR = ./debug/
HEADER_DIR = ./includes/
LIB_INCS += -Ilibft/includes
vpath %.c $(FRAC_SRCS_DIR)
vpath %.o $(OBJS_DIR)
vpath %deb.o $(DEBOBJS_DIR)
vpath %.h ./includes/
# ASM
FRAC_HDS += fractol.h
FRAC_HDS += mlx.h
FRAC_HEADERS = $(addprefix $(HEADER_DIR), $(FRAC_HDS))
FRAC_INCS += -I$(HEADER_DIR)
FRAC_INCS += $(LIB_INCS)
# LIBFT
LIB_PATH = libft/
MAKE_PATH = libft/
LIB = $(LIB_PATH)libft.a
LIBDEB= $(LIB_PATH)libftdeb.a

#-Sources and paths-#
# FRAC
FRAC_SRCS += fractol.c
FRAC_SRCS += fractal_set_1.c
FRAC_SRCS += fractal_set_2.c
FRAC_SRCS += fractal_types.c
FRAC_SRCS += init.c
FRAC_SRCS += colour_palettes.c
FRAC_SRCS += variable_init_1.c
FRAC_SRCS += variable_init_2.c
FRAC_SRCS += argument_manager.c
FRAC_SRCS += event_manager.c
FRAC_SRCS += event_1.c
FRAC_SRCS += event_2.c
FRAC_SRCS += miscellaneous_1.c
FRAC_SRCS += miscellaneous_2.c
FRAC_SRCS_DIR = ./srcs/fractol/
FRAC_PATHS = $(addprefix $(FRAC_SRCS_DIR), $(FRAC_SRCS))
#-Objects-#
OBJS_DIR = ./objects/
DEBOBJS_DIR = ./debug/deb_objects/
# FRAC
FRAC_OBJS_DIR = ./objects/fractol/
FRAC_OBJS = $(patsubst %.c, %.o, $(FRAC_SRCS))
FRAC_OBJS_PATH = $(addprefix $(FRAC_OBJS_DIR), $(FRAC_OBJS))
FRAC_OBJS_DIR_LIN = ./objects/fractol/
FRAC_DEBOBJS_DIR_LIN = $(DEBOBJS_DIR)
# FRAC_DEBUG
FRAC_DEBOBJS_DIR = $(DEBOBJS_DIR)
FRAC_DEBOBJS = $(patsubst %.c, %deb.o, $(FRAC_SRCS))
FRAC_DEBOBJS_PATH = $(addprefix $(FRAC_DEBOBJS_DIR), $(FRAC_DEBOBJS))

#-Rules-#
all: $(FRAC_NAME)

mac: $(FRAC_NAME)

linux:  $(FRAC_NAME_LIN)

debug: $(FRAC_NAMEDEB)

debl: $(FRAC_NAMEDEB_LIN)

analyze:
	@mkdir -p $(DEBUG_DIR)
	@printf "\e[32m----------\nLaunching analyzer script.\e[39m\n"
	@sh build/analyze.sh

$(LIB): FORCE
	@$(MKE) $(MAKE_PATH)

$(LIBDEB): FORCE
	@$(MKE) $(MAKE_PATH) debug

#FRACTOL LINUX
$(FRAC_NAME_LIN): $(LIB) $(FRAC_OBJS_DIR_LIN) $(FRAC_OBJS_PATH)
	@$(GCC) $(WFG) $(FRAC_INCS) $(FRAC_OBJS_PATH) $(LIB) $(MINILIBLINUX) -o $(FRAC_NAME_LIN)

$(FRAC_NAMEDEB_LIN): $(LIBDEB) $(FRAC_DEBOBJS_DIR_LIN) $(FRAC_DEBOBJS_PATH)
	@$(DEBUGLIN) $(WFG) $(FRAC_INCS) $(FRAC_DEBOBJS_PATH) $(LIBDEB) $(MINILIBLINUX) -o $(FRAC_NAMEDEB_LIN)

$(FRAC_OBJS_DIR_LIN)%.o : $(FRAC_SRCS_DIR)%.c $(FRAC_HDS)
	@$(call run_and_test, $(COMPL) $(WFG) $(FRAC_INCS) $< -o $@)

$(FRAC_DEBOBJS_DIR_LIN)%deb.o : $(FRAC_SRCS_DIR)%.c $(FRAC_HDS)
	@$(call run_and_test, $(DEBUGLIN) -c $(WFG) $(FRAC_INCS) $< -o $@)

#FRACTOL MAC
$(FRAC_NAME): $(LIB) $(FRAC_OBJS_DIR) $(FRAC_OBJS_PATH)
	@$(CC) -Ofast $(WFG) $(FRAC_INCS) $(FRAC_OBJS_PATH) $(LIB) $(MINILIBMAC) -o $(FRAC_NAME)

$(FRAC_NAMEDEB): $(LIBDEB) $(FRAC_DEBOBJS_DIR) $(FRAC_DEBOBJS_PATH)
	@$(DEBUG) $(WFG) $(FRAC_INCS) $(FRAC_DEBOBJS_PATH) $(LIBDEB) $(MINILIBMAC) -o $(FRAC_NAMEDEB)

$(FRAC_OBJS_DIR)%.o : $(FRAC_SRCS_DIR)%.c $(FRAC_HDS)
	@$(call run_and_test, $(COMP) $(WFG) $(FRAC_INCS) $< -o $@)

$(FRAC_DEBOBJS_DIR)%deb.o : $(FRAC_SRCS_DIR)%.c $(FRAC_HDS)
	@$(call run_and_test, $(DEBUG) -c $(WFG) $(FRAC_INCS) $< -o $@)

#mkdir
$(DEBOBJS_DIR):
	@mkdir -p $(DEBOBJS_DIR)

$(DEBOBJS_DIR_LIN):
	$(DEBOBJS_DIR)

$(DEBUG_DIR):
	@mkdir -p $(DEBUG_DIR)

$(FRAC_OBJS_DIR):
	@mkdir -p $(FRAC_OBJS_DIR)

FORCE:

clean:
	@$(MKE) $(MAKE_PATH) clean
	@$(RMRF) $(OBJS_DIR)
	@$(RMRF) $(DEBOBJS_DIR)
	@$(RMRF) $(DEBUG_DIR)static_analyzer
	@$(RMRF) $(DSYM)

fclean: clean
	@$(MKE) $(MAKE_PATH) fclean
	@$(RMRF) $(FRAC_NAME_LIN)
	@$(RMRF) $(FRAC_NAMEDEB_LIN)
	@$(RMRF) $(FRAC_NAME)
	@$(RMRF) $(FRAC_NAMEDEB)
	@$(RMRF) $(OBJS_DIR)
	@$(RMRF) $(DEBUG_DIR)

re: fclean all

.PHONY: clean fclean re debug all FORCE
