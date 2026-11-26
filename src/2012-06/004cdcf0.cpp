// from server: 100% by Xemicl
// roc 2012-06 004cdcf0  unit: Ogre::GfxClustererPart  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cdcf0
//
// 004cdcf0  53                   push ebx
// 004cdcf1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 004cdcf5  56                   push esi
// 004cdcf6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004cdcfa  3bf3                 cmp esi, ebx
// 004cdcfc  741c                 je 0x4cdd1a
// 004cdcfe  57                   push edi
// 004cdcff  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004cdd03  57                   push edi
// 004cdd04  8bce                 mov ecx, esi
// 004cdd06  ff155826b200         call dword ptr [0xb22658]
// 004cdd0c  8b471c               mov eax, dword ptr [edi + 0x1c]
// 004cdd0f  89461c               mov dword ptr [esi + 0x1c], eax
// 004cdd12  83c620               add esi, 0x20
// 004cdd15  3bf3                 cmp esi, ebx
// 004cdd17  75ea                 jne 0x4cdd03
// 004cdd19  5f                   pop edi
// 004cdd1a  5e                   pop esi
// 004cdd1b  5b                   pop ebx
// 004cdd1c  c3                   ret 
// copied from an identical function in another client (function ?fillE@@YAXPAUE@@0ABU1@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct E { std::string s; int v; };
void fillE(E* first, E* last, const E& val) { for (; first != last; ++first) *first = val; }