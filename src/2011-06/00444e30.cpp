// from server: 100% by auto
// roc 2011-06 00444e30  unit: CPropGrid::UpdateItemsJob  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00444e30
//
// 00444e30  51                   push ecx
// 00444e31  56                   push esi
// 00444e32  57                   push edi
// 00444e33  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00444e37  8bf1                 mov esi, ecx
// 00444e39  8d442410             lea eax, [esp + 0x10]
// 00444e3d  50                   push eax
// 00444e3e  8d4c240c             lea ecx, [esp + 0xc]
// 00444e42  51                   push ecx
// 00444e43  57                   push edi
// 00444e44  8bce                 mov ecx, esi
// 00444e46  e865f8ffff           call 0x4446b0
// 00444e4b  85c0                 test eax, eax
// 00444e4d  753f                 jne 0x444e8e
// 00444e4f  394604               cmp dword ptr [esi + 4], eax
// 00444e52  7518                 jne 0x444e6c
// 00444e54  8b5608               mov edx, dword ptr [esi + 8]
// 00444e57  6a01                 push 1
// 00444e59  52                   push edx
// 00444e5a  8bce                 mov ecx, esi
// 00444e5c  e8dff7ffff           call 0x444640
// 00444e61  837e0400             cmp dword ptr [esi + 4], 0
// 00444e65  7505                 jne 0x444e6c
// 00444e67  e89e543c00           call 0x80a30a
// 00444e6c  57                   push edi
// 00444e6d  8bce                 mov ecx, esi
// 00444e6f  e89ca44700           call 0x8bf310
// 00444e74  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00444e78  89480c               mov dword ptr [eax + 0xc], ecx
// 00444e7b  8b5604               mov edx, dword ptr [esi + 4]
// 00444e7e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00444e82  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00444e85  895008               mov dword ptr [eax + 8], edx
// 00444e88  8b5604               mov edx, dword ptr [esi + 4]
// 00444e8b  89048a               mov dword ptr [edx + ecx*4], eax
// 00444e8e  5f                   pop edi
// 00444e8f  83c004               add eax, 4
// 00444e92  5e                   pop esi
// 00444e93  59                   pop ecx
// 00444e94  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
