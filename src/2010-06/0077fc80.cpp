// from server: 100% by auto
// roc 2010-06 0077fc80  unit: seg_00770000  size: 739 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0077fc80
//
// 0077fc80  83ec1c               sub esp, 0x1c
// 0077fc83  53                   push ebx
// 0077fc84  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 0077fc87  8bc7                 mov eax, edi
// 0077fc89  8bce                 mov ecx, esi
// 0077fc8b  895c2404             mov dword ptr [esp + 4], ebx
// 0077fc8f  e87cffffff           call 0x77fc10
// 0077fc94  8b4610               mov eax, dword ptr [esi + 0x10]
// 0077fc97  83e828               sub eax, 0x28
// 0077fc9a  3df6000000           cmp eax, 0xf6
// 0077fc9f  0f87ac010000         ja 0x77fe51
// 0077fca5  55                   push ebp
// 0077fca6  eb08                 jmp 0x77fcb0
// 0077fca8  8da42400000000       lea esp, [esp]
// 0077fcaf  90                   nop 
// 0077fcb0  0fb6806cfe7700       movzx eax, byte ptr [eax + 0x77fe6c]
// 0077fcb7  ff248558fe7700       jmp dword ptr [eax*4 + 0x77fe58]
// 0077fcbe  8b6e30               mov ebp, dword ptr [esi + 0x30]
// 0077fcc1  57                   push edi
// 0077fcc2  55                   push ebp
// 0077fcc3  e828050100           call 0x7901f0
// 0077fcc8  56                   push esi
// 0077fcc9  e8b23c0000           call 0x783980
// 0077fcce  83c40c               add esp, 0xc
// 0077fcd1  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 0077fcd8  7424                 je 0x77fcfe
// 0077fcda  681d010000           push 0x11d
// 0077fcdf  56                   push esi
// 0077fce0  e8ab270000           call 0x782490
// 0077fce5  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0077fce8  50                   push eax
// 0077fce9  683830a500           push 0xa53038
// 0077fcee  51                   push ecx
// 0077fcef  e8ec30fbff           call 0x732de0
// 0077fcf4  50                   push eax
// 0077fcf5  56                   push esi
// 0077fcf6  e895280000           call 0x782590
// 0077fcfb  83c41c               add esp, 0x1c
// 0077fcfe  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0077fd01  56                   push esi
// 0077fd02  e8793c0000           call 0x783980
// 0077fd07  8b5630               mov edx, dword ptr [esi + 0x30]
// 0077fd0a  53                   push ebx
// 0077fd0b  52                   push edx
// 0077fd0c  e8effa0000           call 0x78f800
// 0077fd11  89442420             mov dword ptr [esp + 0x20], eax
// 0077fd15  8d442418             lea eax, [esp + 0x18]
// 0077fd19  50                   push eax
// 0077fd1a  83c9ff               or ecx, 0xffffffff
// 0077fd1d  57                   push edi
// 0077fd1e  55                   push ebp
// 0077fd1f  894c2434             mov dword ptr [esp + 0x34], ecx
// 0077fd23  894c2438             mov dword ptr [esp + 0x38], ecx
// 0077fd27  c744242404000000     mov dword ptr [esp + 0x24], 4
// 0077fd2f  e84c0a0100           call 0x790780
// 0077fd34  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0077fd38  83c418               add esp, 0x18
// 0077fd3b  e9ff000000           jmp 0x77fe3f
// 0077fd40  57                   push edi
// 0077fd41  53                   push ebx
// 0077fd42  e8a9040100           call 0x7901f0
// 0077fd47  56                   push esi
// 0077fd48  e8333c0000           call 0x783980
// 0077fd4d  6a00                 push 0
// 0077fd4f  8d4c241c             lea ecx, [esp + 0x1c]
// 0077fd53  51                   push ecx
// 0077fd54  56                   push esi
// 0077fd55  e8a6050000           call 0x780300
// 0077fd5a  8b4630               mov eax, dword ptr [esi + 0x30]
// 0077fd5d  8d542424             lea edx, [esp + 0x24]
// 0077fd61  52                   push edx
// 0077fd62  50                   push eax
// 0077fd63  e8d8040100           call 0x790240
// 0077fd68  83c420               add esp, 0x20
// 0077fd6b  837e105d             cmp dword ptr [esi + 0x10], 0x5d
// 0077fd6f  7421                 je 0x77fd92
// 0077fd71  6a5d                 push 0x5d
// 0077fd73  56                   push esi
// 0077fd74  e817270000           call 0x782490
// 0077fd79  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0077fd7c  50                   push eax
// 0077fd7d  683830a500           push 0xa53038
// 0077fd82  51                   push ecx
// 0077fd83  e85830fbff           call 0x732de0
// 0077fd88  50                   push eax
// 0077fd89  56                   push esi
// 0077fd8a  e801280000           call 0x782590
// 0077fd8f  83c41c               add esp, 0x1c
// 0077fd92  56                   push esi
// 0077fd93  e8e83b0000           call 0x783980
// 0077fd98  8d542410             lea edx, [esp + 0x10]
// 0077fd9c  52                   push edx
// 0077fd9d  57                   push edi
// 0077fd9e  53                   push ebx
// 0077fd9f  e8dc090100           call 0x790780
// 0077fda4  83c410               add esp, 0x10
// 0077fda7  e993000000           jmp 0x77fe3f
// 0077fdac  56                   push esi
// 0077fdad  e8ce3b0000           call 0x783980
// 0077fdb2  83c404               add esp, 4
// 0077fdb5  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 0077fdbc  7424                 je 0x77fde2
// 0077fdbe  681d010000           push 0x11d
// 0077fdc3  56                   push esi
// 0077fdc4  e8c7260000           call 0x782490
// 0077fdc9  50                   push eax
// 0077fdca  8b4634               mov eax, dword ptr [esi + 0x34]
// 0077fdcd  683830a500           push 0xa53038
// 0077fdd2  50                   push eax
// 0077fdd3  e80830fbff           call 0x732de0
// 0077fdd8  50                   push eax
// 0077fdd9  56                   push esi
// 0077fdda  e8b1270000           call 0x782590
// 0077fddf  83c41c               add esp, 0x1c
// 0077fde2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0077fde5  56                   push esi
// 0077fde6  e8953b0000           call 0x783980
// 0077fdeb  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 0077fdee  53                   push ebx
// 0077fdef  51                   push ecx
// 0077fdf0  e80bfa0000           call 0x78f800
// 0077fdf5  8d542418             lea edx, [esp + 0x18]
// 0077fdf9  52                   push edx
// 0077fdfa  89442424             mov dword ptr [esp + 0x24], eax
// 0077fdfe  8b442418             mov eax, dword ptr [esp + 0x18]
// 0077fe02  83c9ff               or ecx, 0xffffffff
// 0077fe05  57                   push edi
// 0077fe06  50                   push eax
// 0077fe07  894c2434             mov dword ptr [esp + 0x34], ecx
// 0077fe0b  894c2438             mov dword ptr [esp + 0x38], ecx
// 0077fe0f  c744242404000000     mov dword ptr [esp + 0x24], 4
// 0077fe17  e834060100           call 0x790450
// 0077fe1c  57                   push edi
// 0077fe1d  8bc6                 mov eax, esi
// 0077fe1f  e8acfcffff           call 0x77fad0
// 0077fe24  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0077fe28  83c41c               add esp, 0x1c
// 0077fe2b  eb12                 jmp 0x77fe3f
// 0077fe2d  57                   push edi
// 0077fe2e  53                   push ebx
// 0077fe2f  e83c030100           call 0x790170
// 0077fe34  57                   push edi
// 0077fe35  8bc6                 mov eax, esi
// 0077fe37  e894fcffff           call 0x77fad0
// 0077fe3c  83c40c               add esp, 0xc
// 0077fe3f  8b4610               mov eax, dword ptr [esi + 0x10]
// 0077fe42  83e828               sub eax, 0x28
// 0077fe45  3df6000000           cmp eax, 0xf6
// 0077fe4a  0f8660feffff         jbe 0x77fcb0
// 0077fe50  5d                   pop ebp
// 0077fe51  5b                   pop ebx
// 0077fe52  83c41c               add esp, 0x1c
// 0077fe55  c3                   ret 
// 0077fe56  8bff                 mov edi, edi
// 0077fe58  2dfe7700be           sub eax, 0xbe0077fe
// 0077fe5d  fc                   cld 
// 0077fe5e  7700                 ja 0x77fe60
// 0077fe60  ac                   lodsb al, byte ptr [esi]
// 0077fe61  fd                   std 
// 0077fe62  7700                 ja 0x77fe64
// 0077fe64  40                   inc eax
// 0077fe65  fd                   std 
// 0077fe66  7700                 ja 0x77fe68
// 0077fe68  50                   push eax
// library lua-5.1/lparser.c (function _primaryexp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
