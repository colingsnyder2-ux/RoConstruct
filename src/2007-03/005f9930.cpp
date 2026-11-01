// from server: 100% by auto
// roc 2007-03 005f9930  unit: seg_005f0000  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9930
//
// 005f9930  8b442408             mov eax, dword ptr [esp + 8]
// 005f9934  56                   push esi
// 005f9935  57                   push edi
// 005f9936  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005f993a  8b7710               mov esi, dword ptr [edi + 0x10]
// 005f993d  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005f9940  8908                 mov dword ptr [eax], ecx
// 005f9942  89461c               mov dword ptr [esi + 0x1c], eax
// 005f9945  8a4805               mov cl, byte ptr [eax + 5]
// 005f9948  f6c107               test cl, 7
// 005f994b  753e                 jne 0x5f998b
// 005f994d  807e1501             cmp byte ptr [esi + 0x15], 1
// 005f9951  752a                 jne 0x5f997d
// 005f9953  8b5008               mov edx, dword ptr [eax + 8]
// 005f9956  80c904               or cl, 4
// 005f9959  884805               mov byte ptr [eax + 5], cl
// 005f995c  837a0804             cmp dword ptr [edx + 8], 4
// 005f9960  7c29                 jl 0x5f998b
// 005f9962  8b12                 mov edx, dword ptr [edx]
// 005f9964  f6420503             test byte ptr [edx + 5], 3
// 005f9968  7421                 je 0x5f998b
// 005f996a  f6c104               test cl, 4
// 005f996d  741c                 je 0x5f998b
// 005f996f  52                   push edx
// 005f9970  50                   push eax
// 005f9971  57                   push edi
// 005f9972  e829ffffff           call 0x5f98a0
// 005f9977  83c40c               add esp, 0xc
// 005f997a  5f                   pop edi
// 005f997b  5e                   pop esi
// 005f997c  c3                   ret 
// 005f997d  8a5614               mov dl, byte ptr [esi + 0x14]
// 005f9980  80e203               and dl, 3
// 005f9983  80e1f8               and cl, 0xf8
// 005f9986  0ad1                 or dl, cl
// 005f9988  885005               mov byte ptr [eax + 5], dl
// 005f998b  5f                   pop edi
// 005f998c  5e                   pop esi
// 005f998d  c3                   ret 
// library lua-5.1.1/lgc.c (function _luaC_linkupval)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
