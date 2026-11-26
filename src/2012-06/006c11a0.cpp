// from server: 100% by Xemicl
// roc 2012-06 006c11a0  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c11a0
//
// 006c11a0  64a100000000         mov eax, dword ptr fs:[0]
// 006c11a6  6aff                 push -1
// 006c11a8  688e9aab00           push 0xab9a8e
// 006c11ad  50                   push eax
// 006c11ae  b801000000           mov eax, 1
// 006c11b3  64892500000000       mov dword ptr fs:[0], esp
// 006c11ba  840508e2e200         test byte ptr [0xe2e208], al
// 006c11c0  7536                 jne 0x6c11f8
// 006c11c2  090508e2e200         or dword ptr [0xe2e208], eax
// 006c11c8  6a00                 push 0
// 006c11ca  6860eeb800           push 0xb8ee60
// 006c11cf  b9ece1e200           mov ecx, 0xe2e1ec
// 006c11d4  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c11dc  e8afe2ffff           call 0x6bf490
// 006c11e1  68a065b100           push 0xb165a0
// 006c11e6  c705ece1e200a068b900 mov dword ptr [0xe2e1ec], 0xb968a0
// 006c11f0  e800202c00           call 0x9831f5
// 006c11f5  83c404               add esp, 4
// 006c11f8  8b0c24               mov ecx, dword ptr [esp]
// 006c11fb  b8ece1e200           mov eax, 0xe2e1ec
// 006c1200  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1207  83c40c               add esp, 0xc
// 006c120a  c3                   ret 
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
	static TypeImpl<boost::shared_ptr<Instance>> type("Instance");
	return type;
}
}
}