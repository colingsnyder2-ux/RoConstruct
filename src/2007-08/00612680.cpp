// from server: 100% by auto
// roc 2007-08 00612680  unit: seg_00610000  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00612680
//
// 00612680  53                   push ebx
// 00612681  55                   push ebp
// 00612682  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00612686  56                   push esi
// 00612687  8bf0                 mov esi, eax
// 00612689  83c601               add esi, 1
// 0061268c  56                   push esi
// 0061268d  55                   push ebp
// 0061268e  8bd8                 mov ebx, eax
// 00612690  e8abfdffff           call 0x612440
// 00612695  83c408               add esp, 8
// 00612698  83780800             cmp dword ptr [eax + 8], 0
// 0061269c  741e                 je 0x6126bc
// 0061269e  8bff                 mov edi, edi
// 006126a0  8bde                 mov ebx, esi
// 006126a2  03f6                 add esi, esi
// 006126a4  81fefdffff7f         cmp esi, 0x7ffffffd
// 006126aa  7733                 ja 0x6126df
// 006126ac  56                   push esi
// 006126ad  55                   push ebp
// 006126ae  e88dfdffff           call 0x612440
// 006126b3  83c408               add esp, 8
// 006126b6  83780800             cmp dword ptr [eax + 8], 0
// 006126ba  75e4                 jne 0x6126a0
// 006126bc  8bc6                 mov eax, esi
// 006126be  2bc3                 sub eax, ebx
// 006126c0  83f801               cmp eax, 1
// 006126c3  7655                 jbe 0x61271a
// 006126c5  57                   push edi
// 006126c6  8d3c33               lea edi, [ebx + esi]
// 006126c9  d1ef                 shr edi, 1
// 006126cb  57                   push edi
// 006126cc  55                   push ebp
// 006126cd  e86efdffff           call 0x612440
// 006126d2  83c408               add esp, 8
// 006126d5  83780800             cmp dword ptr [eax + 8], 0
// 006126d9  7533                 jne 0x61270e
// 006126db  8bf7                 mov esi, edi
// 006126dd  eb31                 jmp 0x612710
// 006126df  be01000000           mov esi, 1
// 006126e4  56                   push esi
// 006126e5  55                   push ebp
// 006126e6  e855fdffff           call 0x612440
// 006126eb  83c408               add esp, 8
// 006126ee  83780800             cmp dword ptr [eax + 8], 0
// 006126f2  7413                 je 0x612707
// 006126f4  83c601               add esi, 1
// 006126f7  56                   push esi
// 006126f8  55                   push ebp
// 006126f9  e842fdffff           call 0x612440
// 006126fe  83c408               add esp, 8
// 00612701  83780800             cmp dword ptr [eax + 8], 0
// 00612705  75ed                 jne 0x6126f4
// 00612707  8d46ff               lea eax, [esi - 1]
// 0061270a  5e                   pop esi
// 0061270b  5d                   pop ebp
// 0061270c  5b                   pop ebx
// 0061270d  c3                   ret 
// 0061270e  8bdf                 mov ebx, edi
// 00612710  8bce                 mov ecx, esi
// 00612712  2bcb                 sub ecx, ebx
// 00612714  83f901               cmp ecx, 1
// 00612717  77ad                 ja 0x6126c6
// 00612719  5f                   pop edi
// 0061271a  5e                   pop esi
// 0061271b  5d                   pop ebp
// 0061271c  8bc3                 mov eax, ebx
// 0061271e  5b                   pop ebx
// 0061271f  c3                   ret 
// library lua-5.1/ltable.c (function _unbound_search)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
