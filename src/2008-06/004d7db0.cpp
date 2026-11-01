// from server: 100% by tester
struct Queue { void flush(); };
struct Scene { char pad[8]; Queue queue; };

struct SimpleSceneManager {
    void* vtbl;
    Scene* scene;
    void flush();
};

void SimpleSceneManager::flush()
{
    scene->queue.flush();
}
