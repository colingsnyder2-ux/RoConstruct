// from server: 100% by auto
// roc 2012-06 00404310  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404310
//
// 00404310  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00404314  85c9                 test ecx, ecx
// 00404316  744b                 je 0x404363
// 00404318  56                   push esi
// 00404319  57                   push edi
// 0040431a  8d79ff               lea edi, [ecx - 1]
// 0040431d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00404321  33c0                 xor eax, eax
// 00404323  85ff                 test edi, edi
// 00404325  7635                 jbe 0x40435c
// 00404327  8b742414             mov esi, dword ptr [esp + 0x14]
// 0040432b  eb03                 jmp 0x404330
// 0040432d  8d4900               lea ecx, [ecx]
// 00404330  0fb716               movzx edx, word ptr [esi]
// 00404333  6685d2               test dx, dx
// 00404336  7424                 je 0x40435c
// 00404338  668911               mov word ptr [ecx], dx
// 0040433b  83c102               add ecx, 2
// 0040433e  66833e27             cmp word ptr [esi], 0x27
// 00404342  7510                 jne 0x404354
// 00404344  40                   inc eax
// 00404345  3bc7                 cmp eax, edi
// 00404347  730b                 jae 0x404354
// 00404349  ba27000000           mov edx, 0x27
// 0040434e  668911               mov word ptr [ecx], dx
// 00404351  83c102               add ecx, 2
// 00404354  40                   inc eax
// 00404355  83c602               add esi, 2
// 00404358  3bc7                 cmp eax, edi
// 0040435a  72d4                 jb 0x404330
// 0040435c  33c0                 xor eax, eax
// 0040435e  5f                   pop edi
// 0040435f  668901               mov word ptr [ecx], ax
// 00404362  5e                   pop esi
// 00404363  c3                   ret 
// library atl-9.0/atl.cpp (function ?EscapeSingleQuote@CAtlModule@ATL@@SAXPA_WIPB_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
