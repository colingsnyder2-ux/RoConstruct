// from server: 100% by Xemicl
// roc 2012-06 006c1210  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c1210
//
// 006c1210  64a100000000         mov eax, dword ptr fs:[0]
// 006c1216  6aff                 push -1
// 006c1218  68ae9aab00           push 0xab9aae
// 006c121d  50                   push eax
// 006c121e  b801000000           mov eax, 1
// 006c1223  64892500000000       mov dword ptr fs:[0], esp
// 006c122a  840528e2e200         test byte ptr [0xe2e228], al
// 006c1230  7536                 jne 0x6c1268
// 006c1232  090528e2e200         or dword ptr [0xe2e228], eax
// 006c1238  6a00                 push 0
// 006c123a  684c69b900           push 0xb9694c
// 006c123f  b90ce2e200           mov ecx, 0xe2e20c
// 006c1244  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c124c  e80fe3ffff           call 0x6bf560
// 006c1251  68b065b100           push 0xb165b0
// 006c1256  c7050ce2e200a868b900 mov dword ptr [0xe2e20c], 0xb968a8
// 006c1260  e8901f2c00           call 0x9831f5
// 006c1265  83c404               add esp, 4
// 006c1268  8b0c24               mov ecx, dword ptr [esp]
// 006c126b  b80ce2e200           mov eax, 0xe2e20c
// 006c1270  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1277  83c40c               add esp, 0xc
// 006c127a  c3                   ret 
// copied from an identical function in another client (function ??$singleton@V?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ)

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
const Type& Type::singleton<boost::shared_ptr<Instances>>()
{
	static TypeImpl<boost::shared_ptr<Instances>> type("Objects");
	return type;
}
}
}