// from server: 100% by atomic.potato
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

extern "C" void* __cdecl sub_006798D0();

struct RBX_Body {
    void sub_00751BD0();
    void* sub_00751C80(unsigned int flags);
};

void* RBX_Body::sub_00751C80(unsigned int flags) {
    sub_00751BD0();
    if (flags & 1) {
        void* p = sub_006798D0();
        EnterCriticalSection(p);
        *(void**)this = *(void**)((char*)p + 0x18);
        *(void**)((char*)p + 0x18) = this;
        LeaveCriticalSection(p);
    }
    return this;
}
