// from server: 100% by auto
// roc 2009-06 00477930  unit: Ogre::RbxMeshLoader  size: 434 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00477930
//
// 00477930  51                   push ecx
// 00477931  56                   push esi
// 00477932  8bf1                 mov esi, ecx
// 00477934  8b560c               mov edx, dword ptr [esi + 0xc]
// 00477937  57                   push edi
// 00477938  85d2                 test edx, edx
// 0047793a  7504                 jne 0x477940
// 0047793c  33c9                 xor ecx, ecx
// 0047793e  eb0a                 jmp 0x47794a
// 00477940  8b4614               mov eax, dword ptr [esi + 0x14]
// 00477943  2bc2                 sub eax, edx
// 00477945  c1f802               sar eax, 2
// 00477948  8bc8                 mov ecx, eax
// 0047794a  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0047794e  85ff                 test edi, edi
// 00477950  0f8486010000         je 0x477adc
// 00477956  53                   push ebx
// 00477957  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0047795a  8bc3                 mov eax, ebx
// 0047795c  2bc2                 sub eax, edx
// 0047795e  c1f802               sar eax, 2
// 00477961  baffffff3f           mov edx, 0x3fffffff
// 00477966  2bd0                 sub edx, eax
// 00477968  3bd7                 cmp edx, edi
// 0047796a  7305                 jae 0x477971
// 0047796c  e8ef890100           call 0x490360
// 00477971  8d1438               lea edx, [eax + edi]
// 00477974  55                   push ebp
// 00477975  3bca                 cmp ecx, edx
// 00477977  0f83b5000000         jae 0x477a32
// 0047797d  8bc1                 mov eax, ecx
// 0047797f  d1e8                 shr eax, 1
// 00477981  bbffffff3f           mov ebx, 0x3fffffff
// 00477986  2bd8                 sub ebx, eax
// 00477988  3bd9                 cmp ebx, ecx
// 0047798a  730e                 jae 0x47799a
// 0047798c  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00477994  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00477998  eb06                 jmp 0x4779a0
// 0047799a  03c8                 add ecx, eax
// 0047799c  894c2410             mov dword ptr [esp + 0x10], ecx
// 004779a0  3bca                 cmp ecx, edx
// 004779a2  7306                 jae 0x4779aa
// 004779a4  89542410             mov dword ptr [esp + 0x10], edx
// 004779a8  8bca                 mov ecx, edx
// 004779aa  6a00                 push 0
// 004779ac  51                   push ecx
// 004779ad  e84e101800           call 0x5f8a00
// 004779b2  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004779b6  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 004779b9  83c408               add esp, 8
// 004779bc  8be8                 mov ebp, eax
// 004779be  8b442424             mov eax, dword ptr [esp + 0x24]
// 004779c2  50                   push eax
// 004779c3  c1fb02               sar ebx, 2
// 004779c6  57                   push edi
// 004779c7  8d4c9d00             lea ecx, [ebp + ebx*4]
// 004779cb  51                   push ecx
// 004779cc  8bce                 mov ecx, esi
// 004779ce  e89dfbffff           call 0x477570
// 004779d3  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004779d7  8b460c               mov eax, dword ptr [esi + 0xc]
// 004779da  55                   push ebp
// 004779db  52                   push edx
// 004779dc  50                   push eax
// 004779dd  8bce                 mov ecx, esi
// 004779df  e8dc182600           call 0x6d92c0
// 004779e4  8b5610               mov edx, dword ptr [esi + 0x10]
// 004779e7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004779eb  03df                 add ebx, edi
// 004779ed  8d4c9d00             lea ecx, [ebp + ebx*4]
// 004779f1  51                   push ecx
// 004779f2  52                   push edx
// 004779f3  50                   push eax
// 004779f4  8bce                 mov ecx, esi
// 004779f6  e8c5182600           call 0x6d92c0
// 004779fb  8b460c               mov eax, dword ptr [esi + 0xc]
// 004779fe  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00477a01  2bc8                 sub ecx, eax
// 00477a03  c1f902               sar ecx, 2
// 00477a06  03f9                 add edi, ecx
// 00477a08  85c0                 test eax, eax
// 00477a0a  7409                 je 0x477a15
// 00477a0c  50                   push eax
// 00477a0d  e820102a00           call 0x718a32
// 00477a12  83c404               add esp, 4
// 00477a15  8b542410             mov edx, dword ptr [esp + 0x10]
// 00477a19  8d4cbd00             lea ecx, [ebp + edi*4]
// 00477a1d  8d449500             lea eax, [ebp + edx*4]
// 00477a21  896e0c               mov dword ptr [esi + 0xc], ebp
// 00477a24  5d                   pop ebp
// 00477a25  5b                   pop ebx
// 00477a26  5f                   pop edi
// 00477a27  894614               mov dword ptr [esi + 0x14], eax
// 00477a2a  894e10               mov dword ptr [esi + 0x10], ecx
// 00477a2d  5e                   pop esi
// 00477a2e  59                   pop ecx
// 00477a2f  c21000               ret 0x10
// 00477a32  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00477a36  8bd3                 mov edx, ebx
// 00477a38  2bd0                 sub edx, eax
// 00477a3a  c1fa02               sar edx, 2
// 00477a3d  8d2cbd00000000       lea ebp, [edi*4]
// 00477a44  3bd7                 cmp edx, edi
// 00477a46  7356                 jae 0x477a9e
// 00477a48  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00477a4c  d901                 fld dword ptr [ecx]
// 00477a4e  8d1428               lea edx, [eax + ebp]
// 00477a51  52                   push edx
// 00477a52  d95c2428             fstp dword ptr [esp + 0x28]
// 00477a56  53                   push ebx
// 00477a57  50                   push eax
// 00477a58  8bce                 mov ecx, esi
// 00477a5a  e861182600           call 0x6d92c0
// 00477a5f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00477a62  8bd0                 mov edx, eax
// 00477a64  2b54241c             sub edx, dword ptr [esp + 0x1c]
// 00477a68  8d4c2424             lea ecx, [esp + 0x24]
// 00477a6c  51                   push ecx
// 00477a6d  c1fa02               sar edx, 2
// 00477a70  2bfa                 sub edi, edx
// 00477a72  57                   push edi
// 00477a73  50                   push eax
// 00477a74  8bce                 mov ecx, esi
// 00477a76  e8f5faffff           call 0x477570
// 00477a7b  016e10               add dword ptr [esi + 0x10], ebp
// 00477a7e  8b7610               mov esi, dword ptr [esi + 0x10]
// 00477a81  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00477a85  8d442424             lea eax, [esp + 0x24]
// 00477a89  50                   push eax
// 00477a8a  2bf5                 sub esi, ebp
// 00477a8c  56                   push esi
// 00477a8d  51                   push ecx
// 00477a8e  e8edebffff           call 0x476680
// 00477a93  83c40c               add esp, 0xc
// 00477a96  5d                   pop ebp
// 00477a97  5b                   pop ebx
// 00477a98  5f                   pop edi
// 00477a99  5e                   pop esi
// 00477a9a  59                   pop ecx
// 00477a9b  c21000               ret 0x10
// 00477a9e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00477aa2  d902                 fld dword ptr [edx]
// 00477aa4  53                   push ebx
// 00477aa5  8bfb                 mov edi, ebx
// 00477aa7  d95c2428             fstp dword ptr [esp + 0x28]
// 00477aab  53                   push ebx
// 00477aac  2bfd                 sub edi, ebp
// 00477aae  57                   push edi
// 00477aaf  8bce                 mov ecx, esi
// 00477ab1  e80a182600           call 0x6d92c0
// 00477ab6  53                   push ebx
// 00477ab7  894610               mov dword ptr [esi + 0x10], eax
// 00477aba  8b442420             mov eax, dword ptr [esp + 0x20]
// 00477abe  57                   push edi
// 00477abf  50                   push eax
// 00477ac0  e88bb91700           call 0x5f3450
// 00477ac5  8b442428             mov eax, dword ptr [esp + 0x28]
// 00477ac9  8d4c2430             lea ecx, [esp + 0x30]
// 00477acd  51                   push ecx
// 00477ace  03e8                 add ebp, eax
// 00477ad0  55                   push ebp
// 00477ad1  50                   push eax
// 00477ad2  e8a9ebffff           call 0x476680
// 00477ad7  83c418               add esp, 0x18
// 00477ada  5d                   pop ebp
// 00477adb  5b                   pop ebx
// 00477adc  5f                   pop edi
// 00477add  5e                   pop esi
// 00477ade  59                   pop ecx
// 00477adf  c21000               ret 0x10
// standard library vector<float> (function ?_Insert_n@?$vector@MV?$allocator@M@std@@@std@@IAEXV?$_Vector_const_iterator@MV?$allocator@M@std@@@2@IABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
