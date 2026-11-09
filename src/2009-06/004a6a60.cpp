// from server: 100% by EspClaude
// roc 2009-06 004a6a60  unit: G3D::TextureManager::TextureArgs  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004a6a60
//
// 004a6a60  6aff                 push -1
// 004a6a62  68a8778500           push 0x8577a8
// 004a6a67  64a100000000         mov eax, dword ptr fs:[0]
// 004a6a6d  50                   push eax
// 004a6a6e  64892500000000       mov dword ptr fs:[0], esp
// 004a6a75  83ec24               sub esp, 0x24
// 004a6a78  53                   push ebx
// 004a6a79  33db                 xor ebx, ebx
// 004a6a7b  895c2408             mov dword ptr [esp + 8], ebx
// 004a6a7f  381d44c9a300         cmp byte ptr [0xa3c944], bl
// 004a6a85  0f8590000000         jne 0x4a6b1b
// 004a6a8b  381df4c8a300         cmp byte ptr [0xa3c8f4], bl
// 004a6a91  0f8584000000         jne 0x4a6b1b
// 004a6a97  e8f4260d00           call 0x579190
// 004a6a9c  391dd8c99f00         cmp dword ptr [0x9fc9d8], ebx
// 004a6aa2  7447                 je 0x4a6aeb
// 004a6aa4  68d40c8c00           push 0x8c0cd4
// 004a6aa9  8d4c2410             lea ecx, [esp + 0x10]
// 004a6aad  ff15b4e48900         call dword ptr [0x89e4b4]
// 004a6ab3  895c2430             mov dword ptr [esp + 0x30], ebx
// 004a6ab7  bb01000000           mov ebx, 1
// 004a6abc  53                   push ebx
// 004a6abd  6844c9a300           push 0xa3c944
// 004a6ac2  6867020000           push 0x267
// 004a6ac7  68400b8c00           push 0x8c0b40
// 004a6acc  8d44241c             lea eax, [esp + 0x1c]
// 004a6ad0  50                   push eax
// 004a6ad1  68c00c8c00           push 0x8c0cc0
// 004a6ad6  895c2420             mov dword ptr [esp + 0x20], ebx
// 004a6ada  ff15d8c99f00         call dword ptr [0x9fc9d8]
// 004a6ae0  83c418               add esp, 0x18
// 004a6ae3  885c2407             mov byte ptr [esp + 7], bl
// 004a6ae7  84c0                 test al, al
// 004a6ae9  7505                 jne 0x4a6af0
// 004a6aeb  c644240700           mov byte ptr [esp + 7], 0
// 004a6af0  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 004a6af8  f6c301               test bl, 1
// 004a6afb  740a                 je 0x4a6b07
// 004a6afd  8d4c240c             lea ecx, [esp + 0xc]
// 004a6b01  ff15c4e48900         call dword ptr [0x89e4c4]
// 004a6b07  807c240700           cmp byte ptr [esp + 7], 0
// 004a6b0c  7408                 je 0x4a6b16
// 004a6b0e  6aff                 push -1
// 004a6b10  ff15bce88900         call dword ptr [0x89e8bc]
// 004a6b16  e8e5260d00           call 0x579200
// 004a6b1b  f60540c9a30001       test byte ptr [0xa3c940], 1
// 004a6b22  7533                 jne 0x4a6b57
// 004a6b24  b801000000           mov eax, 1
// 004a6b29  090540c9a300         or dword ptr [0xa3c940], eax
// 004a6b2f  68021f0000           push 0x1f02
// 004a6b34  89442434             mov dword ptr [esp + 0x34], eax
// 004a6b38  ff158cea8900         call dword ptr [0x89ea8c]
// 004a6b3e  50                   push eax
// 004a6b3f  b924c9a300           mov ecx, 0xa3c924
// 004a6b44  ff15b4e48900         call dword ptr [0x89e4b4]
// 004a6b4a  68f04e8900           push 0x894ef0
// 004a6b4f  e8a72f2700           call 0x719afb
// 004a6b54  83c404               add esp, 4
// 004a6b57  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004a6b5b  b824c9a300           mov eax, 0xa3c924
// 004a6b60  5b                   pop ebx
// 004a6b61  64890d00000000       mov dword ptr fs:[0], ecx
// 004a6b68  83c430               add esp, 0x30
// 004a6b6b  c3                   ret 
// copied from an identical function in another client (function ?glVersion@GLCaps@G3D@@SAABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ)

// from server: 97% by king_originala
// roc 2008-06 00470770  unit: RBX::LDraw2Lua::LuaWriter  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00470770
//
// 00470770  6aff                 push -1
// 00470772  68b8407c00           push 0x7c40b8
// 00470777  64a100000000         mov eax, dword ptr fs:[0]
// 0047077d  50                   push eax
// 0047077e  64892500000000       mov dword ptr fs:[0], esp
// 00470785  83ec24               sub esp, 0x24
// 00470788  53                   push ebx
// 00470789  33db                 xor ebx, ebx
// 0047078b  895c2408             mov dword ptr [esp + 8], ebx
// 0047078f  381db4ee9600         cmp byte ptr [0x96eeb4], bl
// 00470795  0f8590000000         jne 0x47082b
// 0047079b  381d64ee9600         cmp byte ptr [0x96ee64], bl
// 004707a1  0f8584000000         jne 0x47082b
// 004707a7  e894a10900           call 0x50a940
// 004707ac  391d8c279400         cmp dword ptr [0x94278c], ebx
// 004707b2  7447                 je 0x4707fb
// 004707b4  683cce8100           push 0x81ce3c
// 004707b9  8d4c2410             lea ecx, [esp + 0x10]
// 004707bd  ff1558248000         call dword ptr [0x802458]
// 004707c3  895c2430             mov dword ptr [esp + 0x30], ebx
// 004707c7  bb01000000           mov ebx, 1
// 004707cc  53                   push ebx
// 004707cd  68b4ee9600           push 0x96eeb4
// 004707d2  6867020000           push 0x267
// 004707d7  6880cc8100           push 0x81cc80
// 004707dc  8d44241c             lea eax, [esp + 0x1c]
// 004707e0  50                   push eax
// 004707e1  6828ce8100           push 0x81ce28
// 004707e6  895c2420             mov dword ptr [esp + 0x20], ebx
// 004707ea  ff158c279400         call dword ptr [0x94278c]
// 004707f0  83c418               add esp, 0x18
// 004707f3  885c2407             mov byte ptr [esp + 7], bl
// 004707f7  84c0                 test al, al
// 004707f9  7505                 jne 0x470800
// 004707fb  c644240700           mov byte ptr [esp + 7], 0
// 00470800  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00470808  f6c301               test bl, 1
// 0047080b  740a                 je 0x470817
// 0047080d  8d4c240c             lea ecx, [esp + 0xc]
// 00470811  ff1568248000         call dword ptr [0x802468]
// 00470817  807c240700           cmp byte ptr [esp + 7], 0
// 0047081c  7408                 je 0x470826
// 0047081e  6aff                 push -1
// 00470820  ff15f4278000         call dword ptr [0x8027f4]
// 00470826  e885a10900           call 0x50a9b0
// 0047082b  f605b0ee960001       test byte ptr [0x96eeb0], 1
// 00470832  7533                 jne 0x470867
// 00470834  b801000000           mov eax, 1
// 00470839  0905b0ee9600         or dword ptr [0x96eeb0], eax
// 0047083f  68021f0000           push 0x1f02
// 00470844  89442434             mov dword ptr [esp + 0x34], eax
// 00470848  ff1594298000         call dword ptr [0x802994]
// 0047084e  50                   push eax
// 0047084f  b994ee9600           mov ecx, 0x96ee94
// 00470854  ff1558248000         call dword ptr [0x802458]
// 0047085a  6820b07f00           push 0x7fb020
// 0047085f  e84b0f2300           call 0x6a17af
// 00470864  83c404               add esp, 4
// 00470867  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0047086b  b894ee9600           mov eax, 0x96ee94
// 00470870  5b                   pop ebx
// 00470871  64890d00000000       mov dword ptr fs:[0], ecx
// 00470878  83c430               add esp, 0x30
// 0047087b  c3                   ret 
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
    static const std::string& glVersion();
};
const std::string& GLCaps::glVersion()
{
    {
        static bool __ignoreAlways = false;
        if (!(_loadedExtensions) && !__ignoreAlways) {
            G3D::_internal::_releaseInputGrab_();
            if ((G3D::_internal::_failureHook != 0) &&
                G3D::_internal::_failureHook("_loadedExtensions", "Cannot call GLCaps::glVersion before GLCaps::init().",
                                             ".\\glg3dcpp\\GLCaps.cpp", 615, &__ignoreAlways, true)) {
                exit(-1);
            }
            G3D::_internal::_restoreInputGrab_();
        }
    }
    static std::string _glVersion = (const char*)glGetString(0x1F02);
    return _glVersion;
}
}