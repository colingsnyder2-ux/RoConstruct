// from server: 53% by atomic.potato
struct Mouse
{
    void setData(const int* value);
};

void Mouse::setData(const int* value)
{
    int destination[7];
    for (int i = 0; i < 7; ++i)
        destination[i] = value[i];
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x80) = 0;
}
