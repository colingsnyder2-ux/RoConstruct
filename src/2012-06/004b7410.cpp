// from server: 75% by atomic.potato
struct CVideoStream {
    char pad[0x18];
    void* field_18;
    char pad2[0x44 - 0x1c];
    int (__stdcall *field_44)(void*, int, int, int, double);
};

int __stdcall CVideoStream_sub(CVideoStream* self, int a, int b, int c, double d) {
    if (self->field_18 == 0)
        return 0x80040209;
    void* p = self->field_18;
    int (__stdcall *fn)(void*, int, int, int, double) = *(int (__stdcall **)(void*, int, int, int, double))((char*)p + 0x44);
    return fn(p, a, b, c, d);
}
