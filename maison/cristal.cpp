#include "cristal.h"

Cristal::Cristal (glm::vec3 center, float taille, std::string const vertexShader, std::string const fragmentShader, std::string const texture) : m_shader (vertexShader, fragmentShader), m_texture (texture) {

   m_texture.charger ();
   m_shader.charger ();

   float TMPvertices [] {center.x,                 center.y,               center.z + taille,
                         center.x - taille / 2,    center.y - taille / 2,  center.z,
                         center.x + taille / 2,    center.y - taille / 2,  center.z,            // triangle 1

                         center.x,                 center.y,               center.z + taille,
                         center.x + taille / 2,    center.y - taille / 2,  center.z,
                         center.x + taille / 2,    center.y + taille / 2,  center.z,            // triangle 2

                         center.x,                 center.y,               center.z + taille,
                         center.x + taille / 2,    center.y + taille / 2,  center.z,
                         center.x - taille / 2,    center.y + taille / 2,  center.z,            // triangle 3

                         center.x,                 center.y,               center.z + taille,
                         center.x - taille / 2,    center.y + taille / 2,  center.z,
                         center.x - taille / 2,    center.y - taille / 2,  center.z,            // triangle 4

                         center.x,                 center.y,               center.z - taille,
                         center.x - taille / 2,    center.y - taille / 2,  center.z,
                         center.x + taille / 2,    center.y - taille / 2,  center.z,            // triangle 5

                         center.x,                 center.y,               center.z - taille,
                         center.x + taille / 2,    center.y - taille / 2,  center.z,
                         center.x + taille / 2,    center.y + taille / 2,  center.z,            // triangle 6

                         center.x,                 center.y,               center.z - taille,
                         center.x + taille / 2,    center.y + taille / 2,  center.z,
                         center.x - taille / 2,    center.y + taille / 2,  center.z,            // triangle 7

                         center.x,                 center.y,               center.z - taille,
                         center.x - taille / 2,    center.y + taille / 2,  center.z,
                         center.x - taille / 2,    center.y - taille / 2,  center.z};           // triangle 8



   float TMPcooTexture [] {0.5, 0.0,   0.5, 0.5,    0.0, 0.0,            // triangle 1
                           0.5, 0.0,   0.5, 0.5,    0.0, 0.0,            // triangle 2
                           0.5, 0.0,   0.5, 0.5,    0.0, 0.0,            // triangle 3
                           0.5, 0.0,   0.5, 0.5,    0.0, 0.0,            // triangle 4
                           0.5, 0.0,   0.5, 0.5,    0.0, 0.0,            // triangle 5
                           0.5, 0.0,   0.5, 0.5,    0.0, 0.0,            // triangle 6
                           0.5, 0.0,   0.5, 0.5,    0.0, 0.0,            // triangle 7
                           0.5, 0.0,   0.5, 0.5,    0.0, 0.0,};          // triangle 8


   for(int i = 0 ; i < 48 ; ++i)
      m_coordTexture [i] = TMPcooTexture [i];

   for(int i = 0 ; i < 72 ; ++i)
      m_vertices [i] = TMPvertices [i];
}

Cristal::~Cristal () {
   
}


void Cristal::afficher (glm::mat4 &projection, glm::mat4 &modelview) {

      // Activation du shader
   glUseProgram(m_shader.getProgramID());


         // Envoi des vertices
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, m_vertices);
      glEnableVertexAttribArray(0);

         // Envoi des coordonnées de texture
      glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, m_coordTexture);
      glEnableVertexAttribArray(2);

         // Envoi des matrices
      glUniformMatrix4fv (glGetUniformLocation (m_shader.getProgramID(), "projection"), 1, GL_FALSE, value_ptr (projection));
      glUniformMatrix4fv (glGetUniformLocation (m_shader.getProgramID(), "modelview"), 1, GL_FALSE, value_ptr (modelview));

         // Verrouillage de la texture
      glBindTexture(GL_TEXTURE_2D, m_texture.getID());

         // Rendu
      glDrawArrays(GL_TRIANGLES, 0, 24);

         // Déverrouillage de la texture
      glBindTexture(GL_TEXTURE_2D, 0);

         // Désactivation des tableaux
      glDisableVertexAttribArray(2);
      glDisableVertexAttribArray(0);


      // Désactivation du shader
   glUseProgram(0);
}
