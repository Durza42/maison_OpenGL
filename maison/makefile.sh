g++ -c main.cpp -o main.o `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW
g++ -c SceneOpenGL.cpp -o SceneOpenGL.o `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW
g++ -c Shader.cpp -o Shader.o `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW
g++ -c caisse.cpp -o caisse.o `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW
g++ -c Texture.cpp -o Texture.o `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW -lSDL2_image
g++ -c Input.cpp -o Input.o `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW
g++ -c camera.cpp -o camera.o `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW
g++ -c sol.cpp -o sol.o `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW
g++ -c cristal.cpp -o cristal.o `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW
g++ -c maison.cpp -o maison.o `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW
g++ -c utilities.cpp -o utilities.o `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW

g++ main.o SceneOpenGL.o Shader.o cube.o caisse.o Texture.o Input.o camera.o sol.o cristal.o maison.o utilities.o -o TP.out `sdl2-config --libs` -lglut -lGLU -lGL -lGLEW -lSDL2_ttf -lSDL2_mixer -lSDL2_image

./TP.out
