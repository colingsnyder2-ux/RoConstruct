// from server: 83% by atomic.potato
struct Flag {
    char pad0[4];
    int* field4;
    int field8;
    void sub_8790d0(int*, int*, int*);
    void destroy();
    void func();
};

extern "C" void __stdcall sub_982114(int*);

void Flag::func() {
    int* p = field4;
    int v = *p;
    int tmp;
    sub_8790d0(&tmp, (int*)v, p);
    sub_982114(field4);
    field4 = 0;
    field8 = 0;
}
