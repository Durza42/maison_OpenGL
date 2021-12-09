#include "SceneOpenGL.h"


#ifdef __WIN32__
int WinMain(int argc, char **argv) {
#else
int main(int argc, char **argv) {
#endif


      // Création de la sène
   SceneOpenGL scene("maison OpenGL", 800, 600);


      // Initialisation de la scène
   if(scene.initialiserFenetre() == false)
      return -1;

   if(scene.initGL() == false)
      return -1;


      // Boucle Principale
   scene.bouclePrincipale();


      // Fin du programme
   return 0;
}


