// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0x00773710 = CXTPPropertyGridInplaceEdit::SetValue (vtable slot +0x160): `add ecx,0x8c ; jmp [mfc90 #820]`
// (m_strValue = value). aliases_bytealias.txt bound it to boost::thread_resource_error::~thread_resource_error (same
// length, different first instruction), so opening a property-grid editor reset the edit's vptr to std::exception and
// the next Create call jumped into d3d11 -> crash editing a property (gridedit.py row 8).
// INFERRED: owning class layout beyond the CString at +0x8c is not needed; padding stands in for it.
#include <afx.h>
struct Th_00773710
{
    char pad[0x8c];
    CString m_strValue;
    void SetValue(const char* v) { m_strValue = v; }
};
void (Th_00773710::*keep_00773710)(const char*) = &Th_00773710::SetValue;
