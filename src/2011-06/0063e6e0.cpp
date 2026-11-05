// from server: 83% by atomic.potato
struct Inner {
    char pad[4];
    void* vtable;
    void (__thiscall *fn)(void*);
};

struct Outer {
    char pad[0xd0];
    void* field_d0;
    char pad2[0x14];
    Inner* field_e8;

    void method(void* arg);
};

extern "C" void __stdcall sub_58a840(void* field, void* arg);

void Outer::method(void* arg) {
    Inner* p = field_e8;
    void* vt = p->vtable;
    void (__thiscall *fn)(void*) = *(void (__thiscall **)(void*))((char*)vt + 0x10);
    fn(arg);
    sub_58a840(field_d0, arg);
}
