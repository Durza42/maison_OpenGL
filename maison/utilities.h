#ifndef UTILITIES_H
 #define UTILITIES_H

 #include <array>

 #include <glm/glm.hpp>
 #include <glm/gtx/transform.hpp>
 #include <glm/gtc/type_ptr.hpp>


std::array <float, 24> getcube (float taille, glm::vec3 center);
bool pt_is_in_cube (glm::vec3 pt, glm::vec3 center, float taille);
bool pt_is_in_pave (glm::vec3 pt, glm::vec3 haut_gauche_deriere, glm::vec3 bas_droite_devant);

#endif
