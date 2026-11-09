// from server: 32% by colin
struct S {
    char pad[0x1c];
    void* field_1c;
    void f(char* arg);
};

struct T {
    char pad[0x1c];
    void* field_1c;
    char g(void* arg);
};

extern "C" {
    void __stdcall sub_77E6A4(void*);
    void __stdcall sub_77E69C(void*, void*);
    void __stdcall sub_77E6AC(void*);
    void* __cdecl sub_408740();
}

char T::g(void* arg) {
    return 0;
}

void S::f(char* arg) {
    char buf[0x50];
    char tmp[0x20];
    sub_77E6A4(buf);
    sub_77E69C(tmp, arg + 0x5c);
    *(void**)(tmp + 0x1c) = *(void**)(arg + 0x78);
    void* p = sub_408740();
    T* t = (T*)p;
    if (!t->g(tmp)) {
        sub_77E6AC(buf);
    }
}
