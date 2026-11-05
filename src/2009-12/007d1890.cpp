// from server: 100% by auto
// roc 2009-12 007d1890  unit: seg_007d0000  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1890
//
// 007d1890  8b06                 mov eax, dword ptr [esi]
// 007d1892  8b403c               mov eax, dword ptr [eax + 0x3c]
// 007d1895  51                   push ecx
// 007d1896  52                   push edx
// 007d1897  85c0                 test eax, eax
// 007d1899  7521                 jne 0x7d18bc
// 007d189b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007d189e  6808ee9e00           push 0x9eee08
// 007d18a3  51                   push ecx
// 007d18a4  e8d78cfcff           call 0x79a580
// 007d18a9  83c410               add esp, 0x10
// 007d18ac  6a00                 push 0
// 007d18ae  50                   push eax
// 007d18af  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d18b2  50                   push eax
// 007d18b3  e8e8390000           call 0x7d52a0
// 007d18b8  83c40c               add esp, 0xc
// 007d18bb  c3                   ret 
// 007d18bc  8b5610               mov edx, dword ptr [esi + 0x10]
// 007d18bf  50                   push eax
// 007d18c0  68e0ed9e00           push 0x9eede0
// 007d18c5  52                   push edx
// 007d18c6  e8b58cfcff           call 0x79a580
// 007d18cb  83c414               add esp, 0x14
// 007d18ce  6a00                 push 0
// 007d18d0  50                   push eax
// 007d18d1  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d18d4  50                   push eax
// 007d18d5  e8c6390000           call 0x7d52a0
// 007d18da  83c40c               add esp, 0xc
// 007d18dd  c3                   ret 
// library lua-5.1/lparser.c (function _errorlimit)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
