// from server: 100% by Intel
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /MD /GS /EHsc
struct CXTPControls {
    char pad[0x40];
    CXTPControls();
    ~CXTPControls();
};

CXTPControls* __cdecl sub_67d170()
{
    return new CXTPControls;
}
