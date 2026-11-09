// from server: 76% by atomic.potato
struct S
{
    int f(void*);
};

extern "C" void __stdcall call_411cb0(void*, void*);

int S::f(void* arg)
{
    call_411cb0(this, arg);
    *(int*)((char*)this + 0x3c) = 0xa00920;
    *(int*)this = 0xa02dac;
    *(int*)((char*)this + 0x28) = 0xa02da4;
    *(int*)((char*)this + 0x3c) = 0xa02d94;
    return (int)this;
}
