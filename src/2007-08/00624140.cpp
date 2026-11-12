// from server: 96% by EspClaude
// from server: 50% by colin
// roc 2007-08 00624140  unit: RBX::ArrowButton  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00624140
//
// 00624140  6aff                 push -1
// 00624142  6873cf7500           push 0x75cf73
// 00624147  64a100000000         mov eax, dword ptr fs:[0]
// 0062414d  50                   push eax
// 0062414e  64892500000000       mov dword ptr fs:[0], esp
// 00624155  83ec20               sub esp, 0x20
// 00624158  56                   push esi
// 00624159  8b742434             mov esi, dword ptr [esp + 0x34]
// 0062415d  6878497c00           push 0x7c4978
// 00624162  8d4c240c             lea ecx, [esp + 0xc]
// 00624166  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0062416e  c744240800000000     mov dword ptr [esp + 8], 0
// 00624176  ff1598e67700         call dword ptr [0x77e698]
// 0062417c  8d442408             lea eax, [esp + 8]
// 00624180  50                   push eax
// 00624181  56                   push esi
// 00624182  c744243401000000     mov dword ptr [esp + 0x34], 1
// 0062418a  e8b145deff           call 0x408740
// 0062418f  8bc8                 mov ecx, eax
// 00624191  e80a50f2ff           call 0x5491a0
// 00624196  8d4c2408             lea ecx, [esp + 8]
// 0062419a  c744240401000000     mov dword ptr [esp + 4], 1
// 006241a2  c644242c00           mov byte ptr [esp + 0x2c], 0
// 006241a7  ff15ace67700         call dword ptr [0x77e6ac]
// 006241ad  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006241b1  8bc6                 mov eax, esi
// 006241b3  5e                   pop esi
// 006241b4  64890d00000000       mov dword ptr fs:[0], ecx
// 006241bb  83c42c               add esp, 0x2c
// 006241be  c3                   ret 

// roc-flags: /O2 /GS- /EHsc /MD
// Static helper returning the safechat font path (codegen analog):
// target builds a std::string temp from "Fonts\safechat.xml" (dllimport msvcp80 ctor/dtor),
// calls the singleton getter (0x408740, no args) and then the thiscall
// getAssetFile(hidden std::string result, const std::string&) with ret 8 (0x5491a0).
#include <string>

namespace RBX {

class ContentProvider {
public:
    static ContentProvider& singleton();
    std::string getAssetFile(const std::string& filePath);
};

class ArrowButton {
public:
    static std::string safeChatFile();
};

std::string ArrowButton::safeChatFile()
{
    std::string result = ContentProvider::singleton().getAssetFile("Fonts\\safechat.xml");
    return result;
}

}
