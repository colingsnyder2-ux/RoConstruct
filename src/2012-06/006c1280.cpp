// from server: 100% by Xemicl
// roc 2012-06 006c1280  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c1280
//
// 006c1280  64a100000000         mov eax, dword ptr fs:[0]
// 006c1286  6aff                 push -1
// 006c1288  68ce9aab00           push 0xab9ace
// 006c128d  50                   push eax
// 006c128e  b801000000           mov eax, 1
// 006c1293  64892500000000       mov dword ptr fs:[0], esp
// 006c129a  840548e2e200         test byte ptr [0xe2e248], al
// 006c12a0  7536                 jne 0x6c12d8
// 006c12a2  090548e2e200         or dword ptr [0xe2e248], eax
// 006c12a8  6a00                 push 0
// 006c12aa  685469b900           push 0xb96954
// 006c12af  b92ce2e200           mov ecx, 0xe2e22c
// 006c12b4  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c12bc  e86fe3ffff           call 0x6bf630
// 006c12c1  68c065b100           push 0xb165c0
// 006c12c6  c7052ce2e200b068b900 mov dword ptr [0xe2e22c], 0xb968b0
// 006c12d0  e8201f2c00           call 0x9831f5
// 006c12d5  83c404               add esp, 4
// 006c12d8  8b0c24               mov ecx, dword ptr [esp]
// 006c12db  b82ce2e200           mov eax, 0xe2e22c
// 006c12e0  64890d00000000       mov dword ptr fs:[0], ecx
// 006c12e7  83c40c               add esp, 0xc
// 006c12ea  c3                   ret 
// copied from an identical function in another client (function ??$singleton@H@Type@Reflection@RBX@@SAABV012@XZ)

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
const Type& Type::singleton<int>()
{
	static TypeImpl<int> type("int");
	return type;
}
}
}