#ifndef DEF_SCENEOPENGL
 #define DEF_SCENEOPENGL

 #include <glad/glad.h>

 #include <glm/glm.hpp>
 #include <glm/gtx/transform.hpp>
 #include <glm/gtc/type_ptr.hpp>

 #include <SDL2/SDL.h>
 #include <iostream>
 #include <string>

 #include "Input.h"
 #include "camera.h"
 #include "sol.h"

class SceneOpenGL {

  public:

   SceneOpenGL(std::string titreFenetre, int largeurFenetre, int hauteurFenetre);
   ~SceneOpenGL();

   bool initialiserFenetre();
   bool initGL();
   void bouclePrincipale();
   bool do_events (Camera* camera, Sol herbe, Sol espace);


  private:

   std::string m_titreFenetre;
   int m_largeurFenetre;
   int m_hauteurFenetre;

   SDL_Window* m_fenetre;
   SDL_GLContext m_contexteOpenGL;
   Input m_input;
};

#endif
