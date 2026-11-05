// from server: 47% by atomic.potato
struct S
{
    void f();
    int pad0[7];
    int member;
};

extern "C" void __cdecl helper(int*, int);

void S::f()
{
    helper(&member, *(int *)((char *)this->member + 0xacc));
}
