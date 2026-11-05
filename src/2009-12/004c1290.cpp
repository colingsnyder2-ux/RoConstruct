// from server: 48% by atomic.potato
struct SceneNode {
    SceneNode(void*);
};

struct Slot {
    char pad0[0x238];
    void* field238;
    char pad23c[0x25c - 0x23c];
    int field25c;
    int field260;
    void ctor(void*);
};

extern "C" void* __stdcall sub_98c808(void*);
extern "C" void __fastcall sub_4b9b50(void*);

void Slot::ctor(void* a) {
    sub_98c808(a);
    void* p = (char*)this + 0x238;
    sub_4b9b50(p);
    *(void**)((char*)this + 0x238) = (void*)0x9b4f9c;
    *(void**)this = (void*)0x9b4fd4;
    *(void**)((char*)this + 0x238) = (void*)0x9b4fb8;
    field25c = 0;
    field260 = 0;
}
