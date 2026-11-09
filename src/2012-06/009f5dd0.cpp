// roc 2012-06 009f5dd0  unit: RBX::Kernel  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f5dd0
//
// 009f5dd0  c701f4a3c100         mov dword ptr [ecx], 0xc1a3f4
// 009f5dd6  e925f7ffff           jmp 0x9f5500
// auto-matched from its assembly shape

struct B_func_009f5dd0 { virtual ~B_func_009f5dd0(); };
struct S_func_009f5dd0 : B_func_009f5dd0 { ~S_func_009f5dd0(); };
S_func_009f5dd0::~S_func_009f5dd0()
{
}
