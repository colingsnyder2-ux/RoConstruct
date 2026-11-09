// from server: 100% by auto
// roc 2011-06 00405560  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00405560
//
// 00405560  8b442404             mov eax, dword ptr [esp + 4]
// 00405564  56                   push esi
// 00405565  8bf1                 mov esi, ecx
// 00405567  33c9                 xor ecx, ecx
// 00405569  7705                 ja 0x405570
// 0040556b  83f8ff               cmp eax, -1
// 0040556e  760a                 jbe 0x40557a
// 00405570  6857000780           push 0x80070057
// 00405575  e826e0ffff           call 0x4035a0
// 0040557a  3d00040000           cmp eax, 0x400
// 0040557f  760e                 jbe 0x40558f
// 00405581  50                   push eax
// 00405582  8bce                 mov ecx, esi
// 00405584  e8b7edffff           call 0x404340
// 00405589  8b06                 mov eax, dword ptr [esi]
// 0040558b  5e                   pop esi
// 0040558c  c20400               ret 4
// 0040558f  8d4604               lea eax, [esi + 4]
// 00405592  8906                 mov dword ptr [esi], eax
// 00405594  5e                   pop esi
// 00405595  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0EAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
