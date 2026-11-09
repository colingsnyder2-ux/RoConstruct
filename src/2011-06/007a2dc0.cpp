// from server: 100% by atomic.potato
struct Body {
    void sub_7a2d10();
    Body* release(int);
};

extern "C" void (__stdcall *EnterCriticalSection)(void*);
extern "C" void (__stdcall *LeaveCriticalSection)(void*);
extern "C" void* __cdecl sub_6a51e0();

Body* Body::release(int flag)
{
    sub_7a2d10();
    if (flag & 1) {
        void* p = sub_6a51e0();
        EnterCriticalSection(p);
        *(Body**)this = *(Body**)((char*)p + 0x18);
        *(void**)((char*)p + 0x18) = this;
        LeaveCriticalSection(p);
    }
    return this;
}
