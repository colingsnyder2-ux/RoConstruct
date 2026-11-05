// from server: 85% by atomic.potato
struct S
{
    char padding[36];
    void clear();
    char padding2[28];
    int value40;
    int value44;
};

void S::clear()
{
    clear();
    value40 = 0;
    value44 = 0;
}
