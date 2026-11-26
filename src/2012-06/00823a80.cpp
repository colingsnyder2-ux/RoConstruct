// from server: 100% by Xemicl
// roc 2012-06 00823a80  unit: RBX::$01W4SurfaceType::?$SurfaceGetSet  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00823a80
//
// 00823a80  64a100000000         mov eax, dword ptr fs:[0]
// 00823a86  6aff                 push -1
// 00823a88  68fec3ac00           push 0xacc3fe
// 00823a8d  50                   push eax
// 00823a8e  b801000000           mov eax, 1
// 00823a93  64892500000000       mov dword ptr fs:[0], esp
// 00823a9a  8405f40ae500         test byte ptr [0xe50af4], al
// 00823aa0  753b                 jne 0x823add
// 00823aa2  0905f40ae500         or dword ptr [0xe50af4], eax
// 00823aa8  6a00                 push 0
// 00823aaa  68d8c9bc00           push 0xbcc9d8
// 00823aaf  68d0c9bc00           push 0xbcc9d0
// 00823ab4  b9d80ae500           mov ecx, 0xe50ad8
// 00823ab9  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00823ac1  e83afbffff           call 0x823600
// 00823ac6  68b0e7b100           push 0xb1e7b0
// 00823acb  c705d80ae500ccc9bc00 mov dword ptr [0xe50ad8], 0xbcc9cc
// 00823ad5  e81bf71500           call 0x9831f5
// 00823ada  83c404               add esp, 4
// 00823add  8b0c24               mov ecx, dword ptr [esp]
// 00823ae0  b8d80ae500           mov eax, 0xe50ad8
// 00823ae5  64890d00000000       mov dword ptr fs:[0], ecx
// 00823aec  83c40c               add esp, 0xc
// 00823aef  c3                   ret 
// copied from an identical function in another client (function ??$singleton@VSurface@RBX@@@CplxType@Reflection@RBX@@SAABV012@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Surface;
namespace Reflection {
class Type { public: Type(const char* name, const char* tag, int x); virtual ~Type(); };
class CplxType : public Type {
public:
    CplxType(const char* name) : Type(name, "Complex", 0) {}
    virtual ~CplxType() {}
    template<class T> static const CplxType& singleton()
    {
        static CplxType type("Surface");
        return type;
    }
};
template const CplxType& CplxType::singleton<Surface>();
}}