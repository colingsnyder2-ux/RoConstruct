// from server: 100% by king_originala
extern const unsigned char* source;
extern "C" int (__cdecl *copy_bytes)(
    unsigned char*, unsigned int, const unsigned char*, unsigned int);
extern "C" void __cdecl check_result(int);

struct VCContent_CComAggObject
{
    void Init();
    VCContent_CComAggObject* f();
};

VCContent_CComAggObject* VCContent_CComAggObject::f()
{
    Init();
    *(int*)((char*)this + 0x1228) = 2;
    *(int*)((char*)this + 0x122c) = 4;
    *(unsigned short*)((char*)this + 0x1226) = 0x50;
    check_result(copy_bytes((unsigned char*)this, 0x21, source, 4));
    return this;
}
