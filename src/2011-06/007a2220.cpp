// from server: 100% by atomic.potato
struct S
{
    int pad0[3];
    S** items;
    int count;
    int pad1[7];
    int value;
    void f(int);
};

void S::f(int value)
{
    int i = 0;
    this->value = value;
    if (count > 0)
    {
        do
        {
            items[i]->f(value);
            ++i;
        } while (i < count);
    }
}
