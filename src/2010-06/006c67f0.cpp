// from server: 58% by atomic.potato
struct ForceField {
    char pad_0[0x94];
    void* f_94;
    int f_98;
    int f_9c;
    int f_a0;
    int f_a4;
    void ctor();
};

extern "C" void __stdcall sub_6c6780();
extern "C" void __stdcall sub_9ea410();
extern "C" void __stdcall sub_9ea400();
extern "C" void __stdcall sub_598aa0();

struct Str {
    char buf[0x1c];
    Str(const char*);
    ~Str();
};

void ForceField::ctor() {
    sub_6c6780();
    f_98 = -1;
    f_9c = -1;
    f_a0 = 0;
    f_94 = (void*)0xa44b64;
    f_a4 = 0;
    *(void**)this = (void*)0xa44b9c;
    *(void**)((char*)this + 4) = (void*)0xa44b94;
    *(void**)((char*)this + 0x18) = (void*)0xa44b88;
    *(void**)((char*)this + 0x1c) = (void*)0xa44b7c;
    Str s("ForceField");
    sub_598aa0();
    s.~Str();
}
