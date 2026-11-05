// from server: 42% by atomic.potato
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) void* __stdcall HeapAlloc(void*, unsigned long, unsigned long);

struct Log {
    char pad0[4];
    int refcount;
    char pad1[0x10];
    char flag18;
};

extern "C" void __stdcall sub_4C3D30(Log*);
extern "C" void __cdecl sub_719A4A(void*, void*);

void* g_8AC938;
void* g_8EF978;

Log* __stdcall CreateLog()
{
    Log* p = (Log*)HeapAlloc(GetProcessHeap(), 0, 0x20);
    if (p == 0) {
        void* e[4];
        e[0] = &g_8AC938;
        sub_719A4A(e, (void*)0x979188);
    }
    sub_4C3D30(p);
    p->refcount += 1;
    *(void**)p = &g_8EF978;
    p->flag18 = 0;
    return p;
}
