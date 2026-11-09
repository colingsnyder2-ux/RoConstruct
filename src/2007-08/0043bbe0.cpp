// from server: 41% by colin
struct CAutoHidePanelTabManager {
    char pad[0x114];
    void* field114;
    void* field118;
    float method(int);
};

extern "C" void __stdcall sub_439850(void*, int);
extern "C" void __stdcall sub_5595A0(void*);

float CAutoHidePanelTabManager::method(int arg) {
    int v;
    int t = *(int*)((char*)field114 + 0x188);
    sub_439850(&v, t);
    void* p = (arg != 0) ? (void*)(arg + 4) : 0;
    void* q = *(void**)((char*)field118 + 0x18);
    float r = (*(float(__thiscall**)(void*, void*))(*(int*)q + 4))(q, p);
    sub_5595A0(&v);
    return r;
}
