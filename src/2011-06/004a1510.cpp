// from server: 72% by atomic.potato
struct CVideoStream {
    char pad[0x18];
    void* field_18;
    char pad2[0x44 - 0x1c];
    int (__stdcall *field_44)(void*, int, int, int, double);
    int method(int a, int b, int c, double d);
};

int CVideoStream::method(int a, int b, int c, double d) {
    if (field_18 == 0)
        return 0x80040209;
    return field_44(field_18, a, b, c, d);
}
