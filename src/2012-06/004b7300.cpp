// from server: 55% by atomic.potato
struct CVideoStream {
    char pad0[0x1c];
    int (__stdcall *vtbl_call)(void*, int, int, int, int);
    char pad20[0x98 - 0x20];
    void* field98;
    int method(int, int, int, int);
};

int CVideoStream::method(int a, int b, int c, int d) {
    if (field98 == 0)
        return (int)0x80004002;
    void* p = field98;
    int (__stdcall *fn)(void*, int, int, int, int) = *(int (__stdcall **)(void*, int, int, int, int))((char*)p + 0x1c);
    return fn(p, a, b, c, d);
}
