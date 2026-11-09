// from server: 100% by auto
// roc 2009-06 00405f20  unit: VCApp::?$IObjectSafetyRobloxImpl  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00405f20
//
// 00405f20  53                   push ebx
// 00405f21  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00405f25  56                   push esi
// 00405f26  85db                 test ebx, ebx
// 00405f28  0f84d1000000         je 0x405fff
// 00405f2e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00405f32  85f6                 test esi, esi
// 00405f34  0f84c5000000         je 0x405fff
// 00405f3a  55                   push ebp
// 00405f3b  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00405f3f  85ed                 test ebp, ebp
// 00405f41  750b                 jne 0x405f4e
// 00405f43  5d                   pop ebp
// 00405f44  5e                   pop esi
// 00405f45  b803400080           mov eax, 0x80004003
// 00405f4a  5b                   pop ebx
// 00405f4b  c21000               ret 0x10
// 00405f4e  57                   push edi
// 00405f4f  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00405f53  57                   push edi
// 00405f54  c7450000000000       mov dword ptr [ebp], 0
// 00405f5b  e8a0ebffff           call 0x404b00
// 00405f60  85c0                 test eax, eax
// 00405f62  741a                 je 0x405f7e
// 00405f64  8b7604               mov esi, dword ptr [esi + 4]
// 00405f67  8b041e               mov eax, dword ptr [esi + ebx]
// 00405f6a  8b4804               mov ecx, dword ptr [eax + 4]
// 00405f6d  03f3                 add esi, ebx
// 00405f6f  56                   push esi
// 00405f70  ffd1                 call ecx
// 00405f72  897500               mov dword ptr [ebp], esi
// 00405f75  33c0                 xor eax, eax
// 00405f77  5f                   pop edi
// 00405f78  5d                   pop ebp
// 00405f79  5e                   pop esi
// 00405f7a  5b                   pop ebx
// 00405f7b  c21000               ret 0x10
// 00405f7e  8b4e08               mov ecx, dword ptr [esi + 8]
// 00405f81  85c9                 test ecx, ecx
// 00405f83  7453                 je 0x405fd8
// 00405f85  8b06                 mov eax, dword ptr [esi]
// 00405f87  33db                 xor ebx, ebx
// 00405f89  85c0                 test eax, eax
// 00405f8b  0f94c3               sete bl
// 00405f8e  85db                 test ebx, ebx
// 00405f90  751e                 jne 0x405fb0
// 00405f92  8b10                 mov edx, dword ptr [eax]
// 00405f94  3b17                 cmp edx, dword ptr [edi]
// 00405f96  7536                 jne 0x405fce
// 00405f98  8b5004               mov edx, dword ptr [eax + 4]
// 00405f9b  3b5704               cmp edx, dword ptr [edi + 4]
// 00405f9e  752e                 jne 0x405fce
// 00405fa0  8b5008               mov edx, dword ptr [eax + 8]
// 00405fa3  3b5708               cmp edx, dword ptr [edi + 8]
// 00405fa6  7526                 jne 0x405fce
// 00405fa8  8b400c               mov eax, dword ptr [eax + 0xc]
// 00405fab  3b470c               cmp eax, dword ptr [edi + 0xc]
// 00405fae  751e                 jne 0x405fce
// 00405fb0  83f901               cmp ecx, 1
// 00405fb3  742f                 je 0x405fe4
// 00405fb5  8b5604               mov edx, dword ptr [esi + 4]
// 00405fb8  8b442414             mov eax, dword ptr [esp + 0x14]
// 00405fbc  52                   push edx
// 00405fbd  55                   push ebp
// 00405fbe  57                   push edi
// 00405fbf  50                   push eax
// 00405fc0  ffd1                 call ecx
// 00405fc2  85c0                 test eax, eax
// 00405fc4  74b1                 je 0x405f77
// 00405fc6  85db                 test ebx, ebx
// 00405fc8  7504                 jne 0x405fce
// 00405fca  85c0                 test eax, eax
// 00405fcc  7ca9                 jl 0x405f77
// 00405fce  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00405fd1  83c60c               add esi, 0xc
// 00405fd4  85c9                 test ecx, ecx
// 00405fd6  75ad                 jne 0x405f85
// 00405fd8  5f                   pop edi
// 00405fd9  5d                   pop ebp
// 00405fda  5e                   pop esi
// 00405fdb  b802400080           mov eax, 0x80004002
// 00405fe0  5b                   pop ebx
// 00405fe1  c21000               ret 0x10
// 00405fe4  8b7604               mov esi, dword ptr [esi + 4]
// 00405fe7  03742414             add esi, dword ptr [esp + 0x14]
// 00405feb  8b0e                 mov ecx, dword ptr [esi]
// 00405fed  8b5104               mov edx, dword ptr [ecx + 4]
// 00405ff0  56                   push esi
// 00405ff1  ffd2                 call edx
// 00405ff3  5f                   pop edi
// 00405ff4  897500               mov dword ptr [ebp], esi
// 00405ff7  5d                   pop ebp
// 00405ff8  5e                   pop esi
// 00405ff9  33c0                 xor eax, eax
// 00405ffb  5b                   pop ebx
// 00405ffc  c21000               ret 0x10
// 00405fff  5e                   pop esi
// 00406000  b857000780           mov eax, 0x80070057
// 00406005  5b                   pop ebx
// 00406006  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?AtlInternalQueryInterface@ATL@@YGJPAXPBU_ATL_INTMAP_ENTRY@1@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
