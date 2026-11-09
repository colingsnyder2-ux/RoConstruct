// from server: 7% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_9EA40C();
extern "C" void __stdcall sub_9EA400();

struct Inner
{
    void* v0;
    void* v1;
    void* v2;
    void* v3;
    void* v4;
    void* v5;
    void* v6;
    void* v7;
    void* v8;
};

struct Helper
{
    void Call(void* out, void* in);
};

struct Outer
{
    char pad0[0x1c];
    Inner* p1c;
    void Method(char* src);
};

void Outer::Method(char* src)
{
    Inner local;
    local.v0 = 0;
    local.v1 = 0;
    local.v2 = 0;
    local.v3 = 0;
    local.v4 = 0;
    local.v5 = 0;
    local.v6 = 0;
    local.v7 = 0;
    local.v8 = 0;

    sub_9EA40C();
    local.v7 = *(void**)(src + 0x1c);

    void* tmp = 0;
    ((Helper*)this)->Call(&tmp, &local);

    void* obj = tmp;
    void* vt = *(void**)obj;
    void* fn = *(void**)((char*)vt + 0x18);
    ((void (__stdcall*)(void*))fn)(obj);

    void* node = local.v0;
    void* next = *(void**)((char*)node + 8);
    if (next == 0)
        *(void**)((char*)node + 4) = obj;
    else
        *(void**)next = obj;
    *(void**)((char*)node + 8) = obj;

    if (tmp != 0)
    {
        if (_InterlockedExchangeAdd((volatile long*)((char*)tmp + 4), -1) == 1)
        {
            void* vt2 = *(void**)tmp;
            void* fn2 = *(void**)((char*)vt2 + 4);
            ((void (__stdcall*)(void*))fn2)(tmp);

            if (_InterlockedExchangeAdd((volatile long*)((char*)tmp + 8), -1) == 1)
            {
                void* vt3 = *(void**)tmp;
                void* fn3 = *(void**)((char*)vt3 + 8);
                ((void (__stdcall*)(void*))fn3)(tmp);
            }
        }
    }

    sub_9EA400();
}
