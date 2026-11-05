// from server: 70% by atomic.potato
struct SeatImpl
{
    int field168;
    void f();
};

extern "C" void* __cdecl sub_699860(SeatImpl*);
extern "C" void sub_71b4a0(void*, int);

void SeatImpl::f()
{
    void* p = sub_699860(this);
    if (p)
        sub_71b4a0(p, field168);
}
