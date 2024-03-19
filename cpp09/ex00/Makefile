# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daumis <daumis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 14:26:36 by daumis            #+#    #+#              #
#    Updated: 2023/09/27 18:33:03 by daumis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN	=	src/main.cpp\
				src/BitcoinExchange.cpp
				  
SRCS		=	${SRC_MAIN}

OBJ_DIR		=	objs
OBJS 		=	$(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

CXX			=	c++
RM			=	rm -f
CXXFLAGS	=	-Wall -Wextra -Werror -MMD -MP -std=c++98

NAME		=	btc

all: $(OBJ_DIR) $(OBJS) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	@mkdir -p $(@D)
	@printf '\033[A\033[19C'"⌛ [\e[1;96mCompiling\033[0m]\033[35m $<\033[0m \n"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(wildcard *.d)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)
	@printf '\033[A\033[20C'"\033[32;1m  ✅ Project has compiled successfully!          \033[0m"
	@printf "\n\n    [🏳️ FLAGS: \033[0;35m$(CXXFLAGS)\033[0m]"
	@echo "\033[32;1m\n 💾 Executable \e[7m./$(NAME)\e[27m has been created in: \n    └─ 📂 \033[4;36m ~ $(PWD)\033[0m"

clean:
	$(RM) -r $(OBJ_DIR)

fclean:
	@echo "\033[1;93m\n                        [Cleaning directories with \033[0;96mfclean\033[1;93m]\n\033[0m"
	@make clean
	$(RM) $(NAME)

re:
	@make fclean
	@echo "\033[1;93m\n                             [Calling \033[0;96mmake all\033[1;93m rule]\n\n\033[0m"
	@make -s all

.PHONY: all clean fclean re
