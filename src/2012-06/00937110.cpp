// roc 2012-06 00937110  unit: seg_00930000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00937110
//
// 00937110  56                   push esi
// 00937111  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00937115  81fe01010000         cmp esi, 0x101
// 0093711b  7d3d                 jge 0x93715a
// 0093711d  56                   push esi
// 0093711e  ff153028b200         call dword ptr [0xb22830]
// 00937124  83c404               add esp, 4
// 00937127  56                   push esi
// 00937128  85c0                 test eax, eax
// 0093712a  7417                 je 0x937143
// 0093712c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00937130  8b4834               mov ecx, dword ptr [eax + 0x34]
// 00937133  6838fabf00           push 0xbffa38
// 00937138  51                   push ecx
// 00937139  e80290f1ff           call 0x850140
// 0093713e  83c40c               add esp, 0xc
// 00937141  5e                   pop esi
// 00937142  c3                   ret 
// 00937143  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00937147  8b4234               mov eax, dword ptr [edx + 0x34]
// 0093714a  6834fabf00           push 0xbffa34
// 0093714f  50                   push eax
// 00937150  e8eb8ff1ff           call 0x850140
// 00937155  83c40c               add esp, 0xc
// 00937158  5e                   pop esi
// 00937159  c3                   ret 
// 0093715a  8b04b594f5bf00       mov eax, dword ptr [esi*4 + 0xbff594]
// 00937161  5e                   pop esi
// 00937162  c3                   ret 
// copied from an identical function in another client (function _luaX_token2str)

// roc-cl: 21022
// roc-lang: c
// roc-flags: /O2 /Ob1 /GS- /MD
// roc-lib: lua-5.1-dll llex.c