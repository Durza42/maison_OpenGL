#ifndef CRISTAL_H
 #define CRISTAL_H

 #include <glad/glad.h>

 #include <glm/glm.hpp>
 #include <glm/gtx/transform.hpp>
 #include <glm/gtc/type_ptr.hpp>

 #include <string>
 #include "Texture.h"
 #include "Shader.h"

class Cristal {

  public:

   Cristal (glm::vec3 center, float taille, std::string const vertexShader, std::string const fragmentShader, std::string const texture);
   ~Cristal ();

   void afficher (glm::mat4 &projection, glm::mat4 &modelview);

  private:

   Texture m_texture;
   float m_coordTexture [48];
   float m_vertices [72];

   Shader m_shader;
};

#endif
