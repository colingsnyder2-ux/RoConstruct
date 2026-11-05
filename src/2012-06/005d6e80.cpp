// from server: 49% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl func_00972290(int, char*);
extern "C" void* __cdecl func_005d6ce0(void*);

extern char G_e580b3;
extern int G_e275d8;
extern int G_e5809c;
extern char G_b42f90;
extern char G_b42fa8;
extern char G_b432f8;

struct RefCounted
{
    void* vptr;
    long refcount;
};

struct Obj
{
    void* vptr;
    long refcount;
    long refcount2;
};

struct Result
{
    void* ptr;
    void* ref;
};

void* __cdecl func_005d6e80(Result* out)
{
    if (G_e580b3 != 0 && G_e275d8 != 0x29a)
    {
        if (G_e5809c != 0)
        {
            char r = ((char (__cdecl*)(int, char*, char*))G_e5809c)(0xca, &G_b42f90, &G_b42fa8);
            if (r == 0)
            {
                func_00972290(G_e580b3, &G_b432f8);
            }
        }
        else
        {
            func_00972290(G_e580b3, &G_b432f8);
        }
    }

    void* tmp = 0;
    void* r = func_005d6ce0(&tmp);
    void* p = *(void**)r;
    if (p != 0)
        p = (char*)p + 0x18;
    else
        p = 0;
    out->ptr = p;
    void* ref = *(void**)((char*)r + 4);
    out->ref = ref;
    if (ref != 0)
    {
        _InterlockedExchangeAdd((volatile long*)((char*)ref + 4), 1);
    }

    void* esi = tmp;
    if (esi != 0)
    {
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1)
        {
            void* vt = *(void**)esi;
            ((void (__cdecl*)(void*))*(void**)((char*)vt + 4))(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1)
            {
                void* vt2 = *(void**)esi;
                ((void (__cdecl*)(void*))*(void**)((char*)vt2 + 8))(esi);
            }
        }
    }

    return out;
}
