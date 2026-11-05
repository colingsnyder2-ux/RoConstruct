// from server: 41% by atomic.potato
struct S {
    int field0;
    int pad1[4];
    int v14;
    int v18;
    int v0();
};

extern "C" void destroy(void*);

int S::v0()
{
    field0 = 0xA91174;
    v14 = 0xA9116C;
    v14 = 0xA5BFDC;

    if (v18 != 0)
        destroy((void*)v18);

    return 0;
}
