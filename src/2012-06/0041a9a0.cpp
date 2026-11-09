// from server: 100% by tajop
struct PasteVerb {
    void* field0;
    void release();
};

struct Inner {
    void sub_41a5e0();
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

extern "C" void* __cdecl sub_401970();

void PasteVerb::release()
{
    Inner* p = (Inner*)field0;
    if (p) {
        p->sub_41a5e0();
        void* q = sub_401970();
        EnterCriticalSection(q);
        *(void**)p = *(void**)((char*)q + 0x18);
        *(void**)((char*)q + 0x18) = p;
        LeaveCriticalSection(q);
    }
}
