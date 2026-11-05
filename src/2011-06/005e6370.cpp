// from server: 100% by atomic.potato
struct S
{
    unsigned char value;
    void set(unsigned char);
};

void S::set(unsigned char value)
{
    *((unsigned char*)this + 0xc64) = value;
}
