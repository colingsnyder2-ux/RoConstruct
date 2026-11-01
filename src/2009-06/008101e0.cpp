// from server: 100% by auto
// roc 2009-06 008101e0  unit: CXTPScrollBase  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008101e0
//
// 008101e0  8b442404             mov eax, dword ptr [esp + 4]
// 008101e4  56                   push esi
// 008101e5  8bf1                 mov esi, ecx
// 008101e7  837e5c00             cmp dword ptr [esi + 0x5c], 0
// 008101eb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008101ef  57                   push edi
// 008101f0  8bf9                 mov edi, ecx
// 008101f2  7502                 jne 0x8101f6
// 008101f4  8bf8                 mov edi, eax
// 008101f6  51                   push ecx
// 008101f7  50                   push eax
// 008101f8  8d4648               lea eax, [esi + 0x48]
// 008101fb  50                   push eax
// 008101fc  ff15c0ed8900         call dword ptr [0x89edc0]
// 00810202  85c0                 test eax, eax
// 00810204  7505                 jne 0x81020b
// 00810206  5f                   pop edi
// 00810207  5e                   pop esi
// 00810208  c20800               ret 8
// 0081020b  3b7e28               cmp edi, dword ptr [esi + 0x28]
// 0081020e  7d0a                 jge 0x81021a
// 00810210  5f                   pop edi
// 00810211  b83c000000           mov eax, 0x3c
// 00810216  5e                   pop esi
// 00810217  c20800               ret 8
// 0081021a  8b463c               mov eax, dword ptr [esi + 0x3c]
// 0081021d  85c0                 test eax, eax
// 0081021f  7e0e                 jle 0x81022f
// 00810221  3bf8                 cmp edi, eax
// 00810223  7e0a                 jle 0x81022f
// 00810225  5f                   pop edi
// 00810226  b841000000           mov eax, 0x41
// 0081022b  5e                   pop esi
// 0081022c  c20800               ret 8
// 0081022f  3b7e2c               cmp edi, dword ptr [esi + 0x2c]
// 00810232  7c0a                 jl 0x81023e
// 00810234  5f                   pop edi
// 00810235  b83d000000           mov eax, 0x3d
// 0081023a  5e                   pop esi
// 0081023b  c20800               ret 8
// 0081023e  3b7e38               cmp edi, dword ptr [esi + 0x38]
// 00810241  7d0a                 jge 0x81024d
// 00810243  5f                   pop edi
// 00810244  b83e000000           mov eax, 0x3e
// 00810249  5e                   pop esi
// 0081024a  c20800               ret 8
// 0081024d  33c0                 xor eax, eax
// 0081024f  3b7e34               cmp edi, dword ptr [esi + 0x34]
// 00810252  5f                   pop edi
// 00810253  0f9cc0               setl al
// 00810256  5e                   pop esi
// 00810257  83c03f               add eax, 0x3f
// 0081025a  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?HitTestScrollBar@CXTPScrollBase@@QBEHUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
