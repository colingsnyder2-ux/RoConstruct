// from server: 100% by king_originala
struct Instance;
struct ServiceProvider {
    void notify(int value);
};

extern bool __cdecl isLocked(Instance *object);
extern void __cdecl setLocked(Instance *object, bool locked);
extern ServiceProvider *__cdecl findServiceProvider(Instance *object);

struct LockTool {
    unsigned char padding[24];
    Instance *parent;
    Instance *object;

    LockTool *activate(int unused);
};

LockTool *LockTool::activate(int unused)
{
    if (object) {
        setLocked(object, !isLocked(object));
        findServiceProvider(parent)->notify(8);
    }
    return this;
}
