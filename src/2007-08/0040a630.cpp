// from server: 74% by Intel




struct CComObjectBase
{
    void __thiscall Cleanup(void* p);
};

extern "C" void __stdcall sub_429E00(void** pp);

int __stdcall func_0040A630(int arg)
{
    void* local[4];
    sub_429E00(&local[0]);
    CComObjectBase* obj = (CComObjectBase*)0x8BBE24;
    obj->Cleanup(local[0]);
    return 0;
}
