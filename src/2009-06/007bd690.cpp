// from server: 100% by auto
// roc 2009-06 007bd690  unit: CXTPCommandBarAnimation::PAUCAnimateInfo::?$CArray  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bd690
//
// 007bd690  56                   push esi
// 007bd691  8bf1                 mov esi, ecx
// 007bd693  57                   push edi
// 007bd694  33ff                 xor edi, edi
// 007bd696  8d4e1c               lea ecx, [esi + 0x1c]
// 007bd699  897e08               mov dword ptr [esi + 8], edi
// 007bd69c  c7460464f68a00       mov dword ptr [esi + 4], 0x8af664
// 007bd6a3  e818ffffff           call 0x7bd5c0
// 007bd6a8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007bd6ac  897e0c               mov dword ptr [esi + 0xc], edi
// 007bd6af  897e10               mov dword ptr [esi + 0x10], edi
// 007bd6b2  897e14               mov dword ptr [esi + 0x14], edi
// 007bd6b5  897e18               mov dword ptr [esi + 0x18], edi
// 007bd6b8  8906                 mov dword ptr [esi], eax
// 007bd6ba  5f                   pop edi
// 007bd6bb  8bc6                 mov eax, esi
// 007bd6bd  5e                   pop esi
// 007bd6be  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ??0CXTPCommandBarAnimation@@QAE@PAVCXTPCommandBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
