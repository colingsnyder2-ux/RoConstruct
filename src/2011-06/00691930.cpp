// from server: 87% by atomic.potato
struct S
{
    int value;
    int offset;

    unsigned char get(int p);
};

unsigned char S::get(int p)
{
    p = value;
    if (p)
        p -= 0x1c;
    else
        p = 0;

    int base = *reinterpret_cast<int *>(p + 0x94);
    int index = offset;
    int data = *reinterpret_cast<int *>(base + index);
    data += reinterpret_cast<int *>(this)[2];

    return *reinterpret_cast<unsigned char *>(data + p + 0x94);
}
