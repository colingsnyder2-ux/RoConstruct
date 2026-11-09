// from server: 50% by atomic.potato
struct RbxSceneUpdater {
    char pad0[0x43c];
    void* field43c;
    void update();
};

struct Sub57c6f0 {
    void method();
};

extern "C" void __stdcall sub_4bfec0(void* arg);

void RbxSceneUpdater::update() {
    ((Sub57c6f0*)this)->method();
    void* p = field43c;
    void* q = *(void**)((char*)p + 0x10);
    void* r = *(void**)((char*)q + 0x47dc);
    struct { void* a; void* b; } local;
    local.a = (void*)0x9b3e24;
    local.b = this;
    sub_4bfec0(&local);
}
