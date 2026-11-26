// from server: 100% by Xemicl
// roc 2012-06 006c1520  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c1520
//
// 006c1520  64a100000000         mov eax, dword ptr fs:[0]
// 006c1526  6aff                 push -1
// 006c1528  688e9bab00           push 0xab9b8e
// 006c152d  50                   push eax
// 006c152e  b801000000           mov eax, 1
// 006c1533  64892500000000       mov dword ptr fs:[0], esp
// 006c153a  840508e3e200         test byte ptr [0xe2e308], al
// 006c1540  7536                 jne 0x6c1578
// 006c1542  090508e3e200         or dword ptr [0xe2e308], eax
// 006c1548  6a00                 push 0
// 006c154a  687057b900           push 0xb95770
// 006c154f  b9ece2e200           mov ecx, 0xe2e2ec
// 006c1554  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c155c  e8afe5ffff           call 0x6bfb10
// 006c1561  682066b100           push 0xb16620
// 006c1566  c705ece2e200e068b900 mov dword ptr [0xe2e2ec], 0xb968e0
// 006c1570  e8801c2c00           call 0x9831f5
// 006c1575  83c404               add esp, 4
// 006c1578  8b0c24               mov ecx, dword ptr [esp]
// 006c157b  b8ece2e200           mov eax, 0xe2e2ec
// 006c1580  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1587  83c40c               add esp, 0xc
// 006c158a  c3                   ret 
// copied from an identical function in another client (function ??$singleton@V?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost { template<class T> class shared_ptr; }
namespace RBX { namespace Reflection {
class DescribedBase;
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
template<> const Type& Type::singleton<boost::shared_ptr<DescribedBase> >()
{
	static TType<std::string> type("string");
	return type;
}
}}