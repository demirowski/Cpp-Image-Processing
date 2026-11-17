#include "scene_manager.h"


void SceneManager::uploadSources(Field& field) {
    sources = &(field.getLights());
}

void SceneManager::uploadObstacles(Field& field) {
    obstacles = &(field.getObstacles());
}