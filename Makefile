main: main.cpp ImgObject.cpp Game.cpp
	g++ -std=c++11 main.cpp ImgObject.cpp Game.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f main