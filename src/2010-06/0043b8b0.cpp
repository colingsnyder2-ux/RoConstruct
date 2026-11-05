// from server: 84% by atomic.potato
struct Vector3ComponentItem
{
    int f(int, int);
    int pad[76];
};

int Vector3ComponentItem::f(int a, int b)
{
    int x = pad[75];
    x += x;
    x += x;
    return *(float *)(a + x) == *(float *)(b + x);
}
