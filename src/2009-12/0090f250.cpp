// from server: 59% by atomic.potato
struct S
{
    void f(unsigned char value, float number);
    unsigned char pad[0x74];
    unsigned char state;
    unsigned char pad2[3];
    float stored;
};

void S::f(unsigned char value, float number)
{
    if (state != value || stored != number)
    {
        state = value;
        stored = number;
    }
}
