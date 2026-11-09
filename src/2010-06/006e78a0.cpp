// from server: 75% by atomic.potato
struct S_func_006e78a0 {
    void SetImpl(int a1);
};

extern "C" void __stdcall func_006e7840(int a1);

void S_func_006e78a0::SetImpl(int a1)
{
    if (a1)
        *(int *)((char *)this + 0x98) = (int)0x00a36958;
    func_006e7840(a1);
    *(int *)((char *)this + 0xa0) = 0;
}
