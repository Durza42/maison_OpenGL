#include "cube.h"

Cube::Cube (float taille, std::string const vertexShader, std::string const fragmentShader) : m_shader (vertexShader, fragmentShader) {

   m_shader.charger(); // Chargement du shader

   taille /= 2; // Division de la taille


   // Vertices temporaires

   float verticesTmp[] = { -taille, -taille, -taille,   taille, -taille, -taille,   taille, taille, -taille,     // Face 1
                           -taille, -taille, -taille,   -taille, taille, -taille,   taille, taille, -taille,     // Face 1

                           taille, -taille, taille,   taille, -taille, -taille,   taille, taille, -taille,       // Face 2
                           taille, -taille, taille,   taille, taille, taille,   taille, taille, -taille,         // Face 2

                           -taille, -taille, taille,   taille, -taille, taille,   taille, -taille, -taille,      // Face 3
                           -taille, -taille, taille,   -taille, -taille, -taille,   taille, -taille, -taille,    // Face 3

                           -taille, -taille, taille,   taille, -taille, taille,   taille, taille, taille,        // Face 4
                           -taille, -taille, taille,   -taille, taille, taille,   taille, taille, taille,        // Face 4

                           -taille, -taille, -taille,   -taille, -taille, taille,   -taille, taille, taille,     // Face 5
                           -taille, -taille, -taille,   -taille, taille, -taille,   -taille, taille, taille,     // Face 5

                           -taille, taille, taille,   taille, taille, taille,   taille, taille, -taille,         // Face 6
                           -taille, taille, taille,   -taille, taille, -taille,   taille, taille, -taille};      // Face 6


   // Couleurs temporaires

   float couleursTmp[] = { 1.0, 0.0, 0.0,   0.0, 1.0, 0.0,   0.0, 0.0, 1.0,           // Face 1
                           1.0, 0.0, 0.0,   0.0, 1.0, 0.0,   0.0, 0.0, 1.0,           // Face 1

                           1.0, 0.0, 0.0,   0.0, 1.0, 0.0,   0.0, 0.0, 1.0,           // Face 2
                           1.0, 0.0, 0.0,   0.0, 1.0, 0.0,   0.0, 0.0, 1.0,           // Face 2

                           0.0, 1.0, 0.0,   1.0, 0.0, 0.0,   0.0, 1.0, 0.0,           // Face 3
                           0.0, 1.0, 0.0,   1.0, 0.0, 0.0,   0.0, 1.0, 0.0,           // Face 3

                           0.0, 1.0, 0.0,   1.0, 0.0, 0.0,   0.0, 1.0, 0.0,           // Face 4
                           0.0, 1.0, 0.0,   0.0, 0.0, 1.0,   0.0, 1.0, 0.0,           // Face 4

                           1.0, 0.0, 0.0,   0.0, 1.0, 0.0,   0.0, 0.0, 1.0,           // Face 5
                           1.0, 0.0, 0.0,   0.0, 1.0, 0.0,   0.0, 0.0, 1.0,           // Face 5

                           0.0, 0.0, 1.0,   0.0, 1.0, 0.0,   0.0, 0.0, 1.0,           // Face 6
                           0.0, 0.0, 1.0,   0.0, 1.0, 0.0,   0.0, 0.0, 1.0};          // Face 6


   // Copie des valeurs dans les tableaux finaux

   for(int i(0); i < 108; i++)
   {
      m_vertices[i] = verticesTmp[i];
      m_couleurs[i] = couleursTmp[i];
   }
}

Cube::~Cube () {
   
}

void Cube::afficher(glm::mat4 &projection, glm::mat4 &modelview) {

   glUseProgram(m_shader.getProgramID()); // Activation du shader


   /* Envoi des vertices */
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, m_vertices);
   glEnableVertexAttribArray(0);


   /* Envoi de la couleur */
   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, m_couleurs);
   glEnableVertexAttribArray(1);


   /* Envoi des matrices */
   glUniformMatrix4fv(glGetUniformLocation(m_shader.getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));
   glUniformMatrix4fv(glGetUniformLocation(m_shader.getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));


   glDrawArrays(GL_TRIANGLES, 0, 36); // Rendu


   /* D??sactivation des tableaux */
   glDisableVertexAttribArray(1);
   glDisableVertexAttribArray(0);


   glUseProgram(0); // D??sactivation du shader
}
