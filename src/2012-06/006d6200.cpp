// from server: 53% by colin
struct Vtoo_many_args {
    void* vtable0;
    char pad[0x10];
    void* vtable14;
    void* field18;
    void destroy();
};

extern "C" void __stdcall sub_982114(void*);
extern "C" void __stdcall sub_b229d8();

void Vtoo_many_args::destroy()
{
    *(void**)this = (void*)0xb98fcc;
    *(void**)((char*)this + 0x14) = (void*)0xb98fc4;
    *(void**)((char*)this + 0x14) = (void*)0xb43e60;
    void* p = *(void**)((char*)this + 0x18);
    if (p) {
        void** vt = *(void***)p;
        void (*fn)(void*) = (void (*)(void*))vt[4];
        fn(p);
    }
    sub_b229d8();
    if (*(unsigned char*)((char*)this + 8) & 1) {
        sub_982114(this);
    }
}
