all:
	g++ src/*.cpp -o bin/main.exe -lfreeglut -lopengl32 -lglu32 -llua54 -static-libstdc++ -static-libgcc -m32