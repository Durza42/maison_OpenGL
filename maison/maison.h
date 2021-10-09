#ifndef MAISON_H
 #define MAISON_H

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

class Maison {

  public:

   Maison (std::string const vertexShader, std::string const fragmentShader, std::string const texture, std::string const texture_toit);
   ~Maison ();

   void afficher (glm::mat4 &projection, glm::mat4 &modelview);

  private:

   Texture m_texture;
   Texture m_texture_toit;
   float m_coordTexture [126];
   float m_vertices [189];

   Shader m_shader;
};

#endif
