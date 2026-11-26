// from server: 100% by Xemicl
// roc 2012-06 006c12f0  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c12f0
//
// 006c12f0  64a100000000         mov eax, dword ptr fs:[0]
// 006c12f6  6aff                 push -1
// 006c12f8  68ee9aab00           push 0xab9aee
// 006c12fd  50                   push eax
// 006c12fe  b801000000           mov eax, 1
// 006c1303  64892500000000       mov dword ptr fs:[0], esp
// 006c130a  840568e2e200         test byte ptr [0xe2e268], al
// 006c1310  7536                 jne 0x6c1348
// 006c1312  090568e2e200         or dword ptr [0xe2e268], eax
// 006c1318  6a00                 push 0
// 006c131a  685869b900           push 0xb96958
// 006c131f  b94ce2e200           mov ecx, 0xe2e24c
// 006c1324  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c132c  e8cfe3ffff           call 0x6bf700
// 006c1331  68d065b100           push 0xb165d0
// 006c1336  c7054ce2e200b868b900 mov dword ptr [0xe2e24c], 0xb968b8
// 006c1340  e8b01e2c00           call 0x9831f5
// 006c1345  83c404               add esp, 4
// 006c1348  8b0c24               mov ecx, dword ptr [esp]
// 006c134b  b84ce2e200           mov eax, 0xe2e24c
// 006c1350  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1357  83c40c               add esp, 0xc
// 006c135a  c3                   ret 
// copied from an identical function in another client (function ??$singleton@V?$shared_ptr@VInstance@RBX@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ)

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
const Type& Type::singleton<boost::shared_ptr<Instance>>()
{
	static TypeImpl<boost::shared_ptr<Instance>> type("long");
	return type;
}
}
}