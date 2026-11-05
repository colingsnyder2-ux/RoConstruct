// from server: 100% by atomic.potato
extern "C" void __stdcall func_00411f60(unsigned int);

struct BoundFuncDesc
{
    void set(unsigned char value);
};

void BoundFuncDesc::set(unsigned char value)
{
    if (value != *(unsigned char *)((char *)this + 0x96))
    {
        *(unsigned char *)((char *)this + 0x96) = value;
        func_00411f60(0x00cd4b90);
    }
}
