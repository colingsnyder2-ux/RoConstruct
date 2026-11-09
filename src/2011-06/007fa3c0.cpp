// from server: 69% by atomic.potato
typedef void *HANDLE;

extern "C" int __fastcall release_object(void *);
extern "C" void __cdecl destroy_object(void *);
extern "C" int __stdcall CloseHandle(HANDLE);

struct S
{
    void f();
};

void S::f()
{
    void *p = *(void **)((char *)this + 0xc);
    if (p)
    {
        release_object((char *)p + 8);
        HANDLE h = *(HANDLE *)((char *)p + 4);
        *(HANDLE *)((char *)p + 4) = 0;
        if (h)
            CloseHandle(h);
        destroy_object(p);
    }
}
