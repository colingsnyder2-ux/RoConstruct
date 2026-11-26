// from server: 100% by Xemicl
// roc 2012-06 006c1440  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c1440
//
// 006c1440  64a100000000         mov eax, dword ptr fs:[0]
// 006c1446  6aff                 push -1
// 006c1448  684e9bab00           push 0xab9b4e
// 006c144d  50                   push eax
// 006c144e  b801000000           mov eax, 1
// 006c1453  64892500000000       mov dword ptr fs:[0], esp
// 006c145a  8405c8e2e200         test byte ptr [0xe2e2c8], al
// 006c1460  7536                 jne 0x6c1498
// 006c1462  0905c8e2e200         or dword ptr [0xe2e2c8], eax
// 006c1468  6a00                 push 0
// 006c146a  687069b900           push 0xb96970
// 006c146f  b9ace2e200           mov ecx, 0xe2e2ac
// 006c1474  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c147c  e8efe4ffff           call 0x6bf970
// 006c1481  680066b100           push 0xb16600
// 006c1486  c705ace2e200d068b900 mov dword ptr [0xe2e2ac], 0xb968d0
// 006c1490  e8601d2c00           call 0x9831f5
// 006c1495  83c404               add esp, 4
// 006c1498  8b0c24               mov ecx, dword ptr [esp]
// 006c149b  b8ace2e200           mov eax, 0xe2e2ac
// 006c14a0  64890d00000000       mov dword ptr fs:[0], ecx
// 006c14a7  83c40c               add esp, 0xc
// 006c14aa  c3                   ret 
// copied from an identical function in another client (function ??$singleton@N@Type@Reflection@RBX@@SAABV012@XZ)

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
const Type& Type::singleton<double>()
{
	static TypeImpl<double> type("double");
	return type;
}
}
}