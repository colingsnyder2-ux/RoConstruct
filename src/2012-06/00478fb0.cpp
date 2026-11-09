// from server: 82% by atomic.potato
struct S
{
    void f();
};

extern "C" int* g_table[];

void S::f()
{
    int index = *(int*)((char*)this + 0x180);
    if (index != -1)
    {
        *(int*)((char*)this + 0x188) = g_table[index * 3][0];
        *(unsigned char*)((char*)this + 0x184) = 1;
    }
}
