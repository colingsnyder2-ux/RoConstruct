// from server: 45% by atomic.potato
struct EventDesc {
    char pad0[4];
    void sub_4C1670(int);
    void* sub_4C12F0(void*, void*);
    void* construct(void* a, void* b);
};

void* EventDesc::construct(void* a, void* b) {
    char pad[4];
    *(int*)pad = 0;
    sub_4C1670(1);
    return sub_4C12F0(a, b);
}
