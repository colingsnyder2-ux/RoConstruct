// roc 2012-06 00743d60  unit: boost::bad_lexical_cast  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00743d60
//
// 00743d60  c7017ca8ba00         mov dword ptr [ecx], 0xbaa87c
// 00743d66  ff25242ab200         jmp dword ptr [0xb22a24]
// auto-matched from its assembly shape

struct __declspec(dllimport) B_func_00743d60 { virtual ~B_func_00743d60(); };
struct S_func_00743d60 : B_func_00743d60 { ~S_func_00743d60(); };
S_func_00743d60::~S_func_00743d60()
{
}
