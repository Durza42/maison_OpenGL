#include "utilities.h"

std::array <float, 24> getcube (float taille, glm::vec3 center) {

   std::array <float, 24> cube {center.x - taille / (float)2.0, center.y - taille / (float)2.0, center.z - taille / (float)2.0,     // bas, gauche, devant
                                center.x + taille / (float)2.0, center.y - taille / (float)2.0, center.z - taille / (float)2.0,     // bas, droite, devant
                                center.x - taille / (float)2.0, center.y - taille / (float)2.0, center.z + taille / (float)2.0,     // haut, gauche, devant
                                center.x + taille / (float)2.0, center.y - taille / (float)2.0, center.z + taille / (float)2.0,     // haut, droite, devant
                                center.x - taille / (float)2.0, center.y + taille / (float)2.0, center.z - taille / (float)2.0,     // bas, gauche, deriere
                                center.x + taille / (float)2.0, center.y + taille / (float)2.0, center.z - taille / (float)2.0,     // bas, droite, deriere
                                center.x - taille / (float)2.0, center.y + taille / (float)2.0, center.z + taille / (float)2.0,     // haut, gauche, deriere
                                center.x + taille / (float)2.0, center.y + taille / (float)2.0, center.z + taille / (float)2.0};    // haut, droite, deriere
   return cube;
}

bool pt_is_in_cube (glm::vec3 pt, glm::vec3 center, float taille) {

   if (pt.x < center.x - taille / (float)2.0 || pt.x > center.x + taille / (float)2.0) // si x est plus grand ou plus petit
      return false;

   if (pt.y < center.y - taille / (float)2.0 || pt.y > center.y + taille / (float)2.0) // si y est plus grand ou plus petit
      return false;

   if (pt.z < center.z - taille / (float)2.0 || pt.z > center.z + taille / (float)2.0) // si z est plus grand ou plus petit
      return false;

   return true;
}

bool pt_is_in_pave (glm::vec3 pt, glm::vec3 haut_gauche_deriere, glm::vec3 bas_droite_devant) {

   if (pt.x < haut_gauche_deriere.x || pt.x > bas_droite_devant.x) // si x est plus grand ou plus petit
      return false;

   if (pt.y < bas_droite_devant.y || pt.y > haut_gauche_deriere.y) // si y est plus grand ou plus petit
      return false;

   if (pt.z < bas_droite_devant.z || pt.z > haut_gauche_deriere.z) // si z est plus grand ou plus petit
      return false;

   return true;
}
