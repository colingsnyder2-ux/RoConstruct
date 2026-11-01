// from server: 100% by tester
struct Seg_00400000 {
    void construct();
};

extern "C" void __fastcall sub_467c00(void*);
extern "C" void __fastcall sub_4668a0(void*);

struct GlobalThing {
    void* vtbl;
};

extern GlobalThing* g_8b535c;

void Seg_00400000::construct() {
    *(int*)((char*)this + 0x00) = 0x783b4c;
    *(int*)((char*)this + 0x04) = 0x783b34;
    *(int*)((char*)this + 0x08) = 0x783b1c;
    *(int*)((char*)this + 0x0c) = 0x783af8;
    *(int*)((char*)this + 0x18) = 0x783ae0;
    *(int*)((char*)this + 0x20) = 0x783ac4;
    *(int*)((char*)this + 0x28) = 0x783ab8;
    *(int*)((char*)this + 0x2c) = 0x783aac;
    *(int*)((char*)this + 0x30) = 0xc0000001;
    sub_467c00(this);
    GlobalThing* g = g_8b535c;
    void* vt = g->vtbl;
    void (__fastcall *fn)(GlobalThing*) = *(void (__fastcall **)(GlobalThing*))((char*)vt + 8);
    fn(g);
    sub_4668a0(this);
}
