// from server: 52% by atomic.potato
struct S {
    char pad0[0x28];
    void* field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    S(void* arg);
};

struct T {
    void sub_409420(void* arg);
};

S::S(void* arg) {
    ((T*)this)->sub_409420(arg);
    field28 = (void*)0x99fdd8;
    field2c = 0;
    field30 = 0;
    field34 = 0;
    field38 = -1;
    *(void**)this = (void*)0x99ff04;
    field28 = (void*)0x99fefc;
}
