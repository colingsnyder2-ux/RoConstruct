// from server: 66% by atomic.potato
struct S
{
    int Get(int index);
};

int S::Get(int index)
{
    if (index >= 0 && index <= 2)
        return ((*reinterpret_cast<unsigned int *>(this)) & (1u << index)) != 0;
    return 0;
}
