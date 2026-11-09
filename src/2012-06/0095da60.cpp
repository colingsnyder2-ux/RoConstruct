// from server: 63% by atomic.potato
struct Climbing
{
    int* state;
    Climbing(int* a);
};

extern "C" void sub_0095e600(Climbing*, int*, int*);

Climbing::Climbing(int* a)
{
    int* b = a;
    sub_0095e600(this, b, a);
    state = (int*)0x00c042a0;
    *((int**)this + 1) = (int*)0x00c04294;
}
