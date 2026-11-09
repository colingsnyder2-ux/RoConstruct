// from server: 28% by atomic.potato
struct VCoordinateFrame {
    char pad0[0x14];
    void* vt14;
    void* vt18;
    char pad1[0x4];
    void* vt20;
    char pad2[0x98];
    void* field_bc;
    void destroy();
};

extern "C" void __stdcall sub_4d1460(void*);
extern "C" void __stdcall sub_718a32(void*);
extern "C" void __stdcall sub_5d2b60();

void VCoordinateFrame::destroy()
{
    void* p = field_bc;
    if (p) {
        sub_4d1460(p);
        sub_718a32(p);
    }
    *(void**)this = (void*)0x8d69ec;
    *(void**)((char*)this + 0x14) = (void*)0x8d69e0;
    *(void**)((char*)this + 0x18) = (void*)0x8d69d8;
    *(void**)((char*)this + 0x20) = (void*)0x8d69d0;
    sub_5d2b60();
}
