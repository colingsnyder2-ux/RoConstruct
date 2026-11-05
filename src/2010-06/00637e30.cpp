// from server: 31% by atomic.potato
struct S {
    char pad[0x18];
    int (*fn)(void*, unsigned char);
    char pad2[0x4];
    int offset;
    char pad3[0x4];
    int index;
    int GetSetImpl(void* a, unsigned char* b);
};

int S::GetSetImpl(void* a, unsigned char* b) {
    char* p = (char*)a;
    if (p) p -= 0x1c;
    unsigned char c = *b;
    int idx = *(int*)(p + 0x98);
    int val = *(int*)(idx + index);
    val += offset;
    return fn((void*)(val + (int)p + 0x98), c);
}
