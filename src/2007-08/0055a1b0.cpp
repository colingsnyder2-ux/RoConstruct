// from server: 75% by tajop
extern "C" void* __cdecl malloc(unsigned int size);
extern "C" void __cdecl free(void* p);

struct VLocalBackpack
{
    char pad[0x224];
    VLocalBackpack(int arg);
    static void* operator new(unsigned int size) { return malloc(size); }
    static void operator delete(void* p) { free(p); }
};

struct Deleter
{
};

struct SharedPtr
{
    VLocalBackpack* px;
    void* pn;
    SharedPtr(VLocalBackpack* p, Deleter d);
};

struct Creator
{
    static SharedPtr create();
};

SharedPtr Creator::create()
{
    return SharedPtr(new VLocalBackpack(1), Deleter());
}
