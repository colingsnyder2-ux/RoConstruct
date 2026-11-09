// from server: 100% by atomic.potato
struct S {
    void* vtbl0;
    void* vtbl4;
    char pad[0x10];
    void* vtbl18;
    void* vtbl1c;
    S* dtor(char);
};

extern "C" void __cdecl sub_637b00();
extern "C" void __cdecl sub_7f385a(void*);

S* S::dtor(char flag) {
    this->vtbl0 = (void*)0x9d3134;
    this->vtbl4 = (void*)0x9d3128;
    this->vtbl18 = (void*)0x9d311c;
    this->vtbl1c = (void*)0x9d3114;
    sub_637b00();
    if (flag & 1) {
        sub_7f385a(this);
    }
    return this;
}
