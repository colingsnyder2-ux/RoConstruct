// roc 2012-06 007b9080  unit: RBX::Geometry  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b9080
//
// 007b9080  c70148a3bb00         mov dword ptr [ecx], 0xbba348
// 007b9086  e9a5cd1400           jmp 0x905e30
// auto-matched from its assembly shape

struct B_func_007b9080 { virtual ~B_func_007b9080(); };
struct S_func_007b9080 : B_func_007b9080 { ~S_func_007b9080(); };
S_func_007b9080::~S_func_007b9080()
{
}
