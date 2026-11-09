// from server: 71% by atomic.potato
struct BoundFuncDesc
{
    unsigned char value;
    void setValue(unsigned char value);
};

void BoundFuncDesc::setValue(unsigned char value)
{
    if (value != *(unsigned char *)((char *)this + 0xbc))
    {
        *(unsigned char *)((char *)this + 0xbc) = value;
        *(unsigned long *)((char *)this + 0xcd0588) = value;
    }
}
