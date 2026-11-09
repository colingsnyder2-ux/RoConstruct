// from server: 100% by colin
struct VCWorkspace_ComObject {
    void construct();
};

extern "C" void __fastcall sub_467ed0(void*);
extern "C" void __fastcall sub_466bc0(void*);

struct GlobalThing {
    void* vtbl;
    void method();
};

extern GlobalThing* g_8bae44;

void VCWorkspace_ComObject::construct() {
    *(int*)((char*)this + 0x00) = 0x784b4c;
    *(int*)((char*)this + 0x04) = 0x784b34;
    *(int*)((char*)this + 0x08) = 0x784b1c;
    *(int*)((char*)this + 0x0c) = 0x784af8;
    *(int*)((char*)this + 0x18) = 0x784ae0;
    *(int*)((char*)this + 0x20) = 0x784ac4;
    *(int*)((char*)this + 0x28) = 0x784ab8;
    *(int*)((char*)this + 0x2c) = 0x784aac;
    *(int*)((char*)this + 0x30) = 0xc0000001;
    sub_467ed0(this);
    GlobalThing* g = g_8bae44;
    void* vt = g->vtbl;
    void (__fastcall *fn)(GlobalThing*) = *(void (__fastcall **)(GlobalThing*))((char*)vt + 8);
    fn(g);
    sub_466bc0(this);
}
