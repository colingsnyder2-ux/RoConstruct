// from server: 60% by colin
extern "C" void* __stdcall GetState();

struct CRobloxModule
{
    bool Check();
};

bool CRobloxModule::Check()
{
    if (GetState() != 0)
        return true;
    return false;
}
