// from server: 100% by king_originala
struct Queue {
    void process(int, int);
};

struct Scene {
    char pad[8];
    Queue queue;
};

struct SimpleSceneManager {
    void* vtbl;
    Scene* scene;
    void process();
};

void SimpleSceneManager::process()
{
    scene->queue.process(0, 1);
}
