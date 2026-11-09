// from server: 76% by atomic.potato
struct CVideoStreamFilter {
    char pad[0x18];
    void* field_18;
    int field_20;
    int field_24;
    int method(int* arg);
};

int CVideoStreamFilter::method(int* arg)
{
    if (field_18 == 0)
        return 0x80040213;
    void* p = field_18;
    int* vtbl = *(int**)p;
    typedef int (__stdcall *Fn)(void*, int*);
    Fn fn = (Fn)vtbl[3];
    int hr = fn(p, arg);
    if (hr < 0)
        return hr;
    arg[0] -= field_20;
    arg[1] -= field_24;
    return 0;
}
