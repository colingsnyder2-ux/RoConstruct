// from server: 98% by atomic.potato
struct RBX_SelectionBox {
    void* vtable0;
    void* vtable4;
    char pad8[0x10];
    void* vtable18;
    void* vtable1c;
    char pad20[0x60];
    void* vtable80;
    void* vtable84;
    RBX_SelectionBox();
};

extern "C" void __fastcall sub_8dabe0(RBX_SelectionBox* self, void* a);

RBX_SelectionBox::RBX_SelectionBox() {
    sub_8dabe0(this, (void*)0xbea2d4);
    vtable0 = (void*)0xbea404;
    vtable4 = (void*)0xbea3f8;
    vtable18 = (void*)0xbea3ec;
    vtable1c = (void*)0xbea3e0;
    vtable80 = (void*)0xbea3d0;
    vtable84 = (void*)0xbea3a4;
}
