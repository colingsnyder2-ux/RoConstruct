// from server: 100% by auto
// roc 2012-06 004046d0  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004046d0
//
// 004046d0  0fbe4c2404           movsx ecx, byte ptr [esp + 4]
// 004046d5  8d41d0               lea eax, [ecx - 0x30]
// 004046d8  83f836               cmp eax, 0x36
// 004046db  7716                 ja 0x4046f3
// 004046dd  0fb69008474000       movzx edx, byte ptr [eax + 0x404708]
// 004046e4  ff2495f8464000       jmp dword ptr [edx*4 + 0x4046f8]
// 004046eb  8d41c9               lea eax, [ecx - 0x37]
// 004046ee  c3                   ret 
// 004046ef  8d41a9               lea eax, [ecx - 0x57]
// 004046f2  c3                   ret 
// 004046f3  32c0                 xor al, al
// 004046f5  c3                   ret 
// 004046f6  8bff                 mov edi, edi
// 004046f8  f5                   cmc 
// 004046f9  46                   inc esi
// 004046fa  40                   inc eax
// 004046fb  00eb                 add bl, ch
// 004046fd  46                   inc esi
// 004046fe  40                   inc eax
// 004046ff  00ef                 add bh, ch
// 00404701  46                   inc esi
// 00404702  40                   inc eax
// 00404703  00f3                 add bl, dh
// 00404705  46                   inc esi
// 00404706  40                   inc eax
// 00404707  0000                 add byte ptr [eax], al
// 00404709  0000                 add byte ptr [eax], al
// 0040470b  0000                 add byte ptr [eax], al
// 0040470d  0000                 add byte ptr [eax], al
// 0040470f  0000                 add byte ptr [eax], al
// 00404711  0003                 add byte ptr [ebx], al
// 00404713  0303                 add eax, dword ptr [ebx]
// 00404715  0303                 add eax, dword ptr [ebx]
// 00404717  0303                 add eax, dword ptr [ebx]
// 00404719  0101                 add dword ptr [ecx], eax
// 0040471b  0101                 add dword ptr [ecx], eax
// 0040471d  0101                 add dword ptr [ecx], eax
// 0040471f  0303                 add eax, dword ptr [ebx]
// 00404721  0303                 add eax, dword ptr [ebx]
// 00404723  0303                 add eax, dword ptr [ebx]
// 00404725  0303                 add eax, dword ptr [ebx]
// 00404727  0303                 add eax, dword ptr [ebx]
// 00404729  0303                 add eax, dword ptr [ebx]
// 0040472b  0303                 add eax, dword ptr [ebx]
// 0040472d  0303                 add eax, dword ptr [ebx]
// 0040472f  0303                 add eax, dword ptr [ebx]
// 00404731  0303                 add eax, dword ptr [ebx]
// 00404733  0303                 add eax, dword ptr [ebx]
// 00404735  0303                 add eax, dword ptr [ebx]
// 00404737  0303                 add eax, dword ptr [ebx]
// 00404739  0202                 add al, byte ptr [edx]
// 0040473b  0202                 add al, byte ptr [edx]
// 0040473d  0202                 add al, byte ptr [edx]
// library atl-8.0/atl.cpp (function ?ChToByte@CRegParser@ATL@@KAED@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
