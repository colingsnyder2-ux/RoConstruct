// roc 2012-06 009b9650  unit: CXTPReportRecordItemNumber  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b9650
//
// 009b9650  8b442408             mov eax, dword ptr [esp + 8]
// 009b9654  56                   push esi
// 009b9655  50                   push eax
// 009b9656  8bf1                 mov esi, ecx
// 009b9658  ff157c28b200         call dword ptr [0xb2287c]
// 009b965e  dd9e80000000         fstp qword ptr [esi + 0x80]
// 009b9664  83c404               add esp, 4
// 009b9667  5e                   pop esi
// 009b9668  c20800               ret 8
// copied from an identical function in another client (function ?SetValueDouble@CXTPReportRecordItemNumber@ns_ROCX000021@@QAEXPBD0@Z)

namespace ns_ROCX000021 {
extern "C" double (__cdecl* atof)(const char*);

struct CXTPReportRecordItemNumber
{
    char  gap0[0x80];
    double m_nValue;
    void SetValueDouble(const char* a, const char* b);
};

void CXTPReportRecordItemNumber::SetValueDouble(const char* a, const char* b)
{
    m_nValue = atof(b);
}
}
