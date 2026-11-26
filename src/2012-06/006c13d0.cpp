// from server: 100% by Xemicl
// roc 2012-06 006c13d0  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c13d0
//
// 006c13d0  64a100000000         mov eax, dword ptr fs:[0]
// 006c13d6  6aff                 push -1
// 006c13d8  682e9bab00           push 0xab9b2e
// 006c13dd  50                   push eax
// 006c13de  b801000000           mov eax, 1
// 006c13e3  64892500000000       mov dword ptr fs:[0], esp
// 006c13ea  8405a8e2e200         test byte ptr [0xe2e2a8], al
// 006c13f0  7536                 jne 0x6c1428
// 006c13f2  0905a8e2e200         or dword ptr [0xe2e2a8], eax
// 006c13f8  6a00                 push 0
// 006c13fa  686869b900           push 0xb96968
// 006c13ff  b98ce2e200           mov ecx, 0xe2e28c
// 006c1404  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c140c  e88fe4ffff           call 0x6bf8a0
// 006c1411  68f065b100           push 0xb165f0
// 006c1416  c7058ce2e200c868b900 mov dword ptr [0xe2e28c], 0xb968c8
// 006c1420  e8d01d2c00           call 0x9831f5
// 006c1425  83c404               add esp, 4
// 006c1428  8b0c24               mov ecx, dword ptr [esp]
// 006c142b  b88ce2e200           mov eax, 0xe2e28c
// 006c1430  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1437  83c40c               add esp, 0xc
// 006c143a  c3                   ret 
// copied from an identical function in another client (function ??$singleton@M@Type@Reflection@RBX@@SAABV012@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace boost { template<class T> class shared_ptr; }
namespace RBX {
class Instance;
class ContentId;
typedef const std::vector<boost::shared_ptr<Instance> > Instances;
namespace Reflection {
class Descriptor { public: virtual ~Descriptor() {} protected: Descriptor() {} };
class Type : public Descriptor { public: template<typename T> static const Type& singleton(); protected: Type() {} };
template<typename T> class TType : public Type { public: TType(const char* name, const char* tag); };
template<typename T> class TypeImpl : public TType<T> { public: TypeImpl(const char* name) : TType<T>(name, 0) {} virtual void dummy() const; };
template<>
const Type& Type::singleton<float>()
{
	static TypeImpl<float> type("float");
	return type;
}
}
}