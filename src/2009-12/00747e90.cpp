// from server: 96% by atomic.potato
struct Handles
{
    int f(int a, int b);
    char pad[4];
    int x;
    int y;
};

extern bool func_00759970(int* p);

int Handles::f(int a, int b)
{
    int tmp[2];
    tmp[0] = a;
    tmp[1] = b;
    if (!func_00759970(tmp))
    {
        int* p = (int*)((char*)this + 8);
        if (p != 0)
        {
            p[0] = tmp[0];
            p[1] = tmp[1];
        }
        *(int*)this = 0xb57154;
        return 0;
    }
    *(int*)this = 0;
    return 0;
}
