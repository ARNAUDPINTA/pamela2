##
## Makefile for PAMela projet
##

NAME	=	/lib/i386-linux-gnu/security/pam_pamela.so

SRCS	=	pam_pamela.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

RM	=	rm -rf

ACCOUNT	=	"account required pam_pamela.so"

AUTH	=	"auth required pam_pamela.so"

PASSWORD=	"password required pam_pamela.so"

SESSION	=	"session required pam_pamela.so"

GREPACCOUNT=	$(shell grep -x $(ACCOUNT) /etc/pam.d/common-account)

GREPAUTH=	$(shell grep -x $(AUTH) /etc/pam.d/common-auth)

GREPPASSWORD=	$(shell grep -x $(PASSWORD) /etc/pam.d/common-password)

GREPSESSION=	$(shell grep -x $(SESSION) /etc/pam.d/common-session)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -fPIC -DPIC -shared -rdynamic -o $(NAME) $(OBJS)

install	:
		@echo "Installing the Module..."
ifeq ($(GREPACCOUNT),)
	@echo $(ACCOUNT) >> /etc/pam.d/common-account
	@echo "\033[0;32mcommon-account parametred.\033[0m"
else
	@echo "\033[1;33mcommon-account already parametred.\033[0m"
endif
ifeq ($(GREPAUTH),)
	@echo $(AUTH) >> /etc/pam.d/common-auth
	@echo "\033[0;32mcommon-auth parametred.\033[0m"
else
	@echo "\033[1;33mcommon-auth already parametred.\033[0m"
endif
ifeq ($(GREPPASSWORD),)
	@echo $(PASSWORD) >> /etc/pam.d/common-password
	@echo "\033[0;32mcommon-password parametred.\033[0m"
else
	@echo "\033[1;33mcommon-password already parametred.\033[0m"
endif
ifeq ($(GREPSESSION),)
	@echo $(SESSION) >> /etc/pam.d/common-session
	@echo "\033[0;32mcommon-session parametred.\033[0m"
else
	@echo "\033[1;33mcommon-session already parametred.\033[0m"
endif

uninstall:
		@echo "Uninstalling the module..."
		@sed -i '/account required pam_pamela.so/d' /etc/pam.d/common-account
		@sed -i '/auth required pam_pamela.so/d' /etc/pam.d/common-auth
		@sed -i '/password required pam_pamela.so/d' /etc/pam.d/common-password
		@sed -i '/session required pam_pamela.so/d' /etc/pam.d/common-session
		@echo "Done."

check	:
ifeq ($(GREPACCOUNT),)
	@echo "The module is not installed. Use make install."
else
ifeq ($(GREPAUTH),)
	@echo "The module is not installed. Use make install."
else
ifeq ($(GREPAUTH),)
	@echo "The module is not installed. Use make install."
else
ifeq ($(GREPAUTH),)
	@echo "The module is not installed. Use make install."
else
	@echo "The module is correctly installed."
endif
endif
endif
endif

test	:
		@echo "test"

clean	:
		$(RM) $(OBJS) $(NAME)

re	:	clean all
