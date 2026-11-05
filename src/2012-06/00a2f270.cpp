// roc 2012-06 00a2f270  unit: CXTPReportInplaceList  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2f270
//
// 00a2f270  c7011c00c200         mov dword ptr [ecx], 0xc2001c
// 00a2f276  e9f139f5ff           jmp 0x982c6c
// auto-matched from its assembly shape

struct B_func_00a2f270 { virtual ~B_func_00a2f270(); };
struct S_func_00a2f270 : B_func_00a2f270 { ~S_func_00a2f270(); };
S_func_00a2f270::~S_func_00a2f270()
{
}
