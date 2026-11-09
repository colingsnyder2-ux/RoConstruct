// from server: 56% by atomic.potato
typedef unsigned long DWORD;

extern "C" void CopySphere(void *destination, const void *source);

struct SphereFactory
{
    void *Copy(const void *value);
};

void *SphereFactory::Copy(const void *value)
{
    CopySphere(this, value);
    *(DWORD *)((char *)this + 0x24) = *(const DWORD *)((const char *)value);
    *(DWORD *)((char *)this + 0x28) = *(const DWORD *)((const char *)value + 4);
    *(DWORD *)((char *)this + 0x2c) = *(const DWORD *)((const char *)value + 8);
    return this;
}
