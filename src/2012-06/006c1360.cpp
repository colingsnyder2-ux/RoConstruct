// from server: 100% by Xemicl
// roc 2012-06 006c1360  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c1360
//
// 006c1360  64a100000000         mov eax, dword ptr fs:[0]
// 006c1366  6aff                 push -1
// 006c1368  680e9bab00           push 0xab9b0e
// 006c136d  50                   push eax
// 006c136e  b801000000           mov eax, 1
// 006c1373  64892500000000       mov dword ptr fs:[0], esp
// 006c137a  840588e2e200         test byte ptr [0xe2e288], al
// 006c1380  7536                 jne 0x6c13b8
// 006c1382  090588e2e200         or dword ptr [0xe2e288], eax
// 006c1388  6a00                 push 0
// 006c138a  686069b900           push 0xb96960
// 006c138f  b96ce2e200           mov ecx, 0xe2e26c
// 006c1394  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c139c  e82fe4ffff           call 0x6bf7d0
// 006c13a1  68e065b100           push 0xb165e0
// 006c13a6  c7056ce2e200c068b900 mov dword ptr [0xe2e26c], 0xb968c0
// 006c13b0  e8401e2c00           call 0x9831f5
// 006c13b5  83c404               add esp, 4
// 006c13b8  8b0c24               mov ecx, dword ptr [esp]
// 006c13bb  b86ce2e200           mov eax, 0xe2e26c
// 006c13c0  64890d00000000       mov dword ptr fs:[0], ecx
// 006c13c7  83c40c               add esp, 0xc
// 006c13ca  c3                   ret 
// copied from an identical function in another client (function ??$singleton@_N@Type@Reflection@RBX@@SAABV012@XZ)

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
const Type& Type::singleton<bool>()
{
	static TypeImpl<bool> type("bool");
	return type;
}
}
}