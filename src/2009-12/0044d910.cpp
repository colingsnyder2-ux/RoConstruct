// from server: 100% by atomic.potato
extern "C" void* __cdecl sub_7f44f6();
extern "C" void* __cdecl sub_7f3b1e();

struct CRobloxModule
{
    void* f();
};

void* CRobloxModule::f()
{
    sub_7f44f6();
    return *(void**)((char*)sub_7f3b1e() + 0x34);
}
