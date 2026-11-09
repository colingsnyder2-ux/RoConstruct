// from server: 63% by atomic.potato
extern "C" int sub_759240(int);

struct S
{
    int f(int);
};

S* g_object = 0;
unsigned char g_flag;

int S::f(int value)
{
    if (g_flag)
        return 0;

    int* p = *(int**)((char*)this + 0x84);
    return sub_759240((int)((char*)this + 0x84 + *p));
}
