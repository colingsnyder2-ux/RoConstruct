// from server: 100% by colin
struct CXTPControlGallery
{
    char pad[0x218];
    void *field_218;
    void Cleanup();
};

extern "C" void __stdcall sub_63C4A0(unsigned int);
extern "C" void __stdcall sub_63C510();

void CXTPControlGallery::Cleanup()
{
    if (field_218 != 0)
    {
        sub_63C4A0(0x1012);
        field_218 = 0;
    }
    ((void (__thiscall *)(CXTPControlGallery *))sub_63C510)(this);
}
