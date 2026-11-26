// from server: 100% by Xemicl
// roc 2012-06 006c14b0  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c14b0
//
// 006c14b0  64a100000000         mov eax, dword ptr fs:[0]
// 006c14b6  6aff                 push -1
// 006c14b8  686e9bab00           push 0xab9b6e
// 006c14bd  50                   push eax
// 006c14be  b801000000           mov eax, 1
// 006c14c3  64892500000000       mov dword ptr fs:[0], esp
// 006c14ca  8405e8e2e200         test byte ptr [0xe2e2e8], al
// 006c14d0  7536                 jne 0x6c1508
// 006c14d2  0905e8e2e200         or dword ptr [0xe2e2e8], eax
// 006c14d8  6a00                 push 0
// 006c14da  687869b900           push 0xb96978
// 006c14df  b9cce2e200           mov ecx, 0xe2e2cc
// 006c14e4  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c14ec  e84fe5ffff           call 0x6bfa40
// 006c14f1  681066b100           push 0xb16610
// 006c14f6  c705cce2e200d868b900 mov dword ptr [0xe2e2cc], 0xb968d8
// 006c1500  e8f01c2c00           call 0x9831f5
// 006c1505  83c404               add esp, 4
// 006c1508  8b0c24               mov ecx, dword ptr [esp]
// 006c150b  b8cce2e200           mov eax, 0xe2e2cc
// 006c1510  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1517  83c40c               add esp, 0xc
// 006c151a  c3                   ret 
// copied from an identical function in another client (function ??$singleton@VContentId@RBX@@@Type@Reflection@RBX@@SAABV012@XZ)

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
const Type& Type::singleton<ContentId>()
{
	static TypeImpl<ContentId> type("Content");
	return type;
}
}
}