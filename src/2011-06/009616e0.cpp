// from server: 78% by atomic.potato
struct S_func_009616e0 {
    void* vtable;
    void* field_4;
    S_func_009616e0* f(unsigned int flags);
};

extern "C" void __cdecl sub_80a058(void*);

S_func_009616e0* S_func_009616e0::f(unsigned int flags)
{
    void** p = &this->field_4;
    this->vtable = (void*)0xaf78e4;
    if (p != 0) {
        *p = p - 1;
    }
    this->vtable = *(void**)0xa41050;
    if (flags & 1) {
        sub_80a058(this);
    }
    return this;
}
