# name of the program (Minix service)
PROG=proj

.PATH: ${.CURDIR}/project/src
.PATH: ${.CURDIR}/libs/graph/src
.PATH: ${.CURDIR}/libs/kbc/src
.PATH: ${.CURDIR}/libs/timer/src
.PATH: ${.CURDIR}/libs/uart/src
.PATH: ${.CURDIR}/libs/xpms/src
.PATH: ${.CURDIR}/libs/utils/src
.PATH: ${.CURDIR}/libs


# source code files to be compiled
SRCS = proj.c videoCard.c mouse.c interrupts.c timer.c utils.c keyboard.c xpms.c uart1.c loopFuncs.c

# additional compilation flags
IPATHS=-I./project/include -I./libs -I./libs/graph/include -I./libs/timer/include -I./libs/uart/include -I./libs/xpms/include -I./libs/utils/include 
# "-Wall -Wextra -Werror -I . -std=c11 -Wno-unused-parameter" are already set
CFLAGS += -pedantic ${IPATHS}
CFLAGS += -pedantic -D__LCOM_OPTIMIZED__


# list of library dependencies (for Lab 2, only LCF library)
DPADD += ${LIBLCF}
LDADD += -llcf

# include LCOM's makefile that does all the "heavy lifting"
.include <minix.lcom.mk>
