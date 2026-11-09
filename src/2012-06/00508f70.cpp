// from server: 60% by atomic.potato
struct S_func_00508f70 {
    void* vtable;
    void* field_4;
    S_func_00508f70* ctor(unsigned int flags);
};

extern "C" void __stdcall sub_00982114(void* p);

S_func_00508f70* S_func_00508f70::ctor(unsigned int flags)
{
    this->vtable = (void*)0xb6b8ec;
    void* p = (char*)this + 4;
    if (p) {
        this->field_4 = (char*)p - 4;
    } else {
        this->field_4 = 0;
    }
    this->vtable = *(void**)0xb23998;
    if (flags & 1) {
        sub_00982114(this);
    }
    return this;
}
