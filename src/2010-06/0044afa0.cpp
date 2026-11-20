// from server: 100% by Intel_Inside
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// target: 0044afa0  setErrorReporting  (34 B)  offset 0xf4
#pragma pack(push, 1)
struct DebugSettings {
    unsigned char _pad[0xb8];
    int errorReporting;
    void setErrorReporting(int value);
};
#pragma pack(pop)

static int prop_errorReporting;

void __stdcall raisePropertyNameChanged(int* p);

void __thiscall DebugSettings::setErrorReporting(int value)
{
    if (value != errorReporting)
    {
        errorReporting = value;
        raisePropertyNameChanged(&prop_errorReporting);
    }
}