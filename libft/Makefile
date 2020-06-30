# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msabre <msabre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 18:00:46 by msabre            #+#    #+#              #
#    Updated: 2020/02/29 16:04:14 by msabre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

PRINTF_C = ft_printf.c variants.c scp_flags.c parse_format.c output.c output_define.c output_fill.c ft_flag_find.c f_str_fr_int_mass.c f_regular_value.c f_long_value.c f_long_summ.c f_long_multi.c f_long_ariphmetic.c \
f_flag.c dioux_transitions.c dioux_functions.c dioux_flags.c \

GNL_C = get_next_line.c ft_lstadd.c \

HEAD = ./headers

LIBFT_C = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c mod_compair.c mod_minus.c mod_plus.c to_power.c size_int_mass.c integer_size.c ft_strndup.c ft_is_num.c free_doub_lvl_mass.c create_int_mass.c quick_sort.c ft_swap.c ft_chrfill.c cn_power.c ft_digitmass_cpy.c \
word_len.c count_words.c count_row.c zero_doub_lvl_mass.c cpy_double_lvl_mass.c str_qsort.c ft_memswap.c is_num.c is_numvalue.c skip_word.c \

DIR_O = temporary

CFILES = $(LIBFT_C) $(PRINTF_C) $(GNL_C)

PATH_C = $(addprefix ./src/libft/,$(LIBFT_C)) $(addprefix ./src/ft_printf/,$(PRINTF_C)) $(addprefix ./src/get_next_line/,$(GNL_C))

OFILES = $(CFILES:.c=.o)

PATH_O = $(addprefix $(DIR_O)/,$(OFILES))

all: $(NAME)

$(NAME): $(PATH_O)
	@ar rc $(NAME) $(PATH_O)
	@ranlib $(NAME)

$(DIR_O)/%.o: ./src/libft/%.c
	@mkdir -p $(DIR_O)
	@echo "COMPILING $< = $@"
	$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@;

$(DIR_O)/%.o: ./src/ft_printf/%.c
	@mkdir -p $(DIR_O)
	@echo "COMPILING $< = $@"
	$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@;

$(DIR_O)/%.o: ./src/get_next_line/%.c
	@mkdir -p $(DIR_O)
	@echo "COMPILING $< = $@"
	@$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@;

clean:
	@rm -f temporary/*.o
	@rm -rf temporary

fclean: clean
	@rm -f $(NAME)

re: fclean all
