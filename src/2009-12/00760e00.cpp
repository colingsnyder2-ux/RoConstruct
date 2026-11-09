// from server: 75% by atomic.potato
struct P8PVInstance
{
    void SetImpl(void *value);
};

extern "C" void __stdcall sub_00760da0(P8PVInstance *, void *);

void P8PVInstance::SetImpl(void *value)
{
    if (value != 0)
        *(int *)((char *)this + 0x98) = 0x9d01d0;
    sub_00760da0(this, value);
    *(int *)((char *)this + 0xa0) = 0;
}
