// from server: 100% by auto
// roc 2007-03 00681930  unit: seg_00680000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00681930
//
// 00681930  8b442410             mov eax, dword ptr [esp + 0x10]
// 00681934  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00681938  50                   push eax
// 00681939  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068193d  52                   push edx
// 0068193e  50                   push eax
// 0068193f  6a05                 push 5
// 00681941  e80affffff           call 0x681850
// 00681946  85c0                 test eax, eax
// 00681948  7522                 jne 0x68196c
// 0068194a  8b442404             mov eax, dword ptr [esp + 4]
// 0068194e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00681952  8b542418             mov edx, dword ptr [esp + 0x18]
// 00681956  8908                 mov dword ptr [eax], ecx
// 00681958  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0068195c  895004               mov dword ptr [eax + 4], edx
// 0068195f  8b542420             mov edx, dword ptr [esp + 0x20]
// 00681963  894808               mov dword ptr [eax + 8], ecx
// 00681966  89500c               mov dword ptr [eax + 0xc], edx
// 00681969  c22000               ret 0x20
// 0068196c  56                   push esi
// 0068196d  8b742408             mov esi, dword ptr [esp + 8]
// 00681971  83c008               add eax, 8
// 00681974  50                   push eax
// 00681975  56                   push esi
// 00681976  ff1550ed7700         call dword ptr [0x77ed50]
// 0068197c  8bc6                 mov eax, esi
// 0068197e  5e                   pop esi
// 0068197f  c22000               ret 0x20
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ?GetThemeRect@CXTPSkinManagerClass@@QAE?AVCRect@@HHHV2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp
