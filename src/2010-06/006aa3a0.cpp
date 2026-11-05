// from server: 65% by atomic.potato
struct PoolData {
    void* vtable;
    char pad1[4];
    char field8;
    char pad2[4];
    void* dtor(char);
};

extern "C" void __stdcall sub_795310();
extern "C" void __stdcall sub_7a799a(void*);

void* PoolData::dtor(char flag) {
    this->vtable = (void*)0xa41218;
    sub_795310();
    sub_795310();
    if (flag & 1) {
        sub_7a799a(this);
    }
    return this;
}
