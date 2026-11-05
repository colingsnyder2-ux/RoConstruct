// from server: 100% by atomic.potato
extern "C" void __stdcall Dispatch(unsigned int value);

struct RefPropDescriptor
{
    void target(unsigned char value);
};

void RefPropDescriptor::target(unsigned char value)
{
    if (*((unsigned char *)this + 0x398) == value)
        return;

    *((unsigned char *)this + 0x398) = value;
    Dispatch(0xC20900);
}
