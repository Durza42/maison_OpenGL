gcc -c glad.c -o glad.o
g++ -c main.cpp -o main.o
g++ -c SceneOpenGL.cpp -o SceneOpenGL.o
g++ -c Shader.cpp -o Shader.o
g++ -c caisse.cpp -o caisse.o
g++ -c Texture.cpp -o Texture.o
g++ -c Input.cpp -o Input.o
g++ -c camera.cpp -o camera.o
g++ -c sol.cpp -o sol.o
g++ -c cristal.cpp -o cristal.o
g++ -c maison.cpp -o maison.o
g++ -c utilities.cpp -o utilities.o

g++ main.o SceneOpenGL.o Shader.o cube.o caisse.o Texture.o Input.o camera.o sol.o cristal.o maison.o utilities.o glad.o -o TP.out `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW -lSDL2_ttf -lSDL2_mixer -lSDL2_image

./TP.out
