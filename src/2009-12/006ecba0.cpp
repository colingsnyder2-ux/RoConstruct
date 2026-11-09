// from server: 100% by atomic.potato
struct Primitive
{
    int GetValue();
    int padding[38];
    int value;
    int count;
};

int Primitive::GetValue()
{
    if (count > 0)
        return *reinterpret_cast<int *>(value);
    return 0;
}
