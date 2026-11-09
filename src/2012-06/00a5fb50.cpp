// roc 2012-06 00a5fb50  unit: CXTColorPageStandard  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a5fb50
//
// 00a5fb50  c701dc43c200         mov dword ptr [ecx], 0xc243dc
// 00a5fb56  e9255b9fff           jmp 0x455680
// auto-matched from its assembly shape

struct B_func_00a5fb50 { virtual ~B_func_00a5fb50(); };
struct S_func_00a5fb50 : B_func_00a5fb50 { ~S_func_00a5fb50(); };
S_func_00a5fb50::~S_func_00a5fb50()
{
}
