// from server: 100% by auto
// roc 2009-06 00804060  unit: CXTColorPageCustom  size: 453 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00804060
//
// 00804060  83ec10               sub esp, 0x10
// 00804063  56                   push esi
// 00804064  57                   push edi
// 00804065  8bf1                 mov esi, ecx
// 00804067  e8f052f1ff           call 0x71935c
// 0080406c  8d8614070000         lea eax, [esi + 0x714]
// 00804072  85c0                 test eax, eax
// 00804074  7403                 je 0x804079
// 00804076  8b4020               mov eax, dword ptr [eax + 0x20]
// 00804079  8b3d90ee8900         mov edi, dword ptr [0x89ee90]
// 0080407f  6a00                 push 0
// 00804081  50                   push eax
// 00804082  8b8698030000         mov eax, dword ptr [esi + 0x398]
// 00804088  6869040000           push 0x469
// 0080408d  50                   push eax
// 0080408e  ffd7                 call edi
// 00804090  50                   push eax
// 00804091  e86c4cf1ff           call 0x718d02
// 00804096  8b8e98030000         mov ecx, dword ptr [esi + 0x398]
// 0080409c  68ff000000           push 0xff
// 008040a1  6a00                 push 0
// 008040a3  6865040000           push 0x465
// 008040a8  51                   push ecx
// 008040a9  ffd7                 call edi
// 008040ab  8d866c060000         lea eax, [esi + 0x66c]
// 008040b1  85c0                 test eax, eax
// 008040b3  7403                 je 0x8040b8
// 008040b5  8b4020               mov eax, dword ptr [eax + 0x20]
// 008040b8  8b9640040000         mov edx, dword ptr [esi + 0x440]
// 008040be  6a00                 push 0
// 008040c0  50                   push eax
// 008040c1  6869040000           push 0x469
// 008040c6  52                   push edx
// 008040c7  ffd7                 call edi
// 008040c9  50                   push eax
// 008040ca  e8334cf1ff           call 0x718d02
// 008040cf  8b8640040000         mov eax, dword ptr [esi + 0x440]
// 008040d5  68ff000000           push 0xff
// 008040da  6a00                 push 0
// 008040dc  6865040000           push 0x465
// 008040e1  50                   push eax
// 008040e2  ffd7                 call edi
// 008040e4  8d8670050000         lea eax, [esi + 0x570]
// 008040ea  85c0                 test eax, eax
// 008040ec  7403                 je 0x8040f1
// 008040ee  8b4020               mov eax, dword ptr [eax + 0x20]
// 008040f1  8b8e94040000         mov ecx, dword ptr [esi + 0x494]
// 008040f7  6a00                 push 0
// 008040f9  50                   push eax
// 008040fa  6869040000           push 0x469
// 008040ff  51                   push ecx
// 00804100  ffd7                 call edi
// 00804102  50                   push eax
// 00804103  e8fa4bf1ff           call 0x718d02
// 00804108  8b9694040000         mov edx, dword ptr [esi + 0x494]
// 0080410e  68ff000000           push 0xff
// 00804113  6a00                 push 0
// 00804115  6865040000           push 0x465
// 0080411a  52                   push edx
// 0080411b  ffd7                 call edi
// 0080411d  8d86c0060000         lea eax, [esi + 0x6c0]
// 00804123  85c0                 test eax, eax
// 00804125  7403                 je 0x80412a
// 00804127  8b4020               mov eax, dword ptr [eax + 0x20]
// 0080412a  6a00                 push 0
// 0080412c  50                   push eax
// 0080412d  8b86ec030000         mov eax, dword ptr [esi + 0x3ec]
// 00804133  6869040000           push 0x469
// 00804138  50                   push eax
// 00804139  ffd7                 call edi
// 0080413b  50                   push eax
// 0080413c  e8c14bf1ff           call 0x718d02
// 00804141  8b8eec030000         mov ecx, dword ptr [esi + 0x3ec]
// 00804147  68ff000000           push 0xff
// 0080414c  6a00                 push 0
// 0080414e  6865040000           push 0x465
// 00804153  51                   push ecx
// 00804154  ffd7                 call edi
// 00804156  8d86c4050000         lea eax, [esi + 0x5c4]
// 0080415c  85c0                 test eax, eax
// 0080415e  7403                 je 0x804163
// 00804160  8b4020               mov eax, dword ptr [eax + 0x20]
// 00804163  8b96e8040000         mov edx, dword ptr [esi + 0x4e8]
// 00804169  6a00                 push 0
// 0080416b  50                   push eax
// 0080416c  6869040000           push 0x469
// 00804171  52                   push edx
// 00804172  ffd7                 call edi
// 00804174  50                   push eax
// 00804175  e8884bf1ff           call 0x718d02
// 0080417a  8b86e8040000         mov eax, dword ptr [esi + 0x4e8]
// 00804180  68ff000000           push 0xff
// 00804185  6a00                 push 0
// 00804187  6865040000           push 0x465
// 0080418c  50                   push eax
// 0080418d  ffd7                 call edi
// 0080418f  8d8618060000         lea eax, [esi + 0x618]
// 00804195  85c0                 test eax, eax
// 00804197  7403                 je 0x80419c
// 00804199  8b4020               mov eax, dword ptr [eax + 0x20]
// 0080419c  8b8e3c050000         mov ecx, dword ptr [esi + 0x53c]
// 008041a2  6a00                 push 0
// 008041a4  50                   push eax
// 008041a5  6869040000           push 0x469
// 008041aa  51                   push ecx
// 008041ab  ffd7                 call edi
// 008041ad  50                   push eax
// 008041ae  e84f4bf1ff           call 0x718d02
// 008041b3  8b963c050000         mov edx, dword ptr [esi + 0x53c]
// 008041b9  68ff000000           push 0xff
// 008041be  6a00                 push 0
// 008041c0  6865040000           push 0x465
// 008041c5  52                   push edx
// 008041c6  ffd7                 call edi
// 008041c8  8b8e28010000         mov ecx, dword ptr [esi + 0x128]
// 008041ce  8d442408             lea eax, [esp + 8]
// 008041d2  50                   push eax
// 008041d3  51                   push ecx
// 008041d4  ff15f4ed8900         call dword ptr [0x89edf4]
// 008041da  8d542408             lea edx, [esp + 8]
// 008041de  52                   push edx
// 008041df  8bce                 mov ecx, esi
// 008041e1  e8be57f1ff           call 0x7199a4
// 008041e6  6a04                 push 4
// 008041e8  6a00                 push 0
// 008041ea  8d442410             lea eax, [esp + 0x10]
// 008041ee  50                   push eax
// 008041ef  ff15bced8900         call dword ptr [0x89edbc]
// 008041f5  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008041f9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008041fd  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804201  6a01                 push 1
// 00804203  2bc8                 sub ecx, eax
// 00804205  51                   push ecx
// 00804206  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0080420a  2bd1                 sub edx, ecx
// 0080420c  52                   push edx
// 0080420d  50                   push eax
// 0080420e  51                   push ecx
// 0080420f  8d8e08010000         lea ecx, [esi + 0x108]
// 00804215  e8f04bf1ff           call 0x718e0a
// 0080421a  5f                   pop edi
// 0080421b  b801000000           mov eax, 1
// 00804220  5e                   pop esi
// 00804221  83c410               add esp, 0x10
// 00804224  c3                   ret 
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnInitDialog@CXTPColorPageCustom@@MAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
