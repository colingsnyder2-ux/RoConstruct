// from server: 67% by atomic.potato
struct RbxSceneManager
{
    struct Vector3
    {
        float x;
        float y;
        float z;
    };

    struct Scene
    {
        float pad[149];
        float x;
        float y;
        float z;
    };

    Scene* scene;

    void f(Vector3* value);
};

void RbxSceneManager::f(Vector3* value)
{
    if (scene != 0)
    {
        scene->x = value->x;
        scene->y = value->y;
        scene->z = value->z;
    }
}
