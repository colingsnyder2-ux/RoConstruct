// from server: 70% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct UString_sink_stream_buffer
{
    void* field0;
    void* field4;
    char field8;
    void assign(void* src);
};

void UString_sink_stream_buffer::assign(void* src)
{
    if (field8)
    {
        if (field4)
        {
            volatile long* p = (volatile long*)((char*)field4 + 4);
            if (_InterlockedExchangeAdd(p, -1) == 1)
            {
                void** vtbl = *(void***)field4;
                void (*fn)(void*) = (void (*)(void*))vtbl[1];
                fn(field4);
                volatile long* p2 = (volatile long*)((char*)field4 + 8);
                if (_InterlockedExchangeAdd(p2, -1) == 1)
                {
                    void** vtbl2 = *(void***)field4;
                    void (*fn2)(void*) = (void (*)(void*))vtbl2[2];
                    fn2(field4);
                }
            }
        }
        field8 = 0;
    }
    void** s = (void**)src;
    field0 = s[0];
    field4 = s[1];
    if (field4)
    {
        volatile long* p3 = (volatile long*)((char*)field4 + 4);
        _InterlockedExchangeAdd(p3, 1);
    }
    field8 = 1;
}
