// from server: 37% by atomic.potato
extern "C" {
    void __stdcall sub_00B2263C();
}

struct Inner {
    void* vtable;
};

struct Arg {
    char pad[0x20];
};

struct S {
    char pad[0x28];
    Inner* field_28;
    void method(Arg* a, Arg* b);
};

void __stdcall helper_790cf0(void* out, void* in);

void S::method(Arg* a, Arg* b) {
    Inner* inner = this->field_28;
    char tmp[0x20];
    helper_790cf0(tmp, a);
    void* vt = *(void**)inner;
    void (*fn)(Inner*, Arg*, void*) = *(void (**)(Inner*, Arg*, void*))((char*)vt + 0xc);
    fn(inner, b, tmp);
    sub_00B2263C();
}
