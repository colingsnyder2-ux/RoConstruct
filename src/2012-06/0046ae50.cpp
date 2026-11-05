// from server: 74% by atomic.potato
extern "C" void __stdcall UpdateShadowMode(void *, int);

struct S {
    void Set(unsigned char value);
};

void S::Set(unsigned char value)
{
    if (value != *((unsigned char *)this + 0xfc)) {
        *((unsigned char *)this + 0xfc) = value;
        UpdateShadowMode((char *)this + 0x144, 0xe19b34);
    }
}
