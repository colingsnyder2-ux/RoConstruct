// from server: 45% by atomic.potato
struct VPlayerEventDesc {
    char pad0[4];
    char pad1[4];
    void sub_4c1670(int);
    void* sub_4c1a60(void*, void*);
    void* construct(void*, void*);
};

void* VPlayerEventDesc::construct(void* a, void* b) {
    sub_4c1670(1);
    return sub_4c1a60(a, b);
}
