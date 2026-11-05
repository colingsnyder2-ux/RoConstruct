// from server: 100% by colin
// from server: 97% by king_originala
// roc 2008-06 004709a0  unit: RBX::LDraw2Lua::LuaWriter  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004709a0
//
// 004709a0  6aff                 push -1
// 004709a2  6838417c00           push 0x7c4138
// 004709a7  64a100000000         mov eax, dword ptr fs:[0]
// 004709ad  50                   push eax
// 004709ae  64892500000000       mov dword ptr fs:[0], esp
// 004709b5  83ec24               sub esp, 0x24
// 004709b8  53                   push ebx
// 004709b9  33db                 xor ebx, ebx
// 004709bb  895c2408             mov dword ptr [esp + 8], ebx
// 004709bf  381dfcee9600         cmp byte ptr [0x96eefc], bl
// 004709c5  0f8590000000         jne 0x470a5b
// 004709cb  381d64ee9600         cmp byte ptr [0x96ee64], bl
// 004709d1  0f8584000000         jne 0x470a5b
// 004709d7  e8649f0900           call 0x50a940
// 004709dc  391d8c279400         cmp dword ptr [0x94278c], ebx
// 004709e2  7447                 je 0x470a2b
// 004709e4  68a8ce8100           push 0x81cea8
// 004709e9  8d4c2410             lea ecx, [esp + 0x10]
// 004709ed  ff1558248000         call dword ptr [0x802458]
// 004709f3  895c2430             mov dword ptr [esp + 0x30], ebx
// 004709f7  bb01000000           mov ebx, 1
// 004709fc  53                   push ebx
// 004709fd  68fcee9600           push 0x96eefc
// 00470a02  687d020000           push 0x27d
// 00470a07  6880cc8100           push 0x81cc80
// 00470a0c  8d44241c             lea eax, [esp + 0x1c]
// 00470a10  50                   push eax
// 00470a11  6828ce8100           push 0x81ce28
// 00470a16  895c2420             mov dword ptr [esp + 0x20], ebx
// 00470a1a  ff158c279400         call dword ptr [0x94278c]
// 00470a20  83c418               add esp, 0x18
// 00470a23  885c2407             mov byte ptr [esp + 7], bl
// 00470a27  84c0                 test al, al
// 00470a29  7505                 jne 0x470a30
// 00470a2b  c644240700           mov byte ptr [esp + 7], 0
// 00470a30  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00470a38  f6c301               test bl, 1
// 00470a3b  740a                 je 0x470a47
// 00470a3d  8d4c240c             lea ecx, [esp + 0xc]
// 00470a41  ff1568248000         call dword ptr [0x802468]
// 00470a47  807c240700           cmp byte ptr [esp + 7], 0
// 00470a4c  7408                 je 0x470a56
// 00470a4e  6aff                 push -1
// 00470a50  ff15f4278000         call dword ptr [0x8027f4]
// 00470a56  e8559f0900           call 0x50a9b0
// 00470a5b  f605f8ee960001       test byte ptr [0x96eef8], 1
// 00470a62  7533                 jne 0x470a97
// 00470a64  b801000000           mov eax, 1
// 00470a69  0905f8ee9600         or dword ptr [0x96eef8], eax
// 00470a6f  68011f0000           push 0x1f01
// 00470a74  89442434             mov dword ptr [esp + 0x34], eax
// 00470a78  ff1594298000         call dword ptr [0x802994]
// 00470a7e  50                   push eax
// 00470a7f  b9dcee9600           mov ecx, 0x96eedc
// 00470a84  ff1558248000         call dword ptr [0x802458]
// 00470a8a  6850b07f00           push 0x7fb050
// 00470a8f  e81b0d2300           call 0x6a17af
// 00470a94  83c404               add esp, 4
// 00470a97  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00470a9b  b8dcee9600           mov eax, 0x96eedc
// 00470aa0  5b                   pop ebx
// 00470aa1  64890d00000000       mov dword ptr fs:[0], ecx
// 00470aa8  83c430               add esp, 0x30
// 00470aab  c3                   ret 
#include <string>
#include <stdlib.h>
extern "C" __declspec(dllimport) const unsigned char* __stdcall glGetString(unsigned int);
namespace G3D {
namespace _internal {
    extern bool (__cdecl* _failureHook)(const char*, const std::string&, const char*, int, bool*, bool);
    void __cdecl _releaseInputGrab_();
    void __cdecl _restoreInputGrab_();
}
class GLCaps {
public:
    static bool _loadedExtensions;
    static const std::string& renderer();
};
const std::string& GLCaps::renderer()
{
    {
        static bool __ignoreAlways = false;
        if (!(_loadedExtensions) && !__ignoreAlways) {
            G3D::_internal::_releaseInputGrab_();
            if ((G3D::_internal::_failureHook != 0) &&
                G3D::_internal::_failureHook("_loadedExtensions", "Cannot call GLCaps::renderer before GLCaps::init().",
                                             ".\\glg3dcpp\\GLCaps.cpp", 637, &__ignoreAlways, true)) {
                exit(-1);
            }
            G3D::_internal::_restoreInputGrab_();
        }
    }
    static std::string _renderer = (const char*)glGetString(0x1F01);
    return _renderer;
}
}
