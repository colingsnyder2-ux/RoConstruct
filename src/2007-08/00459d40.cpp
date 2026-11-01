// from server: 31% by colin
struct VTableArgs {
    void* vtable;
    char pad[4];
    void* field8;
    void* fieldC;
};

struct TextureManagerVTableArgs {
    void* vtable;
    char pad[4];
    void* field8;
    void* fieldC;
    void init();
};

extern "C" void __cdecl sub_459700(void*);

void TextureManagerVTableArgs::init() {
    field8 = (void*)0x793624;
    sub_459700((char*)this + 8);
    vtable = (void*)0x7931b4;
}
