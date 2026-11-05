// from server: 87% by atomic.potato
struct S
{
    S(int);
    int padding[7];
};

extern "C" void initialize();
extern "C" void setValue(S *, int);

S::S(int value)
{
    initialize();
    padding[0] = 0xabcf1c;
    padding[7] = 0xabcefc;
    setValue(this, value);
}
