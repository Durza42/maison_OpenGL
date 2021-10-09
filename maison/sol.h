#ifndef SOL_H
 #define SOL_H

 #ifdef WIN32
  #include <GL/glew.h>

 #else
  #define GL3_PROTOTYPES 1
  #include <GLES3/gl3.h>

 #endif


 #include <glm/glm.hpp>
 #include <glm/gtx/transform.hpp>
 #include <glm/gtc/type_ptr.hpp>

 #include <string>
 #include "Texture.h"
 #include "Shader.h"

class Sol {

  public:

   Sol (glm::vec3 coo_origine, float longueur, float largeur, std::string const vertexShader, std::string const fragmentShader, std::string const texture);
   ~Sol ();

   void afficher (glm::mat4 &projection, glm::mat4 &modelview);

   bool is_heighter (const glm::vec3 pt) const;
   bool isNot_heighter (const glm::vec3 pt) const;
   bool is_some_z (const glm::vec3 pt) const;
   bool est_au_dessus (const glm::vec3 pt) const;
   bool est_au_dessous (const glm::vec3 pt) const;
   bool is_in (const glm::vec3 pt) const;

  private:

   Texture m_texture;
   float m_coordTexture [12];
   float m_vertices [18];

   glm::vec3 m_coo_origine;
   float m_longueur;
   float m_largeur;

   Shader m_shader;
};

#endif
