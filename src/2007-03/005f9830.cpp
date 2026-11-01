// from server: 100% by auto
// roc 2007-03 005f9830  unit: seg_005f0000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9830
//
// 005f9830  56                   push esi
// 005f9831  57                   push edi
// 005f9832  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005f9836  8b7710               mov esi, dword ptr [edi + 0x10]
// 005f9839  807e1501             cmp byte ptr [esi + 0x15], 1
// 005f983d  7718                 ja 0x5f9857
// 005f983f  33c0                 xor eax, eax
// 005f9841  8d4e1c               lea ecx, [esi + 0x1c]
// 005f9844  894618               mov dword ptr [esi + 0x18], eax
// 005f9847  894e20               mov dword ptr [esi + 0x20], ecx
// 005f984a  894624               mov dword ptr [esi + 0x24], eax
// 005f984d  894628               mov dword ptr [esi + 0x28], eax
// 005f9850  89462c               mov dword ptr [esi + 0x2c], eax
// 005f9853  c6461502             mov byte ptr [esi + 0x15], 2
// 005f9857  807e1504             cmp byte ptr [esi + 0x15], 4
// 005f985b  7410                 je 0x5f986d
// 005f985d  8d4900               lea ecx, [ecx]
// 005f9860  8bc7                 mov eax, edi
// 005f9862  e849feffff           call 0x5f96b0
// 005f9867  807e1504             cmp byte ptr [esi + 0x15], 4
// 005f986b  75f3                 jne 0x5f9860
// 005f986d  e80efcffff           call 0x5f9480
// 005f9872  807e1500             cmp byte ptr [esi + 0x15], 0
// 005f9876  740d                 je 0x5f9885
// 005f9878  8bc7                 mov eax, edi
// 005f987a  e831feffff           call 0x5f96b0
// 005f987f  807e1500             cmp byte ptr [esi + 0x15], 0
// 005f9883  75f3                 jne 0x5f9878
// 005f9885  b81f85eb51           mov eax, 0x51eb851f
// 005f988a  f76648               mul dword ptr [esi + 0x48]
// 005f988d  c1ea05               shr edx, 5
// 005f9890  0faf5650             imul edx, dword ptr [esi + 0x50]
// 005f9894  5f                   pop edi
// 005f9895  895640               mov dword ptr [esi + 0x40], edx
// 005f9898  5e                   pop esi
// 005f9899  c3                   ret 
// library lua-5.1.1/lgc.c (function _luaC_fullgc)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
