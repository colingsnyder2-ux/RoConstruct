// from server: 100% by colin
// from server: 97% by king_originala
// roc 2008-06 00470880  unit: RBX::LDraw2Lua::LuaWriter  size: 277 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00470880
//
// 00470880  6aff                 push -1
// 00470882  68f8407c00           push 0x7c40f8
// 00470887  64a100000000         mov eax, dword ptr fs:[0]
// 0047088d  50                   push eax
// 0047088e  64892500000000       mov dword ptr fs:[0], esp
// 00470895  83ec24               sub esp, 0x24
// 00470898  53                   push ebx
// 00470899  33db                 xor ebx, ebx
// 0047089b  895c2408             mov dword ptr [esp + 8], ebx
// 0047089f  381dd8ee9600         cmp byte ptr [0x96eed8], bl
// 004708a5  0f8590000000         jne 0x47093b
// 004708ab  381d64ee9600         cmp byte ptr [0x96ee64], bl
// 004708b1  0f8584000000         jne 0x47093b
// 004708b7  e884a00900           call 0x50a940
// 004708bc  391d8c279400         cmp dword ptr [0x94278c], ebx
// 004708c2  7447                 je 0x47090b
// 004708c4  6874ce8100           push 0x81ce74
// 004708c9  8d4c2410             lea ecx, [esp + 0x10]
// 004708cd  ff1558248000         call dword ptr [0x802458]
// 004708d3  895c2430             mov dword ptr [esp + 0x30], ebx
// 004708d7  bb01000000           mov ebx, 1
// 004708dc  53                   push ebx
// 004708dd  68d8ee9600           push 0x96eed8
// 004708e2  6875020000           push 0x275
// 004708e7  6880cc8100           push 0x81cc80
// 004708ec  8d44241c             lea eax, [esp + 0x1c]
// 004708f0  50                   push eax
// 004708f1  6828ce8100           push 0x81ce28
// 004708f6  895c2420             mov dword ptr [esp + 0x20], ebx
// 004708fa  ff158c279400         call dword ptr [0x94278c]
// 00470900  83c418               add esp, 0x18
// 00470903  885c2407             mov byte ptr [esp + 7], bl
// 00470907  84c0                 test al, al
// 00470909  7505                 jne 0x470910
// 0047090b  c644240700           mov byte ptr [esp + 7], 0
// 00470910  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00470918  f6c301               test bl, 1
// 0047091b  740a                 je 0x470927
// 0047091d  8d4c240c             lea ecx, [esp + 0xc]
// 00470921  ff1568248000         call dword ptr [0x802468]
// 00470927  807c240700           cmp byte ptr [esp + 7], 0
// 0047092c  7408                 je 0x470936
// 0047092e  6aff                 push -1
// 00470930  ff15f4278000         call dword ptr [0x8027f4]
// 00470936  e875a00900           call 0x50a9b0
// 0047093b  68001f0000           push 0x1f00
// 00470940  ff1594298000         call dword ptr [0x802994]
// 00470946  f605d4ee960001       test byte ptr [0x96eed4], 1
// 0047094d  7531                 jne 0x470980
// 0047094f  b901000000           mov ecx, 1
// 00470954  090dd4ee9600         or dword ptr [0x96eed4], ecx
// 0047095a  894c2430             mov dword ptr [esp + 0x30], ecx
// 0047095e  85c0                 test eax, eax
// 00470960  7505                 jne 0x470967
// 00470962  b816b78000           mov eax, 0x80b716
// 00470967  50                   push eax
// 00470968  b9b8ee9600           mov ecx, 0x96eeb8
// 0047096d  ff1558248000         call dword ptr [0x802458]
// 00470973  6840b07f00           push 0x7fb040
// 00470978  e8320e2300           call 0x6a17af
// 0047097d  83c404               add esp, 4
// 00470980  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00470984  b8b8ee9600           mov eax, 0x96eeb8
// 00470989  5b                   pop ebx
// 0047098a  64890d00000000       mov dword ptr fs:[0], ecx
// 00470991  83c430               add esp, 0x30
// 00470994  c3                   ret 
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
    static const std::string& vendor();
};
const std::string& GLCaps::vendor()
{
    {
        static bool __ignoreAlways = false;
        if (!__ignoreAlways && !(_loadedExtensions)) {
            G3D::_internal::_releaseInputGrab_();
            if ((G3D::_internal::_failureHook != 0) &&
                G3D::_internal::_failureHook("_loadedExtensions", "Cannot call GLCaps::vendor before GLCaps::init().",
                                             ".\\glg3dcpp\\GLCaps.cpp", 629, &__ignoreAlways, true)) {
                exit(-1);
            }
            G3D::_internal::_restoreInputGrab_();
        }
    }
    const char* text = (const char*)glGetString(0x1F00);
    static std::string _glVendor = text ? text : "";
    return _glVendor;
}
}
