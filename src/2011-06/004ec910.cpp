// from server: 86% by colin
extern "C" void __stdcall sub_00C2EE8C(const char*, const char*, unsigned int);

struct GuidItemRegistry
{
    void assertValid() const;
};

void GuidItemRegistry::assertValid() const
{
    if (*(const unsigned char*)((const char*)this + 0x10) != 0)
    {
        if (*(const unsigned int*)((const char*)this + 4) > 0x800)
        {
            const char* p = *(const char**)((const char*)this + 0xc);
            sub_00C2EE8C(p, (const char*)0x00A7AE48, 0x81);
        }
    }
}
