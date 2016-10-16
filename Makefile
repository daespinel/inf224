##########################################
#
#  Exemple de Makefile
#  Eric Lecolinet - Reda Dehak - Telecom ParisTech 2015
#  INF224 - TP C++ - http://www.telecom-paristech.fr/~elc/inf224
#
##########################################

#
# Nom du programme
#
CLIENT=client
PROG=multimedia
CLISERV=cliserv

#
# Fichiers sources (NE PAS METTRE les .h ni les .o seulement les .cpp)
#
PROG_SOURCES = Multimedia.cpp main.cpp Film.cpp GestionControl.cpp cppsocket.cpp tcpserver.cpp
CLIENT_SOURCES=client.cpp cppsocket.cpp
CLISERV_SOURCES=Multimedia.cpp main.cpp Film.cpp GestionControl.cpp client.cpp  tcpserver.cpp cppsocket.cpp Makefile

#
# Fichiers objets (ne pas modifier sauf si l'extension n'est pas .cpp)
#

CLIENT_OBJETS=${CLIENT_SOURCES:%.cpp=%.o}
PROG_OBJETS=${PROG_SOURCES:%.cpp=%.o}

#
# Compilateur C++
#
CXX = c++

#
# Options du compilateur C++
#   -g pour debugger, -O optimise, -Wall affiche les erreurs, -I pour les headers
#   -std=c++11 pour C++11
# Example: CXXFLAGS= -std=c++11 -Wall -O -I/usr/local/qt/include
#
CXXFLAGS = -std=c++11 -Wall -g

#
# Options de l'editeur de liens
#
LDFLAGS = 

#
# Librairies a utiliser
# Example: LDLIBS = -L/usr/local/qt/lib -lqt
#
LDLIBS = -lpthread


##########################################
#
# Regles de construction/destruction des .o et de l'executable
# depend-${PROG} sera un fichier contenant les dependances
#
all: ${CLIENT} ${PROG}

run-${PROG}: ${PROG}
	./${PROG}

run-${CLIENT}: ${CLIENT}
	./${CLIENT}

${CLIENT}: depend-${CLIENT} ${CLIENT_OBJETS}
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${CLIENT_OBJETS} ${LDLIBS}

${PROG}: depend-${PROG} ${PROG_OBJETS}
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${PROG_OBJETS} ${LDLIBS}

clean:
	-@$(RM) *.o depend-${CLIENT} depend-${PROG} core 1>/dev/null 2>&1

clean-all: clean
	-@$(RM) -${CLIENT} -${PROG} 1>/dev/null 2>&1
  
tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}

# Gestion des dependances : creation automatique des dependances en utilisant 
# l'option -MM de g++ (attention tous les compilateurs n'ont pas cette option)
#
depend-${PROG}:
	${CXX} ${CXXFLAGS} -MM ${PROG_SOURCES} > depend-${PROG}

depend-${CLIENT}:
	${CXX} ${CXXFLAGS} -MM ${CLIENT_SOURCES} > depend-${CLIENT}

###########################################
#
# Regles implicites
#

.SUFFIXES: .cpp .cxx .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c (CFLAGS) $(INCPATH) -o $@ $<


#############################################
#
# Inclusion du fichier des dependances
#
-include depend-${PROG}
-include depend-${CLIENT}
