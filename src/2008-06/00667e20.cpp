// from server: 100% by king_originala
extern const float initialX;
extern const float initialY;
extern char primaryTable[];
extern char secondaryTable[];

struct GroupDragTool {
    void* vtable;
    void* vtable2;
    char pad[0x98];
    float fieldA0;
    float fieldA4;

    GroupDragTool(void* a, float x, float y);
    ~GroupDragTool();
    int f();
};

struct Signal {
    void connect(void** argument, int enabled);
};

struct Target {
    char pad[0x10];
    Signal signal;
};

struct Registry {
    Target* find(void* key);
};

extern Registry registry;

struct GettingUp : GroupDragTool {
    GettingUp(void* argument);
};

GettingUp::GettingUp(void* argument)
    : GroupDragTool(argument, initialX, initialY)
{
    vtable = primaryTable;
    vtable2 = secondaryTable;

    int object = f();
    void* key = object ? reinterpret_cast<void*>(object + 0x14) : 0;
    Target* target = registry.find(key);
    if (target)
        target->signal.connect(&argument, 1);
}
