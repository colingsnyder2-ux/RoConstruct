// from server: 61% by atomic.potato
extern "C" {
    typedef void (__stdcall *fn0)(void*);
    typedef void (__stdcall *fn1)(void*);
}

struct String {
    char pad[0x1c];
    String(const char*);
    ~String();
};

struct Verb {
    void* vtbl;
    char pad[8];
    void* field_c;
};

extern "C" void* __stdcall sub_6FB8C0(void*, void*, void*);
extern "C" void* __stdcall sub_983448(void*, void*, void*, void*, void*);

struct ToggleFullscreenVerb {
    void* vtbl;
    char pad[8];
    void* field_c;
    ToggleFullscreenVerb* ctor(void*);
};

ToggleFullscreenVerb* ToggleFullscreenVerb::ctor(void* a) {
    String s("ToggleBackpackVisibility");
    void* local = this;
    sub_6FB8C0(this, a, &local);
    s.~String();
    this->vtbl = (void*)0xb5e404;
    this->field_c = sub_983448(a, (void*)0xd70598, (void*)0xd705b8, 0, 0);
    return this;
}
