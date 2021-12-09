#include "maison.h"

Maison::Maison (std::string const vertexShader, std::string const fragmentShader, std::string const texture, std::string const texture_toit) : m_shader (vertexShader, fragmentShader), m_texture (texture), m_texture_toit (texture_toit) {

   m_texture.charger ();
   m_texture_toit.charger ();
   m_shader.charger ();
   

   float TMPvertices [] {-5, -5, 5,       -5, 5, 5,      -5, 5, 0,      // mur de gauche
                         -5, -5, 5,       -5, -5, 0,     -5, 5, 0,      // mur de gauche

                         5, -5, 5,        -5, -5, 5,     -5, -5, 0,     // mur de derière
                         5, -5, 0,        -5, -5, 0,     5, -5, 5,      // mur de derière

                         5, -5, 5,        5, 5, 5,       5, 5, 0,       // mur de droite
                         5, -5, 5,        5, -5, 0,      5, 5, 0,       // mur de droite

                         -5, -5, 5,       0, -5, 6,      5, -5, 5,      // combles

                         -6, -6, 4.8,     0, -6, 6,      -6, 6, 4.8,    // toit de gauche
                         0, -6, 6,        0, 6, 6,       -6, 6, 4.8,    // toit de gauche

                         0, -6, 6,        6, -6, 4.8,    0, 6, 6,       // toit de droite
                         6, -6, 4.8,      6, 6, 4.8,     0, 6, 6,       // toit de droite

                         5.5, 5, 0,       5, 5, 0,        5, 5, 5,
                         5.5, 5, 0,       5.5, 5, 5,      5, 5, 5,        // devant du mur de gauche

                         5.5, 5, 0,       5.5, 5, 5,      5.5, -5.5, 5,
                         5.5, 5, 0,       5.5, -5.5, 0,   5.5, -5.5, 5,   // exterieur du mur de gauche

                         5.5, -5.5, 5,    5.5, -5.5, 0,   -5.5, -5.5, 5,
                         5.5, -5.5, 0,    -5.5, -5.5, 0,  -5.5, -5.5, 5,             // exterieur du mur de deriere 

                         -5.5, -5.5, 5,   -5.5, -5.5, 0, -5.5, 5.0, 0,
                         -5.5, 5.0, 5,    -5.5, -5.5, 5,  -5.5, 5.0, 0,

                         -5.5, 5.0, 5,    -5.5, 5.0, 0,   -5.0, 5.0, 0,
                         -5.5, 5.0, 5,    -5.0, 5.0, 5,   -5.0, 5.0, 0,
                         };



   float TMPcooTexture [] {0.0, 1.0,   1.0, 1.0,    1.0, 0.0,
                           0.0, 1.0,   0.0, 0.0,    1.0, 0.0,            // mur de gauche

                           0.0, 1.0,   1.0, 1.0,    1.0, 0.0,
                           0.0, 0.0,   1.0, 0.0,    0.0, 1.0,            // mur de derière

                           0.0, 1.0,   1.0, 1.0,    1.0, 0.0,
                           0.0, 1.0,   0.0, 0.0,    1.0, 0.0,            // mur de droite

                           0.0, 0.0,   0.5, 0.2,    1.0, 0.0,            // combles

                           0.0, 0.0,   0.0, 2.0,    4.0, 0.0,
                           0.0, 2.0,   4.0, 2.0,    4.0, 0.0,            // toit de gauche

                           0.0, 0.0,   0.0, 2.0,    4.0, 0.0,
                           0.0, 2.0,   4.0, 2.0,    4.0, 0.0,            // toit de gauche

                           0.0, 0.0,   0.1, 0.0,    0.1, 1.0,
                           0.0, 0.0,   0.0, 1.0,    0.1, 1.0,            // devant du mur de gauche

                           1.0, 0.0,   1.0, 1.0,    0.0, 1.0,
                           1.0, 0.0,   0.0, 0.0,    0.0, 1.0,            // exterieur du mur de gauche

                           1.0, 1.0,   1.0, 0.0,    0.0, 1.0,
                           1.0, 0.0,   0.0, 0.0,    0.0, 1.0,            // exterieur du mur de derière

                           1.0, 1.0,   1.0, 0.0,    0.0, 0.0,
                           0.0, 1.0,   2.0, 1.0,    0.0, 0.0,            // exterieur du mur de droite

                           0.1, 1.0,   0.1, 0.0,    0.0, 0.0,
                           0.1, 1.0,   0.0, 1.0,    0.0, 0.0,            // devant du mur de droite
                           };


   for(int i = 0 ; i < 126 ; ++i)
      m_coordTexture [i] = TMPcooTexture [i];

   for(int i = 0 ; i < 189 ; ++i)
      m_vertices [i] = TMPvertices [i];
}

Maison::~Maison () {
   
}


void Maison::afficher (glm::mat4 &projection, glm::mat4 &modelview) {

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
      glDrawArrays(GL_TRIANGLES, 0, 21);

         // Verrouillage de la texture
      glBindTexture(GL_TEXTURE_2D, m_texture_toit.getID());

         // Rendu
      glDrawArrays(GL_TRIANGLES, 21, 12);

         // Verrouillage de la texture
      glBindTexture(GL_TEXTURE_2D, m_texture.getID());

         // Rendu
      glDrawArrays(GL_TRIANGLES, 33, 30);

         // Déverrouillage de la texture
      glBindTexture(GL_TEXTURE_2D, 0);

         // Désactivation des tableaux
      glDisableVertexAttribArray(2);
      glDisableVertexAttribArray(0);


      // Désactivation du shader
   glUseProgram(0);
}

