// from server: 100% by auto
// roc 2012-06 00647000  unit: seg_00640000  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00647000
//
// 00647000  53                   push ebx
// 00647001  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00647005  85db                 test ebx, ebx
// 00647007  0f84e1000000         je 0x6470ee
// 0064700d  56                   push esi
// 0064700e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00647012  85f6                 test esi, esi
// 00647014  0f84d3000000         je 0x6470ed
// 0064701a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0064701e  85c0                 test eax, eax
// 00647020  0f84c7000000         je 0x6470ed
// 00647026  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 0064702b  0f84bc000000         je 0x6470ed
// 00647031  8d5001               lea edx, [eax + 1]
// 00647034  8a08                 mov cl, byte ptr [eax]
// 00647036  40                   inc eax
// 00647037  84c9                 test cl, cl
// 00647039  75f9                 jne 0x647034
// 0064703b  55                   push ebp
// 0064703c  2bc2                 sub eax, edx
// 0064703e  57                   push edi
// 0064703f  8d6801               lea ebp, [eax + 1]
// 00647042  55                   push ebp
// 00647043  53                   push ebx
// 00647044  e807750000           call 0x64e550
// 00647049  8bf8                 mov edi, eax
// 0064704b  83c408               add esp, 8
// 0064704e  85ff                 test edi, edi
// 00647050  7513                 jne 0x647065
// 00647052  684863b800           push 0xb86348
// 00647057  53                   push ebx
// 00647058  e803720000           call 0x64e260
// 0064705d  83c408               add esp, 8
// 00647060  5f                   pop edi
// 00647061  5d                   pop ebp
// 00647062  5e                   pop esi
// 00647063  5b                   pop ebx
// 00647064  c3                   ret 
// 00647065  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00647069  55                   push ebp
// 0064706a  50                   push eax
// 0064706b  57                   push edi
// 0064706c  e8ebc53300           call 0x98365c
// 00647071  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00647075  55                   push ebp
// 00647076  53                   push ebx
// 00647077  e8d4740000           call 0x64e550
// 0064707c  8bd8                 mov ebx, eax
// 0064707e  83c414               add esp, 0x14
// 00647081  85db                 test ebx, ebx
// 00647083  751e                 jne 0x6470a3
// 00647085  8b742414             mov esi, dword ptr [esp + 0x14]
// 00647089  57                   push edi
// 0064708a  56                   push esi
// 0064708b  e890740000           call 0x64e520
// 00647090  681863b800           push 0xb86318
// 00647095  56                   push esi
// 00647096  e8c5710000           call 0x64e260
// 0064709b  83c410               add esp, 0x10
// 0064709e  5f                   pop edi
// 0064709f  5d                   pop ebp
// 006470a0  5e                   pop esi
// 006470a1  5b                   pop ebx
// 006470a2  c3                   ret 
// 006470a3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006470a7  55                   push ebp
// 006470a8  51                   push ecx
// 006470a9  53                   push ebx
// 006470aa  e8adc53300           call 0x98365c
// 006470af  8b542420             mov edx, dword ptr [esp + 0x20]
// 006470b3  6a00                 push 0
// 006470b5  6a10                 push 0x10
// 006470b7  56                   push esi
// 006470b8  52                   push edx
// 006470b9  e8226effff           call 0x63dee0
// 006470be  8a44243c             mov al, byte ptr [esp + 0x3c]
// 006470c2  838eb800000010       or dword ptr [esi + 0xb8], 0x10
// 006470c9  83c41c               add esp, 0x1c
// 006470cc  814e0800100000       or dword ptr [esi + 8], 0x1000
// 006470d3  89bec4000000         mov dword ptr [esi + 0xc4], edi
// 006470d9  5f                   pop edi
// 006470da  89aecc000000         mov dword ptr [esi + 0xcc], ebp
// 006470e0  899ec8000000         mov dword ptr [esi + 0xc8], ebx
// 006470e6  8886d0000000         mov byte ptr [esi + 0xd0], al
// 006470ec  5d                   pop ebp
// 006470ed  5e                   pop esi
// 006470ee  5b                   pop ebx
// 006470ef  c3                   ret 
// library libpng-1.2.24/pngset.c (function _png_set_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngset.c
