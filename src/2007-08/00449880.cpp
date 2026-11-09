// from server: 100% by colin
// roc 2007-08 00449880  unit: CRobloxModule  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00449880

extern "C" void* __cdecl sub_6307AE();
extern "C" void* __cdecl sub_62FF02();

struct CRobloxModule {
    int getField34();
};

int CRobloxModule::getField34()
{
    sub_6307AE();
    void* p = sub_62FF02();
    return *(int*)((char*)p + 0x34);
}
