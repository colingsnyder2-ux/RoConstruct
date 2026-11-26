// from server: 100% by Xemicl
// roc 2012-06 006c1590  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c1590
//
// 006c1590  64a100000000         mov eax, dword ptr fs:[0]
// 006c1596  6aff                 push -1
// 006c1598  68ae9bab00           push 0xab9bae
// 006c159d  50                   push eax
// 006c159e  b801000000           mov eax, 1
// 006c15a3  64892500000000       mov dword ptr fs:[0], esp
// 006c15aa  840528e3e200         test byte ptr [0xe2e328], al
// 006c15b0  7536                 jne 0x6c15e8
// 006c15b2  090528e3e200         or dword ptr [0xe2e328], eax
// 006c15b8  6a00                 push 0
// 006c15ba  68b039b800           push 0xb839b0
// 006c15bf  b90ce3e200           mov ecx, 0xe2e30c
// 006c15c4  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c15cc  e80fe6ffff           call 0x6bfbe0
// 006c15d1  683066b100           push 0xb16630
// 006c15d6  c7050ce3e200e868b900 mov dword ptr [0xe2e30c], 0xb968e8
// 006c15e0  e8101c2c00           call 0x9831f5
// 006c15e5  83c404               add esp, 4
// 006c15e8  8b0c24               mov ecx, dword ptr [esp]
// 006c15eb  b80ce3e200           mov eax, 0xe2e30c
// 006c15f0  64890d00000000       mov dword ptr fs:[0], ecx
// 006c15f7  83c40c               add esp, 0xc
// 006c15fa  c3                   ret 
// copied from an identical function in another client (function ??$singleton@VVector3@G3D@@@Type@Reflection@RBX@@SAABV012@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class Vector3; }
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
template<> const Type& Type::singleton<G3D::Vector3>()
{
	static TType<G3D::Vector3> type("Vector3");
	return type;
}
}}