// from server: 74% by atomic.potato
struct S
{
    int value;
    void get(int* out, int* offset);
};

void S::get(int* out, int* offset)
{
    if (offset != 0)
        *out = *(int*)((char*)offset + value - 0x1c);
    else
        *out = *(int*)value;
}
