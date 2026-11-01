// from server: 100% by colin
struct S_005fd7d0 {
    char pad[8];
    int offset8;
    int offsetc;
    unsigned char f(void* arg);
};

unsigned char S_005fd7d0::f(void* arg)
{
    char* p = (char*)arg;
    if (p != 0)
        p -= 0x14;
    else
        p = 0;
    int* table = *(int**)(p + 0x1c0);
    int idx = *(int*)((char*)this + 0xc);
    int off = *(int*)((char*)table + idx);
    off += *(int*)((char*)this + 8);
    return *(unsigned char*)(p + off + 0x1c0);
}
