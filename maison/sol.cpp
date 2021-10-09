#include "sol.h"

Sol::Sol (glm::vec3 coo_origine, float longueur, float largeur, std::string const vertexShader, std::string const fragmentShader, std::string const texture) :
                                                                                                            m_longueur {longueur}, m_largeur {largeur}, m_coo_origine (coo_origine),
                                                                                                            m_shader (vertexShader, fragmentShader), m_texture (texture) {

   m_texture.charger ();
   m_shader.charger ();

   float TMPvertices [] {coo_origine.x,            coo_origine.y,           coo_origine.z,
                         coo_origine.x + longueur, coo_origine.y,           coo_origine.z,
                         coo_origine.x,            coo_origine.y + largeur, coo_origine.z,             // triangle 1

                         coo_origine.x + longueur, coo_origine.y,           coo_origine.z,
                         coo_origine.x,            coo_origine.y + largeur, coo_origine.z,
                         coo_origine.x + longueur, coo_origine.y + largeur, coo_origine.z};            // triangle 2

   float TMPcooTexture [] {0.0, 0.0,   (float) (longueur / 5.0), 0.0,    0.0, (float) (longueur / 5.0),            // triangle 1
                           (float) (longueur / 5.0), 0.0,   0.0, (float) (longueur / 5.0),    (float) (longueur / 5.0), (float) (longueur / 5.0)};   // triangle 2


   for(int i = 0 ; i < 12 ; ++i)
      m_coordTexture [i] = TMPcooTexture [i];

   for(int i = 0 ; i < 18 ; ++i)
      m_vertices [i] = TMPvertices [i];
}

Sol::~Sol () {
   
}


void Sol::afficher (glm::mat4 &projection, glm::mat4 &modelview) {

      // Activation du shader
   glUseProgram(m_shader.getProgramID());


         // Envoi des vertices
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, m_vertices);
      glEnableVertexAttribArray(0);

         // Envoi des coordonnées de texture
      glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, m_coordTexture);
      glEnableVertexAttribArray(2);

         // Envoi des matrices
      glUniformMatrix4fv(glGetUniformLocation(m_shader.getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));
      glUniformMatrix4fv(glGetUniformLocation(m_shader.getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));

         // Verrouillage de la texture
      glBindTexture(GL_TEXTURE_2D, m_texture.getID());

         // Rendu
      glDrawArrays(GL_TRIANGLES, 0, 6);

         // Déverrouillage de la texture
      glBindTexture(GL_TEXTURE_2D, 0);

         // Désactivation des tableaux
      glDisableVertexAttribArray(2);
      glDisableVertexAttribArray(0);


      // Désactivation du shader
   glUseProgram(0);
}


bool Sol::is_heighter (const glm::vec3 pt) const {
   return pt.z > m_coo_origine.z;
}

bool Sol::isNot_heighter (const glm::vec3 pt) const {
   return pt.z < m_coo_origine.z;
}

bool Sol::is_some_z (const glm::vec3 pt) const {
   return pt.z == m_coo_origine.z;
}


bool Sol::est_au_dessus (const glm::vec3 pt) const {
   if (pt.x < m_coo_origine.x || pt.x > m_coo_origine.x + m_longueur) // si X ne correspond pas
      return false;
   else if (pt.y < m_coo_origine.y || pt.y > m_coo_origine.y + m_largeur) // si Y ne correspond pas
      return false;
   else
      return is_heighter (pt);
}

bool Sol::est_au_dessous (const glm::vec3 pt) const {
   if (pt.x < m_coo_origine.x || pt.x > m_coo_origine.x + m_longueur) // si X ne correspond pas
      return false;
   else if (pt.y < m_coo_origine.y || pt.y > m_coo_origine.y + m_largeur) // si Y ne correspond pas
      return false;
   else
      return isNot_heighter (pt);
}

bool Sol::is_in (const glm::vec3 pt) const {
   if (pt.x < m_coo_origine.x || pt.x > m_coo_origine.x + m_longueur) // si X ne correspond pas
      return false;
   else if (pt.y < m_coo_origine.y || pt.y > m_coo_origine.y + m_largeur) // si Y ne correspond pas
      return false;
   else
      return is_some_z (pt);
}

