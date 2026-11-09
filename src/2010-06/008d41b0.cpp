// from server: 97% by atomic.potato
struct S
{
    char pad0[8];
    char value;
    char pad9[11];
    char active;
    void reset();
    void f(char);
};

void S::f(char x)
{
    if (active != 0 && pad9[0] == 0 && x == value)
    {
        reset();
        active = 0;
    }
}
