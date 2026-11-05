// from server: 96% by atomic.potato
extern "C" unsigned long __stdcall get_file_attributes(const char*);

struct S {
    char pad[0x1ac];
    unsigned long f();
};

unsigned long S::f() {
    return get_file_attributes((const char*)this + 0x1ac);
}
