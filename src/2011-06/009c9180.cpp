// from server: 27% by atomic.potato
struct GfxBinding {
    void func(int, int);
};

extern "C" void __stdcall sub_401de0(void*);
extern "C" char __fastcall sub_9c9110(void*);
extern "C" void __fastcall sub_9c8c00(void*);

void GfxBinding::func(int a, int b) {
    void* p = *(void**)((char*)this + 4);
    if (!sub_9c9110(p)) {
        sub_9c8c00(this);
    }
    if (b) {
        sub_401de0((void*)b);
    }
}
