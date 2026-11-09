// from server: 92% by atomic.potato
struct RBX_BallPolyContact
{
    void* v0;
    RBX_BallPolyContact* construct(int);
};

extern "C" void __stdcall EnterCriticalSection_impl(void*);
extern "C" void __stdcall LeaveCriticalSection_impl(void*);
extern "C" void* __cdecl sub_713200();
extern "C" void __cdecl sub_78d910();

RBX_BallPolyContact* RBX_BallPolyContact::construct(int flag)
{
    sub_78d910();
    if (flag & 1)
    {
        void* p = sub_713200();
        EnterCriticalSection_impl(p);
        v0 = *(void**)((char*)p + 0x18);
        *(void**)((char*)p + 0x18) = this;
        LeaveCriticalSection_impl(p);
    }
    return this;
}
