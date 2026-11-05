// from server: 46% by atomic.potato
struct Geometry
{
    int GetValue();
};

int Geometry::GetValue()
{
    int value = *(int*)((char*)this + 0x90);
    if (value == 0)
        return 1;
    if (--value == 0)
        return 5;
    if (--value != 0)
        return 1;
    return 20;
}
