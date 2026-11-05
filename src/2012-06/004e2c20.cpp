// from server: 30% by atomic.potato
struct Ogre_TextureCompositor {
    void* vtable;
    char pad0[0x20];
    void* field24;
    char pad1[0x8];
    void* field30;
    char pad2[0x8];
    void* field3c;
    char pad3[0x10];
    void* field50;
    char pad4[0x4];
    char field58;
    void destroy();
};

extern "C" void __stdcall sub_4DF290(void*);
extern "C" void __stdcall sub_4E1290(void*);
extern "C" void __stdcall sub_4E25D0(void*);
extern "C" void __stdcall sub_4E2620(void*, void*, void*, void*);
extern "C" void __stdcall sub_982114(void*);
extern "C" void* __stdcall sub_B22E10();

void Ogre_TextureCompositor::destroy()
{
    this->vtable = (void*)0xB69794;
    void* rs = sub_B22E10();
    void* vt = *(void**)rs;
    void* fn = *(void**)((char*)vt + 0x1CC);
    ((void (__stdcall*)(void*, void*))fn)(rs, this);
    sub_4DF290((char*)this + 0x54);
    sub_4E25D0((char*)this + 0x40);
    void* a = this->field30;
    void* b = *(void**)a;
    sub_4E2620((char*)this + 0x30, (char*)this + 0x30, b, a);
    sub_982114(*(void**)((char*)this + 0x34));
    *(void**)((char*)this + 0x34) = 0;
    *(void**)((char*)this + 0x38) = 0;
    void* c = this->field24;
    void* d = *(void**)c;
    sub_4E2620((char*)this + 0x24, (char*)this + 0x24, d, c);
    sub_982114(*(void**)((char*)this + 0x28));
    *(void**)((char*)this + 0x28) = 0;
    *(void**)((char*)this + 0x2C) = 0;
    sub_4E1290((char*)this + 4);
    sub_982114(*(void**)((char*)this + 4));
    this->vtable = *(void**)0xB22EE4;
}
