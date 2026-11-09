// from server: 100% by atomic.potato
struct Geometry
{
    void SetValue(int index, int value);
};

void Geometry::SetValue(int index, int value)
{
    if (*(int*)((char*)this + 0x10c + index * 4) != value)
        *(int*)((char*)this + 0x10c + index * 4) = value;
}
