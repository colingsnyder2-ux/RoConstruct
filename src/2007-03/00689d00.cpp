// from server: 100% by tester
extern "C" int (__stdcall *ReleaseCapture)();
extern "C" int (__stdcall *PostMessageA)(void*, unsigned int, unsigned int, int);

struct CXTPPropertyGridItemColor {
    void OnInplaceButtonDown(int);
};

void CXTPPropertyGridItemColor::OnInplaceButtonDown(int param) {
    ReleaseCapture();
    int v = *(int*)((char*)this + 0x17c);
    void** vt = *(void***)this;
    void (__thiscall *fn)(void*, int, int) = *(void (__thiscall **)(void*, int, int))((char*)vt + 0x140);
    fn(this, param, v);
    PostMessageA(*(void**)((char*)this + 0x20), 0x10, 0, 0);
}
