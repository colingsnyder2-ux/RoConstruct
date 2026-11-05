// from server: 74% by atomic.potato
struct ColourValue { float r, g, b, a; };

struct Vtbl1 {
    char pad[0x54];
    void* fn54;
};

struct Vtbl2 {
    char pad[0x138];
    void* fn138;
};

struct Vtbl3 {
    char pad[0x14c];
    void* fn14c;
};

struct Vtbl4 {
    char pad[0x154];
    void* fn154;
};

struct Obj {
    char pad0[0x44];
    void* p44;
    void* p48;
    void* p4c;
    void* p50;
    void* p54;
    char pad58[0x148 - 0x58];
    char b148;
};

extern "C" void __stdcall setBackgroundColour(void* viewport, const ColourValue* cv);

extern float g_9aea18;

struct RbxCullableSceneNode {
    void method_4b9d90(void* a, void* b);
    void method_4ba0f0(void* a, void* b);
    void func(void* a, void* b);
};

void RbxCullableSceneNode::func(void* a, void* b) {
    Obj* self = (Obj*)this;
    ColourValue cv;
    cv.r = *(float*)((char*)a + 0xc);
    cv.g = *(float*)((char*)a + 0x10);
    cv.b = *(float*)((char*)a + 0x14);
    cv.a = g_9aea18;
    setBackgroundColour(*(void**)((char*)b + 0x30), &cv);
    if (self->b148) {
        void* p;
        p = self->p44;
        if (!((bool(__thiscall*)(void*))(*(void***)p)[0x54/4])(p)) {
            void* q = self->p50;
            ((void(__thiscall*)(void*, void*))(*(void***)q)[0x138/4])(q, self->p44);
        }
        p = self->p4c;
        if (!((bool(__thiscall*)(void*))(*(void***)p)[0x54/4])(p)) {
            void* q = self->p50;
            ((void(__thiscall*)(void*, void*))(*(void***)q)[0x138/4])(q, self->p4c);
        }
        p = self->p48;
        if (!((bool(__thiscall*)(void*))(*(void***)p)[0x54/4])(p)) {
            void* q = self->p54;
            ((void(__thiscall*)(void*, void*))(*(void***)q)[0x138/4])(q, self->p48);
        }
        method_4b9d90(a, b);
        method_4ba0f0(a, b);
    } else {
        void* q = self->p50;
        ((void(__thiscall*)(void*))(*(void***)q)[0x154/4])(q);
        void* r = self->p54;
        ((void(__thiscall*)(void*, void*))(*(void***)r)[0x14c/4])(r, self->p48);
    }
}
