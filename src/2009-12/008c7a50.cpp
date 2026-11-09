// from server: 75% by atomic.potato
extern "C" int __cdecl G1_func_007f3b0c();

struct S
{
    int f(int);
    int *data;
    int size;
};

int S::f(int index)
{
    if (index >= 0 && index < size)
        return data[index];
    return G1_func_007f3b0c();
}
