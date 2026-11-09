// from server: 100% by atomic.potato
extern int g_00b3bf0c;

struct DataModel
{
    unsigned char f(int, int);
};

unsigned char DataModel::f(int a, int b)
{
    int x = g_00b3bf0c * 9 + *(int *)((char *)a + 0x1c8);
    x = x * 9 + *(int *)((char *)b + 0x1c8);
    return *((unsigned char *)((char *)this + x + 0x838));
}
