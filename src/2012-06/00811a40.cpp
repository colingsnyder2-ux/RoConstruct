// from server: 47% by atomic.potato
struct S
{
    int* a;
    int* b;
    int f(int* out, int* value);
};

int S::f(int* out, int* value)
{
    int* p = 0;
    if (value != 0)
        p = (int*)((char*)value - 28);
    int* r = (int*)((char*)b + (int)a);
    r = (int*)((char*)r + (int)p);
    out[0] = r[0];
    out[1] = r[1];
    out[2] = r[2];
    return (int)out;
}
