# Go to dir with project in terminal and run:
#	g++ -MM *.cpp >> Makefile

# Compile with debug option and all warnings on. ------------
CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -O1

# Object modules comprising this application ----------------
OBJ = main.o Board.o BoardDiag.o BoardSixy.o \
		BoardTrad.o Canvas.o Cluster.o Game.o \
		GridChar.o MixedChar.o Square.o State.o \
		tools.o Viewer.o

# Build targets
TARGETS = sudo_helper

# .PHONY: means that the targets that follow should be built even 
# though the are not real files.
.PHONY: all clean
all: $(TARGETS)

sudo_helper: $(OBJ)
	$(CXX)  -o $@ $(CXXFLAGS) $(OBJ)

# Delete .o and exe files and force recompilation. ----------
clean:
	rm -f $(OBJ) $(TARGETS)

# Dependencies ----------------------------------------------
# The  lines below were generated by the c++ -MM command up at the top.
Board.o: Board.cpp Board.hpp Square.hpp State.hpp tools.hpp BadLogic.hpp \
 BadGameFile.hpp CanView.hpp Frame.hpp Stack.hpp Cluster.hpp
BoardDiag.o: BoardDiag.cpp BoardDiag.hpp BoardTrad.hpp Board.hpp \
 Square.hpp State.hpp tools.hpp BadLogic.hpp BadGameFile.hpp CanView.hpp \
 Frame.hpp Stack.hpp Cluster.hpp
BoardSixy.o: BoardSixy.cpp BoardSixy.hpp Board.hpp Square.hpp State.hpp \
 tools.hpp BadLogic.hpp BadGameFile.hpp CanView.hpp Frame.hpp Stack.hpp \
 Cluster.hpp
BoardTrad.o: BoardTrad.cpp BoardTrad.hpp Board.hpp Square.hpp State.hpp \
 tools.hpp BadLogic.hpp BadGameFile.hpp CanView.hpp Frame.hpp Stack.hpp \
 Cluster.hpp
Canvas.o: Canvas.cpp Canvas.hpp MixedChar.hpp tools.hpp GridChar.hpp
Cluster.o: Cluster.cpp Cluster.hpp Square.hpp State.hpp tools.hpp \
 BadLogic.hpp BadGameFile.hpp
Game.o: Game.cpp Game.hpp Board.hpp Square.hpp State.hpp tools.hpp \
 BadLogic.hpp BadGameFile.hpp CanView.hpp Frame.hpp Stack.hpp \
 BoardDiag.hpp BoardTrad.hpp BoardSixy.hpp Viewer.hpp
GridChar.o: GridChar.cpp tools.hpp GridChar.hpp
main.o: main.cpp Game.hpp Board.hpp Square.hpp State.hpp tools.hpp \
 BadLogic.hpp BadGameFile.hpp CanView.hpp Frame.hpp Stack.hpp \
 BoardDiag.hpp BoardTrad.hpp BoardSixy.hpp Viewer.hpp
MixedChar.o: MixedChar.cpp tools.hpp MixedChar.hpp
Square.o: Square.cpp Square.hpp State.hpp tools.hpp BadLogic.hpp \
 BadGameFile.hpp Cluster.hpp
State.o: State.cpp State.hpp tools.hpp BadLogic.hpp BadGameFile.hpp \
 Frame.hpp
tools.o: tools.cpp tools.hpp
Viewer.o: Viewer.cpp Viewer.hpp CanView.hpp Canvas.hpp MixedChar.hpp \
 tools.hpp GridChar.hpp
