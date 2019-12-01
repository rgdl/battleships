# Note: $@ is the target of the rule, $^ is the dependencies of the rule

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
APP = "Battleships"
LDFLAGS = -lncurses


$(APP): $(OBJ)
	g++ -o $@ $^ $(LDFLAGS)

clean:
	rm *.o
	rm $(APP)
