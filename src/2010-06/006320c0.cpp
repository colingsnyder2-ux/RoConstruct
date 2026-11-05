// from server: 100% by atomic.potato
struct S {
    S* func(int flags);
};

extern "C" void sub_599c50();
extern "C" void sub_7a799a(void*);

S* S::func(int flags) {
    *(int*)0xc01be8 = 0;
    *(int*)this = 0xa35b7c;
    *(int*)((char*)this + 4) = 0xa35b74;
    *(int*)((char*)this + 0x18) = 0xa35b68;
    *(int*)((char*)this + 0x1c) = 0xa35b5c;
    sub_599c50();
    if (flags & 1) {
        sub_7a799a(this);
    }
    return this;
}
