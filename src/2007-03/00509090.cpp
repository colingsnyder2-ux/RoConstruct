// from server: 100% by auto
// roc 2007-03 00509090  unit: seg_00500000  size: 827 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509090
//
// 00509090  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00509094  85c9                 test ecx, ecx
// 00509096  0f842e030000         je 0x5093ca
// 0050909c  56                   push esi
// 0050909d  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005090a1  85f6                 test esi, esi
// 005090a3  0f8420030000         je 0x5093c9
// 005090a9  d9ee                 fldz 
// 005090ab  dd442410             fld qword ptr [esp + 0x10]
// 005090af  d8d1                 fcom st(1)
// 005090b1  dfe0                 fnstsw ax
// 005090b3  f6c405               test ah, 5
// 005090b6  0f8bfb020000         jnp 0x5093b7
// 005090bc  dd442418             fld qword ptr [esp + 0x18]
// 005090c0  d8d2                 fcom st(2)
// 005090c2  dfe0                 fnstsw ax
// 005090c4  f6c405               test ah, 5
// 005090c7  0f8b96020000         jnp 0x509363
// 005090cd  d9ca                 fxch st(2)
// 005090cf  dc542420             fcom qword ptr [esp + 0x20]
// 005090d3  dfe0                 fnstsw ax
// 005090d5  f6c441               test ah, 0x41
// 005090d8  0f84bb020000         je 0x509399
// 005090de  dc542428             fcom qword ptr [esp + 0x28]
// 005090e2  dfe0                 fnstsw ax
// 005090e4  f6c441               test ah, 0x41
// 005090e7  0f84ac020000         je 0x509399
// 005090ed  dd442430             fld qword ptr [esp + 0x30]
// 005090f1  d8d1                 fcom st(1)
// 005090f3  dfe0                 fnstsw ax
// 005090f5  f6c405               test ah, 5
// 005090f8  0f8bb5020000         jnp 0x5093b3
// 005090fe  dd442438             fld qword ptr [esp + 0x38]
// 00509102  d8d2                 fcom st(2)
// 00509104  dfe0                 fnstsw ax
// 00509106  f6c405               test ah, 5
// 00509109  0f8b6a020000         jnp 0x509379
// 0050910f  dd442440             fld qword ptr [esp + 0x40]
// 00509113  d8d3                 fcom st(3)
// 00509115  dfe0                 fnstsw ax
// 00509117  f6c405               test ah, 5
// 0050911a  0f8b73020000         jnp 0x509393
// 00509120  dd442448             fld qword ptr [esp + 0x48]
// 00509124  d8d4                 fcom st(4)
// 00509126  dfe0                 fnstsw ax
// 00509128  dddc                 fstp st(4)
// 0050912a  f6c405               test ah, 5
// 0050912d  0f8b7c020000         jnp 0x5093af
// 00509133  dd05d8097a00         fld qword ptr [0x7a09d8]
// 00509139  d8d5                 fcom st(5)
// 0050913b  dfe0                 fnstsw ax
// 0050913d  f6c405               test ah, 5
// 00509140  0f8b4f010000         jnp 0x509295
// 00509146  d8d6                 fcom st(6)
// 00509148  dfe0                 fnstsw ax
// 0050914a  ddde                 fstp st(6)
// 0050914c  f6c405               test ah, 5
// 0050914f  0f8b5e010000         jnp 0x5092b3
// 00509155  d9cd                 fxch st(5)
// 00509157  dc542420             fcom qword ptr [esp + 0x20]
// 0050915b  dfe0                 fnstsw ax
// 0050915d  f6c405               test ah, 5
// 00509160  0f8b69010000         jnp 0x5092cf
// 00509166  dd442428             fld qword ptr [esp + 0x28]
// 0050916a  d8d1                 fcom st(1)
// 0050916c  dfe0                 fnstsw ax
// 0050916e  f6c441               test ah, 0x41
// 00509171  0f8474010000         je 0x5092eb
// 00509177  d9cb                 fxch st(3)
// 00509179  d8d1                 fcom st(1)
// 0050917b  dfe0                 fnstsw ax
// 0050917d  f6c441               test ah, 0x41
// 00509180  0f8483010000         je 0x509309
// 00509186  d9ca                 fxch st(2)
// 00509188  d8d1                 fcom st(1)
// 0050918a  dfe0                 fnstsw ax
// 0050918c  f6c441               test ah, 0x41
// 0050918f  0f8492010000         je 0x509327
// 00509195  d9ce                 fxch st(6)
// 00509197  d8d1                 fcom st(1)
// 00509199  dfe0                 fnstsw ax
// 0050919b  f6c441               test ah, 0x41
// 0050919e  0f84a1010000         je 0x509345
// 005091a4  d9c9                 fxch st(1)
// 005091a6  d8dc                 fcomp st(4)
// 005091a8  dfe0                 fnstsw ax
// 005091aa  f6c405               test ah, 5
// 005091ad  0f8b94010000         jnp 0x509347
// 005091b3  d9cc                 fxch st(4)
// 005091b5  d99680000000         fst dword ptr [esi + 0x80]
// 005091bb  dd442418             fld qword ptr [esp + 0x18]
// 005091bf  d99e84000000         fstp dword ptr [esi + 0x84]
// 005091c5  dd442420             fld qword ptr [esp + 0x20]
// 005091c9  d99e88000000         fstp dword ptr [esi + 0x88]
// 005091cf  d9ca                 fxch st(2)
// 005091d1  d99e8c000000         fstp dword ptr [esi + 0x8c]
// 005091d7  d99690000000         fst dword ptr [esi + 0x90]
// 005091dd  d9cc                 fxch st(4)
// 005091df  d99694000000         fst dword ptr [esi + 0x94]
// 005091e5  d9cb                 fxch st(3)
// 005091e7  d99698000000         fst dword ptr [esi + 0x98]
// 005091ed  d9ca                 fxch st(2)
// 005091ef  d9969c000000         fst dword ptr [esi + 0x9c]
// 005091f5  dd05d0097a00         fld qword ptr [0x7a09d0]
// 005091fb  dcca                 fmul st(2), st(0)
// 005091fd  dd05584f7900         fld qword ptr [0x794f58]
// 00509203  dcc3                 fadd st(3), st(0)
// 00509205  d9cb                 fxch st(3)
// 00509207  e8f45f1100           call 0x61f200
// 0050920c  dd442418             fld qword ptr [esp + 0x18]
// 00509210  d8c9                 fmul st(1)
// 00509212  898600010000         mov dword ptr [esi + 0x100], eax
// 00509218  d8c3                 fadd st(3)
// 0050921a  e8e15f1100           call 0x61f200
// 0050921f  dd442420             fld qword ptr [esp + 0x20]
// 00509223  d8c9                 fmul st(1)
// 00509225  898604010000         mov dword ptr [esi + 0x104], eax
// 0050922b  d8c3                 fadd st(3)
// 0050922d  e8ce5f1100           call 0x61f200
// 00509232  dd442428             fld qword ptr [esp + 0x28]
// 00509236  d8c9                 fmul st(1)
// 00509238  898608010000         mov dword ptr [esi + 0x108], eax
// 0050923e  d8c3                 fadd st(3)
// 00509240  e8bb5f1100           call 0x61f200
// 00509245  dccd                 fmul st(5), st(0)
// 00509247  d9cd                 fxch st(5)
// 00509249  89860c010000         mov dword ptr [esi + 0x10c], eax
// 0050924f  d8c2                 fadd st(2)
// 00509251  e8aa5f1100           call 0x61f200
// 00509256  d9cb                 fxch st(3)
// 00509258  d8cc                 fmul st(4)
// 0050925a  898610010000         mov dword ptr [esi + 0x110], eax
// 00509260  d8c1                 fadd st(1)
// 00509262  e8995f1100           call 0x61f200
// 00509267  d9c9                 fxch st(1)
// 00509269  d8cb                 fmul st(3)
// 0050926b  898614010000         mov dword ptr [esi + 0x114], eax
// 00509271  d8c1                 fadd st(1)
// 00509273  e8885f1100           call 0x61f200
// 00509278  d9c9                 fxch st(1)
// 0050927a  deca                 fmulp st(2)
// 0050927c  898618010000         mov dword ptr [esi + 0x118], eax
// 00509282  dec1                 faddp st(1)
// 00509284  e8775f1100           call 0x61f200
// 00509289  834e0804             or dword ptr [esi + 8], 4
// 0050928d  89861c010000         mov dword ptr [esi + 0x11c], eax
// 00509293  5e                   pop esi
// 00509294  c3                   ret 
// 00509295  ddd8                 fstp st(0)
// 00509297  688c097a00           push 0x7a098c
// 0050929c  dddc                 fstp st(4)
// 0050929e  51                   push ecx
// 0050929f  dddc                 fstp st(4)
// 005092a1  ddd9                 fstp st(1)
// 005092a3  ddd9                 fstp st(1)
// 005092a5  ddd9                 fstp st(1)
// 005092a7  ddd8                 fstp st(0)
// 005092a9  e822f10000           call 0x5183d0
// 005092ae  83c408               add esp, 8
// 005092b1  5e                   pop esi
// 005092b2  c3                   ret 
// 005092b3  dddd                 fstp st(5)
// 005092b5  688c097a00           push 0x7a098c
// 005092ba  dddb                 fstp st(3)
// 005092bc  51                   push ecx
// 005092bd  ddd9                 fstp st(1)
// 005092bf  ddda                 fstp st(2)
// 005092c1  ddd8                 fstp st(0)
// 005092c3  ddd8                 fstp st(0)
// 005092c5  e806f10000           call 0x5183d0
// 005092ca  83c408               add esp, 8
// 005092cd  5e                   pop esi
// 005092ce  c3                   ret 
// 005092cf  ddd8                 fstp st(0)
// 005092d1  688c097a00           push 0x7a098c
// 005092d6  dddb                 fstp st(3)
// 005092d8  51                   push ecx
// 005092d9  ddd9                 fstp st(1)
// 005092db  ddda                 fstp st(2)
// 005092dd  ddd8                 fstp st(0)
// 005092df  ddd8                 fstp st(0)
// 005092e1  e8eaf00000           call 0x5183d0
// 005092e6  83c408               add esp, 8
// 005092e9  5e                   pop esi
// 005092ea  c3                   ret 
// 005092eb  ddd9                 fstp st(1)
// 005092ed  688c097a00           push 0x7a098c
// 005092f2  dddc                 fstp st(4)
// 005092f4  51                   push ecx
// 005092f5  dddb                 fstp st(3)
// 005092f7  ddd9                 fstp st(1)
// 005092f9  ddda                 fstp st(2)
// 005092fb  ddd8                 fstp st(0)
// 005092fd  ddd8                 fstp st(0)
// 005092ff  e8ccf00000           call 0x5183d0
// 00509304  83c408               add esp, 8
// 00509307  5e                   pop esi
// 00509308  c3                   ret 
// 00509309  ddd9                 fstp st(1)
// 0050930b  688c097a00           push 0x7a098c
// 00509310  dddc                 fstp st(4)
// 00509312  51                   push ecx
// 00509313  ddd9                 fstp st(1)
// 00509315  ddd9                 fstp st(1)
// 00509317  ddda                 fstp st(2)
// 00509319  ddd9                 fstp st(1)
// 0050931b  ddd8                 fstp st(0)
// 0050931d  e8aef00000           call 0x5183d0
// 00509322  83c408               add esp, 8
// 00509325  5e                   pop esi
// 00509326  c3                   ret 
// 00509327  ddd9                 fstp st(1)
// 00509329  688c097a00           push 0x7a098c
// 0050932e  dddc                 fstp st(4)
// 00509330  51                   push ecx
// 00509331  ddd9                 fstp st(1)
// 00509333  ddd9                 fstp st(1)
// 00509335  ddda                 fstp st(2)
// 00509337  ddd8                 fstp st(0)
// 00509339  ddd8                 fstp st(0)
// 0050933b  e890f00000           call 0x5183d0
// 00509340  83c408               add esp, 8
// 00509343  5e                   pop esi
// 00509344  c3                   ret 
// 00509345  ddd9                 fstp st(1)
// 00509347  dddc                 fstp st(4)
// 00509349  688c097a00           push 0x7a098c
// 0050934e  ddd9                 fstp st(1)
// 00509350  51                   push ecx
// 00509351  ddd9                 fstp st(1)
// 00509353  ddd9                 fstp st(1)
// 00509355  ddd9                 fstp st(1)
// 00509357  ddd8                 fstp st(0)
// 00509359  e872f00000           call 0x5183d0
// 0050935e  83c408               add esp, 8
// 00509361  5e                   pop esi
// 00509362  c3                   ret 
// 00509363  ddda                 fstp st(2)
// 00509365  6858097a00           push 0x7a0958
// 0050936a  ddd8                 fstp st(0)
// 0050936c  51                   push ecx
// 0050936d  ddd8                 fstp st(0)
// 0050936f  e85cf00000           call 0x5183d0
// 00509374  83c408               add esp, 8
// 00509377  5e                   pop esi
// 00509378  c3                   ret 
// 00509379  ddda                 fstp st(2)
// 0050937b  6858097a00           push 0x7a0958
// 00509380  ddda                 fstp st(2)
// 00509382  51                   push ecx
// 00509383  ddda                 fstp st(2)
// 00509385  ddd9                 fstp st(1)
// 00509387  ddd8                 fstp st(0)
// 00509389  e842f00000           call 0x5183d0
// 0050938e  83c408               add esp, 8
// 00509391  5e                   pop esi
// 00509392  c3                   ret 
// 00509393  dddb                 fstp st(3)
// 00509395  dddb                 fstp st(3)
// 00509397  dddb                 fstp st(3)
// 00509399  ddd8                 fstp st(0)
// 0050939b  6858097a00           push 0x7a0958
// 005093a0  ddd8                 fstp st(0)
// 005093a2  51                   push ecx
// 005093a3  ddd8                 fstp st(0)
// 005093a5  e826f00000           call 0x5183d0
// 005093aa  83c408               add esp, 8
// 005093ad  5e                   pop esi
// 005093ae  c3                   ret 
// 005093af  dddc                 fstp st(4)
// 005093b1  dddc                 fstp st(4)
// 005093b3  ddd9                 fstp st(1)
// 005093b5  ddd9                 fstp st(1)
// 005093b7  6858097a00           push 0x7a0958
// 005093bc  ddd9                 fstp st(1)
// 005093be  51                   push ecx
// 005093bf  ddd8                 fstp st(0)
// 005093c1  e80af00000           call 0x5183d0
// 005093c6  83c408               add esp, 8
// 005093c9  5e                   pop esi
// 005093ca  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_cHRM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
