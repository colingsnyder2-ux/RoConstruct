// from server: 100% by atomic.potato
extern "C" void __cdecl Function_007f44fc();
extern "C" void* __cdecl Function_007f3b1e();

struct CRobloxModule
{
    int Function();
};

int CRobloxModule::Function()
{
    Function_007f44fc();
    return *((int*)Function_007f3b1e() + 13);
}
