// from server: 100% by auto
// roc 2009-12 008deb50  unit: CXTColorPageCustom  size: 453 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008deb50
//
// 008deb50  83ec10               sub esp, 0x10
// 008deb53  56                   push esi
// 008deb54  57                   push edi
// 008deb55  8bf1                 mov esi, ecx
// 008deb57  e82856f1ff           call 0x7f4184
// 008deb5c  8d8614070000         lea eax, [esi + 0x714]
// 008deb62  85c0                 test eax, eax
// 008deb64  7403                 je 0x8deb69
// 008deb66  8b4020               mov eax, dword ptr [eax + 0x20]
// 008deb69  8b3dc4cb9800         mov edi, dword ptr [0x98cbc4]
// 008deb6f  6a00                 push 0
// 008deb71  50                   push eax
// 008deb72  8b8698030000         mov eax, dword ptr [esi + 0x398]
// 008deb78  6869040000           push 0x469
// 008deb7d  50                   push eax
// 008deb7e  ffd7                 call edi
// 008deb80  50                   push eax
// 008deb81  e8a44ff1ff           call 0x7f3b2a
// 008deb86  8b8e98030000         mov ecx, dword ptr [esi + 0x398]
// 008deb8c  68ff000000           push 0xff
// 008deb91  6a00                 push 0
// 008deb93  6865040000           push 0x465
// 008deb98  51                   push ecx
// 008deb99  ffd7                 call edi
// 008deb9b  8d866c060000         lea eax, [esi + 0x66c]
// 008deba1  85c0                 test eax, eax
// 008deba3  7403                 je 0x8deba8
// 008deba5  8b4020               mov eax, dword ptr [eax + 0x20]
// 008deba8  8b9640040000         mov edx, dword ptr [esi + 0x440]
// 008debae  6a00                 push 0
// 008debb0  50                   push eax
// 008debb1  6869040000           push 0x469
// 008debb6  52                   push edx
// 008debb7  ffd7                 call edi
// 008debb9  50                   push eax
// 008debba  e86b4ff1ff           call 0x7f3b2a
// 008debbf  8b8640040000         mov eax, dword ptr [esi + 0x440]
// 008debc5  68ff000000           push 0xff
// 008debca  6a00                 push 0
// 008debcc  6865040000           push 0x465
// 008debd1  50                   push eax
// 008debd2  ffd7                 call edi
// 008debd4  8d8670050000         lea eax, [esi + 0x570]
// 008debda  85c0                 test eax, eax
// 008debdc  7403                 je 0x8debe1
// 008debde  8b4020               mov eax, dword ptr [eax + 0x20]
// 008debe1  8b8e94040000         mov ecx, dword ptr [esi + 0x494]
// 008debe7  6a00                 push 0
// 008debe9  50                   push eax
// 008debea  6869040000           push 0x469
// 008debef  51                   push ecx
// 008debf0  ffd7                 call edi
// 008debf2  50                   push eax
// 008debf3  e8324ff1ff           call 0x7f3b2a
// 008debf8  8b9694040000         mov edx, dword ptr [esi + 0x494]
// 008debfe  68ff000000           push 0xff
// 008dec03  6a00                 push 0
// 008dec05  6865040000           push 0x465
// 008dec0a  52                   push edx
// 008dec0b  ffd7                 call edi
// 008dec0d  8d86c0060000         lea eax, [esi + 0x6c0]
// 008dec13  85c0                 test eax, eax
// 008dec15  7403                 je 0x8dec1a
// 008dec17  8b4020               mov eax, dword ptr [eax + 0x20]
// 008dec1a  6a00                 push 0
// 008dec1c  50                   push eax
// 008dec1d  8b86ec030000         mov eax, dword ptr [esi + 0x3ec]
// 008dec23  6869040000           push 0x469
// 008dec28  50                   push eax
// 008dec29  ffd7                 call edi
// 008dec2b  50                   push eax
// 008dec2c  e8f94ef1ff           call 0x7f3b2a
// 008dec31  8b8eec030000         mov ecx, dword ptr [esi + 0x3ec]
// 008dec37  68ff000000           push 0xff
// 008dec3c  6a00                 push 0
// 008dec3e  6865040000           push 0x465
// 008dec43  51                   push ecx
// 008dec44  ffd7                 call edi
// 008dec46  8d86c4050000         lea eax, [esi + 0x5c4]
// 008dec4c  85c0                 test eax, eax
// 008dec4e  7403                 je 0x8dec53
// 008dec50  8b4020               mov eax, dword ptr [eax + 0x20]
// 008dec53  8b96e8040000         mov edx, dword ptr [esi + 0x4e8]
// 008dec59  6a00                 push 0
// 008dec5b  50                   push eax
// 008dec5c  6869040000           push 0x469
// 008dec61  52                   push edx
// 008dec62  ffd7                 call edi
// 008dec64  50                   push eax
// 008dec65  e8c04ef1ff           call 0x7f3b2a
// 008dec6a  8b86e8040000         mov eax, dword ptr [esi + 0x4e8]
// 008dec70  68ff000000           push 0xff
// 008dec75  6a00                 push 0
// 008dec77  6865040000           push 0x465
// 008dec7c  50                   push eax
// 008dec7d  ffd7                 call edi
// 008dec7f  8d8618060000         lea eax, [esi + 0x618]
// 008dec85  85c0                 test eax, eax
// 008dec87  7403                 je 0x8dec8c
// 008dec89  8b4020               mov eax, dword ptr [eax + 0x20]
// 008dec8c  8b8e3c050000         mov ecx, dword ptr [esi + 0x53c]
// 008dec92  6a00                 push 0
// 008dec94  50                   push eax
// 008dec95  6869040000           push 0x469
// 008dec9a  51                   push ecx
// 008dec9b  ffd7                 call edi
// 008dec9d  50                   push eax
// 008dec9e  e8874ef1ff           call 0x7f3b2a
// 008deca3  8b963c050000         mov edx, dword ptr [esi + 0x53c]
// 008deca9  68ff000000           push 0xff
// 008decae  6a00                 push 0
// 008decb0  6865040000           push 0x465
// 008decb5  52                   push edx
// 008decb6  ffd7                 call edi
// 008decb8  8b8e28010000         mov ecx, dword ptr [esi + 0x128]
// 008decbe  8d442408             lea eax, [esp + 8]
// 008decc2  50                   push eax
// 008decc3  51                   push ecx
// 008decc4  ff1570cc9800         call dword ptr [0x98cc70]
// 008decca  8d542408             lea edx, [esp + 8]
// 008decce  52                   push edx
// 008deccf  8bce                 mov ecx, esi
// 008decd1  e8025bf1ff           call 0x7f47d8
// 008decd6  6a04                 push 4
// 008decd8  6a00                 push 0
// 008decda  8d442410             lea eax, [esp + 0x10]
// 008decde  50                   push eax
// 008decdf  ff1558ca9800         call dword ptr [0x98ca58]
// 008dece5  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008dece9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008deced  8b542410             mov edx, dword ptr [esp + 0x10]
// 008decf1  6a01                 push 1
// 008decf3  2bc8                 sub ecx, eax
// 008decf5  51                   push ecx
// 008decf6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008decfa  2bd1                 sub edx, ecx
// 008decfc  52                   push edx
// 008decfd  50                   push eax
// 008decfe  51                   push ecx
// 008decff  8d8e08010000         lea ecx, [esi + 0x108]
// 008ded05  e8284ff1ff           call 0x7f3c32
// 008ded0a  5f                   pop edi
// 008ded0b  b801000000           mov eax, 1
// 008ded10  5e                   pop esi
// 008ded11  83c410               add esp, 0x10
// 008ded14  c3                   ret 
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnInitDialog@CXTPColorPageCustom@@MAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
