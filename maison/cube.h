#ifndef DEF_CUBE
 #define DEF_CUBE


 #include <glad/glad.h>

// Includes GLM

 #include <glm/glm.hpp>
 #include <glm/gtx/transform.hpp>
 #include <glm/gtc/type_ptr.hpp>


// Includes

 #include "Shader.h"


// Classe Cube

class Cube {

  public:

   Cube(float taille, std::string const vertexShader, std::string const fragmentShader);
   ~Cube();

   void afficher(glm::mat4 &projection, glm::mat4 &modelview);

  protected:

   Shader m_shader;
   float m_vertices[108];
   float m_couleurs[108];

};

#endif
