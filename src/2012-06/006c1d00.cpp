// from server: 100% by Xemicl
// roc 2012-06 006c1d00  unit: RBX::VAxes::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c1d00
//
// 006c1d00  64a100000000         mov eax, dword ptr fs:[0]
// 006c1d06  6aff                 push -1
// 006c1d08  68ce9cab00           push 0xab9cce
// 006c1d0d  50                   push eax
// 006c1d0e  b801000000           mov eax, 1
// 006c1d13  64892500000000       mov dword ptr fs:[0], esp
// 006c1d1a  840548e4e200         test byte ptr [0xe2e448], al
// 006c1d20  7536                 jne 0x6c1d58
// 006c1d22  090548e4e200         or dword ptr [0xe2e448], eax
// 006c1d28  6a00                 push 0
// 006c1d2a  683039b800           push 0xb83930
// 006c1d2f  b92ce4e200           mov ecx, 0xe2e42c
// 006c1d34  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c1d3c  e8efe5ffff           call 0x6c0330
// 006c1d41  68c066b100           push 0xb166c0
// 006c1d46  c7052ce4e2003069b900 mov dword ptr [0xe2e42c], 0xb96930
// 006c1d50  e8a0142c00           call 0x9831f5
// 006c1d55  83c404               add esp, 4
// 006c1d58  8b0c24               mov ecx, dword ptr [esp]
// 006c1d5b  b82ce4e200           mov eax, 0xe2e42c
// 006c1d60  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1d67  83c40c               add esp, 0xc
// 006c1d6a  c3                   ret 
// copied from an identical function in another client (function ??$singleton@VColor3@G3D@@@Type@Reflection@RBX@@SAABV012@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class Color3; }
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
template<> const Type& Type::singleton<G3D::Color3>()
{
	static TType<G3D::Color3> type("Color3");
	return type;
}
}}