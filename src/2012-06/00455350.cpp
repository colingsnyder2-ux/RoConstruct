// from server: 36% by atomic.potato
extern "C" {
    int __stdcall sub_7462C0(char*, const char*);
    void* __stdcall sub_B22640();
    void __stdcall sub_B247C8(void*, const char*);
    void __stdcall sub_B2263C(void*);
}

struct S {
    void f(char*);
};

void S::f(char* a) {
    char buf[28];
    sub_7462C0(buf, a);
    void* p = sub_B22640();
    sub_B247C8(p, buf);
    (*(void(__thiscall**)(S*))((*(int*)this) + 0x60))(this);
    sub_B2263C(buf);
}
