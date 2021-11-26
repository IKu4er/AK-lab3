CXX = g++

RM = del /Q /F

CXXFLAGS = -Wall -Wextra  -c 

run: main.o
	$(CXX) $? -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

clean:
	$(RM) *.o run.exe