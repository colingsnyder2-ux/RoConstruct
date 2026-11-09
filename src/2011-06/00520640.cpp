// from server: 100% by atomic.potato
struct S
{
    int *data;
    unsigned int begin;
    unsigned int unused;
    unsigned int end;
    int *f(unsigned int offset);
};

int *S::f(unsigned int offset)
{
    unsigned int index = begin + offset;
    if (index >= end)
        return data + (begin - end + offset);

    return data + index;
}
