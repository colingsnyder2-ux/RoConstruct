// from server: 65% by atomic.potato
struct CVideoStream {
    char pad[0x24];
    char field_24;
    char pad2[0x98 - 0x25];
    void* field_98;
    int Stop();
};

int CVideoStream::Stop()
{
    field_24 = 0;
    void* p = field_98;
    if (p == 0)
        return 0x8004020a;
    int* vtbl = *(int**)p;
    int (__stdcall *fn)(void*) = (int (__stdcall *)(void*))vtbl[6];
    return fn(p);
}
