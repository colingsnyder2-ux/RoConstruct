// from server: 100% by atomic.potato
struct CArray {
    char pad[8];
    int size;
    void InsertAt(int index, const void* value);
};

extern CArray g_array;
extern int g_count;

void func(int a, int b, int c)
{
    int tmp[3];
    tmp[0] = a;
    tmp[1] = b;
    tmp[2] = c;
    g_array.InsertAt(g_count, tmp);
}
