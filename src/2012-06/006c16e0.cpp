// from server: 100% by Xemicl
// roc 2012-06 006c16e0  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c16e0
//
// 006c16e0  64a100000000         mov eax, dword ptr fs:[0]
// 006c16e6  6aff                 push -1
// 006c16e8  680e9cab00           push 0xab9c0e
// 006c16ed  50                   push eax
// 006c16ee  b801000000           mov eax, 1
// 006c16f3  64892500000000       mov dword ptr fs:[0], esp
// 006c16fa  840588e3e200         test byte ptr [0xe2e388], al
// 006c1700  7536                 jne 0x6c1738
// 006c1702  090588e3e200         or dword ptr [0xe2e388], eax
// 006c1708  6a00                 push 0
// 006c170a  689069b900           push 0xb96990
// 006c170f  b96ce3e200           mov ecx, 0xe2e36c
// 006c1714  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c171c  e82fe7ffff           call 0x6bfe50
// 006c1721  686066b100           push 0xb16660
// 006c1726  c7056ce3e2000069b900 mov dword ptr [0xe2e36c], 0xb96900
// 006c1730  e8c01a2c00           call 0x9831f5
// 006c1735  83c404               add esp, 4
// 006c1738  8b0c24               mov ecx, dword ptr [esp]
// 006c173b  b86ce3e200           mov eax, 0xe2e36c
// 006c1740  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1747  83c40c               add esp, 0xc
// 006c174a  c3                   ret 
// copied from an identical function in another client (function ??$singleton@VTuple@Reflection@RBX@@@Type@Reflection@RBX@@SAABV012@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost { template<class T> class shared_ptr; }
namespace RBX { namespace Reflection {
class DescribedBase;
class Tuple;
class Type {
public:
	template<class T> Type(const char* name, T* dummy);
	virtual ~Type();
	template<class T> static const Type& singleton();
};
template<class T> class TType : public Type {
public:
	TType(const char* name) : Type(name, (T*)0) {}
	virtual ~TType() {}
};
template<> const Type& Type::singleton<Tuple>()
{
	static TType<Tuple> type("Tuple");
	return type;
}
}}