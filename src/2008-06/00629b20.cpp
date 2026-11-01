// from server: 100% by king_originala
struct Detector;

struct Instance {
    virtual void anchor();
    char padding[256];
    Instance* parent;
    Detector* getDetector();
};

struct Detector {
    char padding[324];
    float maximumDistance;
    void activate(Instance*, float);
};

extern char instanceType[];
extern char workspaceType[];
extern "C" void* __cdecl castInstance(
    Instance*, int, void*, void*, int);

bool func_00629b20(Instance* instance, float distance, bool activate)
{
    if (instance) {
        Instance* current = instance;
        do {
            Detector* detector = current->getDetector();
            if (detector && detector->maximumDistance > distance) {
                if (activate)
                    detector->activate(instance, distance);
                return true;
            }
            current = current->parent;
        } while (current &&
                 !castInstance(current, 0, instanceType, workspaceType, 0));
    }
    return false;
}
