// from server: 100% by atomic.potato
struct GroupDragTool {
    void* vtable;
    void* vtable2;
    char pad[0x98];
    float fieldA0;
    float fieldA4;
    GroupDragTool* construct(void* a, float x, float y);
};

struct StrafingNoPhysics {
    void* vtable;
    void* vtable2;
    StrafingNoPhysics* init(void* a);
};

extern float g_819ba4;
extern float g_84cc5c;
extern void* g_84ce54;
extern void* g_84ce4c;

StrafingNoPhysics* StrafingNoPhysics::init(void* a) {
    float f0 = g_819ba4;
    float f1 = g_84cc5c;
    ((GroupDragTool*)this)->construct(a, f0, f1);
    *(void**)this = &g_84ce54;
    *(void**)((char*)this + 4) = &g_84ce4c;
    return this;
}
