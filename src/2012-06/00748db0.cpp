// from server: 100% by Xemicl
// roc 2012-06 00748db0  unit: CPropGrid::UpdateItemsJob  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00748db0
//
// 00748db0  56                   push esi
// 00748db1  8b742408             mov esi, dword ptr [esp + 8]
// 00748db5  6a07                 push 7
// 00748db7  6a00                 push 0
// 00748db9  6804c7b700           push 0xb7c704
// 00748dbe  8bce                 mov ecx, esi
// 00748dc0  ff154425b200         call dword ptr [0xb22544]
// 00748dc6  85c0                 test eax, eax
// 00748dc8  7415                 je 0x748ddf
// 00748dca  6a08                 push 8
// 00748dcc  6a00                 push 0
// 00748dce  68f8c6b700           push 0xb7c6f8
// 00748dd3  8bce                 mov ecx, esi
// 00748dd5  ff154425b200         call dword ptr [0xb22544]
// 00748ddb  85c0                 test eax, eax
// 00748ddd  7504                 jne 0x748de3
// 00748ddf  b001                 mov al, 1
// 00748de1  5e                   pop esi
// 00748de2  c3                   ret 
// 00748de3  6a0b                 push 0xb
// 00748de5  6a00                 push 0
// 00748de7  681cbbb600           push 0xb6bb1c
// 00748dec  8bce                 mov ecx, esi
// 00748dee  ff154425b200         call dword ptr [0xb22544]
// 00748df4  85c0                 test eax, eax
// 00748df6  0f94c0               sete al
// 00748df9  5e                   pop esi
// 00748dfa  c3                   ret 
// copied from an identical function in another client (function ?isUrl@@YA_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
static inline bool isHttp(const std::string& s) { return s.find("http://") == 0 || s.find("https://") == 0; }
static inline bool isAsset(const std::string& s) {  }
bool isUrl(const std::string& s)
{
if (isHttp(s)) return true; bool r = s.find("rbxasset://") == 0; return r;
}