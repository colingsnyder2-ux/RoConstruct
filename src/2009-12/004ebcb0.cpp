// from server: 33% by atomic.potato
struct S
{
    int value;
    int stride;
    int reserved8;
    int reservedC;
    int* data;
    int* f(int, int);
};

int* S::f(int index, int offset)
{
    int base = value;
    int position = index * stride + offset;
    return data + position * 2;
}
