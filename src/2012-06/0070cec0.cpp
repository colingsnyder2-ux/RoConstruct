// from server: 85% by tester
struct PropDesc {
    void* vtable;
    int value;
    PropDesc* assign(int* other);
};

void __stdcall sub_9831f5(void*);

PropDesc* PropDesc::assign(int* other)
{
    static int initialized = 0;
    if (!(initialized & 1)) {
        initialized |= 1;
        *(int*)0xe313a4 = 0xdaabac;
        *(int*)0xe313ac = 0x5708d0;
        *(int*)0xe313a8 = 0x59a790;
        sub_9831f5((void*)0xb17350);
    }
    if (this->vtable == (void*)0xe313a4) {
        this->value = *other;
        return this;
    }
    if (this->vtable) {
        ((void (__stdcall*)(int*))((int*)this->vtable)[1])(&this->value);
        this->vtable = 0;
    }
    int* p = &this->value;
    if (p) {
        *p = *other;
    }
    this->vtable = (void*)0xe313a4;
    return this;
}
