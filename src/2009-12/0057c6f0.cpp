// from server: 53% by atomic.potato
struct SceneUpdater;

extern "C" void __cdecl Function0057c490(void *);

struct SceneUpdater
{
    void f();
};

void SceneUpdater::f()
{
    void *value = *(void **)((char *)this + 0x1c);
    value = *(void **)((char *)value + 0xa90);
    Function0057c490(value);
}
