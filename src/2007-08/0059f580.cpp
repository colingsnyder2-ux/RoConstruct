// from server: 70% by colin
// roc 2007-08 0059f580  unit: RBX::VBackpack::?$FactoryProduct  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0059f580

struct RBXName {
    void* p;
};

struct FactoryProduct {
    char pad[0x100];
    void* vtable0;
    void* vtable4;
    void* vtable10;
    void* vtable14;
    void* vtable2c;
    void* vtable44;
    void* vtable5c;
    void* vtable74;
    void* vtable8c;
    void* vtablee8;
    void* vtable120;
    void construct();
};

extern "C" {
    void __stdcall sub_77e698(void*);
    void __stdcall sub_77e6ac(void*);
}

void sub_541bf0(FactoryProduct* self, void* arg);

void FactoryProduct::construct()
{
    char buf[0x20];
    *(void**)((char*)this + 0) = (void*)0x7b3064;
    *(void**)((char*)this + 4) = (void*)0x7b3058;
    *(void**)((char*)this + 0x10) = (void*)0x7b3050;
    *(void**)((char*)this + 0x14) = (void*)0x7b3040;
    *(void**)((char*)this + 0x2c) = (void*)0x7b3030;
    *(void**)((char*)this + 0x44) = (void*)0x7b3020;
    *(void**)((char*)this + 0x5c) = (void*)0x7b3010;
    *(void**)((char*)this + 0x74) = (void*)0x7b3000;
    *(void**)((char*)this + 0x8c) = (void*)0x7b2ff0;
    *(void**)((char*)this + 0xe8) = (void*)0x7b2fe8;
    *(void**)((char*)this + 0x120) = (void*)0x7b2fd8;
    sub_77e698(buf);
    sub_541bf0(this, buf);
    sub_77e6ac(buf);
}
