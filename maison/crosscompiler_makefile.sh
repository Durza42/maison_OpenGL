# replace the -I... option by your include directory
# and the -L option by your libs directory

## For Windows users : same; but replace also the commands
## "x86_64-w64-mingw32-gcc" by "gcc"
## and "x86_64-w64-mingw32-g++" by "g++"

x86_64-w64-mingw32-gcc -c glad.c -o glad.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c main.cpp -o main.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c SceneOpenGL.cpp -o SceneOpenGL.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c Shader.cpp -o Shader.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c caisse.cpp -o caisse.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c Texture.cpp -o Texture.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c Input.cpp -o Input.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c camera.cpp -o camera.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c cube.cpp -o cube.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c sol.cpp -o sol.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c cristal.cpp -o cristal.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c maison.cpp -o maison.o -I/home/durza42/programing/includes/
x86_64-w64-mingw32-g++ -c utilities.cpp -o utilities.o -I/home/durza42/programing/includes/

x86_64-w64-mingw32-g++ glad.o main.o SceneOpenGL.o Shader.o cube.o caisse.o Texture.o Input.o camera.o sol.o cristal.o maison.o utilities.o -o TP.exe -I/home/durza42/programing/includes -L/home/durza42/programing/libs `sdl2-config --libs` -lSDL2 -lSDL2_image

wine TP.exe
