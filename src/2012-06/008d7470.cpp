// from server: 100% by atomic.potato
extern "C" int g_bea024;
extern "C" int g_bea018;
extern "C" int g_bea00c;
extern "C" int g_bea000;
extern "C" int g_be9ff0;
extern "C" int g_be9fc4;

extern "C" void __cdecl sub_8d3420();

struct FactoryProduct
{
    void initialize();
};

void FactoryProduct::initialize()
{
    *(int*)((char*)this) = (int)&g_bea024;
    *(int*)((char*)this + 4) = (int)&g_bea018;
    *(int*)((char*)this + 0x18) = (int)&g_bea00c;
    *(int*)((char*)this + 0x1c) = (int)&g_bea000;
    *(int*)((char*)this + 0x80) = (int)&g_be9ff0;
    *(int*)((char*)this + 0x84) = (int)&g_be9fc4;
    sub_8d3420();
}
