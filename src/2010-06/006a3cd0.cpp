// from server: 75% by atomic.potato
struct S
{
    char pad0[36];
    void clear();
    int value40;
    int value44;
};

void S::clear()
{
    clear();
    value40 = 0;
    value44 = 0;
}
