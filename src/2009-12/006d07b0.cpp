// from server: 52% by atomic.potato
extern "C" void __cdecl sub_0040C080(float);

struct SeatImpl
{
    void f(float);
};

void SeatImpl::f(float value)
{
    if (!(value == *(float *)((char *)this + 0x178)))
    {
        *(float *)((char *)this + 0x178) = value;
        sub_0040C080(*(float *)0x00B927C8);
    }
}
