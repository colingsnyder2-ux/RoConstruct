// from server: 100% by atomic.potato
extern "C" void __stdcall Notify(void *);

struct BoundFuncDesc
{
    unsigned char padding[0x2F4];
    unsigned char value;
    void Set(unsigned char);
};

void BoundFuncDesc::Set(unsigned char value)
{
    if (this->value != value)
    {
        this->value = value;
        Notify((void *)0x00CD02A0);
    }
}
