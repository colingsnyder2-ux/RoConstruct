// roc 2012-06 00a30520  unit: CXTPReportHyperlinks  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a30520
//
// 00a30520  c7012404c200         mov dword ptr [ecx], 0xc20424
// 00a30526  e94127f5ff           jmp 0x982c6c
// auto-matched from its assembly shape

struct B_func_00a30520 { virtual ~B_func_00a30520(); };
struct S_func_00a30520 : B_func_00a30520 { ~S_func_00a30520(); };
S_func_00a30520::~S_func_00a30520()
{
}
