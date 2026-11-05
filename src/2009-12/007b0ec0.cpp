// from server: 100% by atomic.potato
int g_00B633EC;

struct Ball
{
    char padding[0x98];
    int value;

    void setValue();
};

void Ball::setValue()
{
    int value = ++g_00B633EC;
    if (value == 0x7fffffff)
    {
        value = 1;
        g_00B633EC = value;
    }
    this->value = value;
}
