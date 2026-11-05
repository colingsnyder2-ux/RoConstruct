// roc 2012-06 009c0fe0  unit: VCPtrList::?$CTypedPtrList  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c0fe0
//
// 009c0fe0  c701a41bc100         mov dword ptr [ecx], 0xc11ba4
// 009c0fe6  e9e5e6ffff           jmp 0x9bf6d0
// auto-matched from its assembly shape

struct B_func_009c0fe0 { virtual ~B_func_009c0fe0(); };
struct S_func_009c0fe0 : B_func_009c0fe0 { ~S_func_009c0fe0(); };
S_func_009c0fe0::~S_func_009c0fe0()
{
}
