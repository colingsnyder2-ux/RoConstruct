// from server: 94% by atomic.potato
struct Primitive
{
    int GetValue();
    int pad20[38];
    int value98;
    int count9c;
    int padA0[4];
    int valueB4;
    int countB8;
};

int Primitive::GetValue()
{
    if (countB8 > 0)
        return *(int *)valueB4;
    if (count9c > 0)
        return *(int *)value98;
    return 0;
}
