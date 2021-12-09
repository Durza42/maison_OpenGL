#include <glad/glad.h>
#include <array>
#include "SceneOpenGL.h"
#include "Shader.h"
#include "cube.h"
#include "Texture.h"
#include "Input.h"
#include "caisse.h"
#include "sol.h"
#include "cristal.h"
#include "maison.h"
#include "utilities.h"

using namespace glm;

// Constructeur de Destucteur

SceneOpenGL::SceneOpenGL(std::string titreFenetre, int largeurFenetre, int hauteurFenetre) : m_titreFenetre(titreFenetre), m_largeurFenetre(largeurFenetre),
                                                                                             m_hauteurFenetre(hauteurFenetre), m_fenetre(0), m_contexteOpenGL(0) {

}


SceneOpenGL::~SceneOpenGL() {
   SDL_GL_DeleteContext(m_contexteOpenGL);
   SDL_DestroyWindow(m_fenetre);
   SDL_Quit();
}


bool SceneOpenGL::initialiserFenetre() {

      // Initialisation de la SDL
   if(SDL_Init(SDL_INIT_VIDEO) < 0) {
      std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
      SDL_Quit();

      return false;
   }


      // Version d'OpenGL
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);


      // Double Buffer
   SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
   SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


      // Création de la fenêtre
   m_fenetre = SDL_CreateWindow(m_titreFenetre.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_largeurFenetre, m_hauteurFenetre, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

   if(m_fenetre == 0) {
      std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
      SDL_Quit();

      return false;
   }

      // Création du contexte OpenGL
   m_contexteOpenGL = SDL_GL_CreateContext(m_fenetre);

   if(m_contexteOpenGL == 0) {
      std::cout << SDL_GetError() << std::endl;
      SDL_DestroyWindow(m_fenetre);
      SDL_Quit();

      return false;
   }

   if (!gladLoadGLLoader ((GLADloadproc)SDL_GL_GetProcAddress)) {
      std::cout << "Failed to initialize GLAD." << std::endl;
      return false;
   }

   return true;
}


bool SceneOpenGL::initGL() {

   glEnable(GL_DEPTH_TEST);

      // Tout s'est bien passé, on retourne true
   return true;
}


void SceneOpenGL::bouclePrincipale() {

   float angle {0.0};

      // Matrices
   mat4 projection;
   mat4 modelview;

   projection = perspective(70.0, (double) m_largeurFenetre / m_hauteurFenetre, 1.0, 100.0);
   modelview = mat4(1.0);

      // Caméra mobile
   Camera camera(vec3(15, 15, 15), vec3(0, 0, 0), vec3(0, 0, 1), 0.5, 0.5);
   m_input.afficherPointeur(false);
   m_input.capturerPointeur(true);

      // Placement de la caméra
   camera.lookAt(modelview);

   mat4 sauv_caisse = translate (modelview, vec3 (0.0, 0.0, 1.0));
   mat4 sauv_caisse2 = translate (modelview, vec3 (-3.0, -3.0, 1.0));
   mat4 sauv_caisse3 = translate (modelview, vec3 (-3.0, 3.0, 1.0));
   mat4 sauv_cristal = translate (modelview, vec3 (0, 0, 3.5));
   mat4 sauv_maison = rotate (modelview, (float)(-90.0 * M_PI / 180.0), vec3 (0, 0, 1));

   Sol herbe (glm::vec3 (-30.0, -30.0, -0.002), (float)60.0, (float)60.0, "Shaders/texture.vert", "Shaders/texture.frag", "../textures/vegetal/veg007.jpg");
   Sol terre (glm::vec3 (-5.0, -5.0, -0.001), (float)10.0, (float)10.0, "Shaders/texture.vert", "Shaders/texture.frag", "../textures/ground/ground014.jpg");
   Sol espace (glm::vec3 (-500.0, -500.0, 50), (float)1000.0, (float)1000.0, "Shaders/texture.vert", "Shaders/texture.frag", "ciel.png");

   Caisse caisse (2.0, "Shaders/texture.vert", "Shaders/texture.frag", "../textures/crate/crate03.jpg");
   Caisse caisse2 (2.0, "Shaders/texture.vert", "Shaders/texture.frag", "../textures/crate/crate04.jpg");
   Caisse caisse3 (2.0, "Shaders/texture.vert", "Shaders/texture.frag", "../textures/crate/crate12.jpg");

   Cristal cristal (glm::vec3 (0, 0, 0), 1, "Shaders/texture.vert", "Shaders/texture.frag", "../textures/bricks/brick102b.jpg");

   Maison maison ("Shaders/texture.vert", "Shaders/texture.frag", "../textures/bricks/brick003r.jpg", "../textures/roof/roof01.jpg");

   bool change {true};

      // Boucle principale
   while(!m_input.terminer()) {

      SDL_Delay  (15);

      angle += 0.0001;

      change = do_events (&camera, herbe, espace);

         // Nettoyage de l'écran
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         // Placement de la caméra
      camera.lookAt(modelview);

      if (change) {

         sauv_caisse = translate (modelview, vec3 (0.0, 0.0, 1.0));
         sauv_caisse2 = translate (modelview, vec3 (-3.0, -3.0, 1.0));
         sauv_caisse3 = translate (modelview, vec3 (-3.0, 3.0, 1.0));
         sauv_cristal = translate (modelview, vec3 (0, 0, 3.5));
         sauv_maison = rotate (modelview, (float)(-90.0 * M_PI / 180.0), vec3 (0, 0, 1));

         change = false;
      }

      sauv_cristal = rotate (sauv_cristal, angle, vec3 (0, 0, 1));

      herbe.afficher (projection, modelview);
      terre.afficher (projection, modelview);
      espace.afficher (projection, modelview);

      modelview = sauv_maison;
      maison.afficher (projection, modelview);

      modelview = sauv_caisse;
      caisse.afficher (projection, modelview);

      modelview = sauv_caisse2;
      caisse2.afficher (projection, modelview);

      modelview = sauv_caisse3;
      caisse3.afficher (projection, modelview);

      modelview = sauv_cristal;
      cristal.afficher (projection, modelview);

         // Actualisation de la fenêtre
      SDL_GL_SwapWindow(m_fenetre);
   }
}


bool SceneOpenGL::do_events (Camera* camera, Sol herbe, Sol espace) {

   bool change {false};

      // Gestion des évènements
   m_input.updateEvenements ();

      // quit
   if (m_input.getTouche (SDL_SCANCODE_ESCAPE))
      exit (EXIT_SUCCESS);

      // moove mouse
   if (m_input.getXRel () != 0 || m_input.getYRel () != 0) {
      camera -> orienter (m_input.getXRel(), m_input.getYRel());
      change = true;
   }

   if (m_input.getTouche (SDL_SCANCODE_W)) {

      camera -> go_on ();

      std::array <float, 24> cube {getcube (3.0, camera -> getPos ())};
      bool stop {false};

      for (size_t i = 0 ; i < 24 && !stop ; i += 3) {
         if (!herbe.est_au_dessus(glm::vec3 (cube [i], cube [i + 1], cube [i + 2])) || !espace.est_au_dessous(glm::vec3 (cube [i], cube [i + 1], cube [i + 2]))) {
            camera -> go_back ();
            camera -> go_on_h ();
            stop = true;
         }
      }

      change = true;
   }

   if (m_input.getTouche (SDL_SCANCODE_S)) {
      camera -> go_back ();

      std::array <float, 24> cube {getcube (3.0, camera -> getPos ())};
      bool stop {false};

      for (size_t i = 0 ; i < 24 && !stop ; i += 3) {
         if (!herbe.est_au_dessus(glm::vec3 (cube [i], cube [i + 1], cube [i + 2])) || !espace.est_au_dessous(glm::vec3 (cube [i], cube [i + 1], cube [i + 2]))) {
            camera -> go_on ();
            camera -> go_back_h ();
            stop = true;
         }
      }

      change = true;
   }

   if (m_input.getTouche (SDL_SCANCODE_A)) {
      camera -> go_left ();

      std::array <float, 24> cube {getcube (3.0, camera -> getPos ())};
      bool stop {false};

      for (size_t i = 0 ; i < 24 && !stop ; i += 3) {
         if (!herbe.est_au_dessus(glm::vec3 (cube [i], cube [i + 1], cube [i + 2])) || !espace.est_au_dessous(glm::vec3 (cube [i], cube [i + 1], cube [i + 2]))) {
            camera -> go_right ();
            stop = true;
         }
      }

      change = true;
   }

   if (m_input.getTouche (SDL_SCANCODE_D)) {
      camera -> go_right ();

      std::array <float, 24> cube {getcube (3.0, camera -> getPos ())};
      bool stop {false};

      for (size_t i = 0 ; i < 24 && !stop ; i += 3) {
         if (!herbe.est_au_dessus(glm::vec3 (cube [i], cube [i + 1], cube [i + 2])) || !espace.est_au_dessous(glm::vec3 (cube [i], cube [i + 1], cube [i + 2]))) {
            camera -> go_left ();
            stop = true;
         }
      }

      change = true;
   }

   return change;
}


