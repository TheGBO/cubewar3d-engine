all:
	g++ src/*.cpp -o bin/main.exe -lfreeglut -lopengl32 -lglu32 -static-libstdc++ -static-libgcc