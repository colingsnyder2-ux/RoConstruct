// from server: 68% by atomic.potato
struct S
{
    int pad0[10];
};

void f(S* a, S* b)
{
    a = (S*)((char*)a + 0x10);
    *((unsigned char*)b + 5) &= 0xfb;
    *(int*)((char*)b + 0x1c) = *(int*)((char*)a + 0x28);
    *(int*)((char*)a + 0x28) = (int)b;
}
