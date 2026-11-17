#include "light_source.h"
#include "obstacle.h"
#include "2d_field.h"


class SceneManager {

    private:
        vector<shared_ptr<Obstacle>>* obstacles = nullptr;
        vector<shared_ptr<LSource>>* sources = nullptr;



    public:
        void uploadSources(Field& field);
        void uploadObstacles(Field& field);




};