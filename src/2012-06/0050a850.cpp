// from server: 100% by Xemicl
// roc 2012-06 0050a850  unit: Ogre::RbxArchive  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050a850
//
// 0050a850  6aff                 push -1
// 0050a852  68fc93ae00           push 0xae93fc
// 0050a857  64a100000000         mov eax, dword ptr fs:[0]
// 0050a85d  50                   push eax
// 0050a85e  64892500000000       mov dword ptr fs:[0], esp
// 0050a865  81ec84000000         sub esp, 0x84
// 0050a86b  56                   push esi
// 0050a86c  6a01                 push 1
// 0050a86e  6a02                 push 2
// 0050a870  8d4c2410             lea ecx, [esp + 0x10]
// 0050a874  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0050a87c  ff158026b200         call dword ptr [0xb22680]
// 0050a882  8b84249c000000       mov eax, dword ptr [esp + 0x9c]
// 0050a889  50                   push eax
// 0050a88a  6870d94600           push 0x46d970
// 0050a88f  8d4c2410             lea ecx, [esp + 0x10]
// 0050a893  6808bcb600           push 0xb6bc08
// 0050a898  51                   push ecx
// 0050a899  c78424a000000001000000 mov dword ptr [esp + 0xa0], 1
// 0050a8a4  e88729f4ff           call 0x44d230
// 0050a8a9  83c408               add esp, 8
// 0050a8ac  8bc8                 mov ecx, eax
// 0050a8ae  ff159025b200         call dword ptr [0xb22590]
// 0050a8b4  8bc8                 mov ecx, eax
// 0050a8b6  ff15b425b200         call dword ptr [0xb225b4]
// 0050a8bc  8bb42498000000       mov esi, dword ptr [esp + 0x98]
// 0050a8c3  56                   push esi
// 0050a8c4  8d4c240c             lea ecx, [esp + 0xc]
// 0050a8c8  ff157c26b200         call dword ptr [0xb2267c]
// 0050a8ce  8d4c2408             lea ecx, [esp + 8]
// 0050a8d2  c744240401000000     mov dword ptr [esp + 4], 1
// 0050a8da  c684249000000000     mov byte ptr [esp + 0x90], 0
// 0050a8e2  ff157826b200         call dword ptr [0xb22678]
// 0050a8e8  8b8c2488000000       mov ecx, dword ptr [esp + 0x88]
// 0050a8ef  8bc6                 mov eax, esi
// 0050a8f1  5e                   pop esi
// 0050a8f2  64890d00000000       mov dword ptr fs:[0], ecx
// 0050a8f9  81c490000000         add esp, 0x90
// 0050a8ff  c3                   ret 
// copied from an identical function in another client (function ?archiveName@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <sstream>
#include <string>
std::string archiveName(int n)
{
    std::ostringstream s;
    s << "RbxArchive" << std::hex << n;
    return s.str();
}