// from server: 100% by colin
struct CRobloxModule {
    void sub_004498a0(int*);
};

void CRobloxModule::sub_004498a0(int* arg)
{
    void (__stdcall *fn)(int*, const char*, const char*);
    fn = *(void (__stdcall **)(int*, const char*, const char*))(*(int*)arg + 0xc);
    fn(arg, (const char*)0x79064c, (const char*)0x79efbc);
}
