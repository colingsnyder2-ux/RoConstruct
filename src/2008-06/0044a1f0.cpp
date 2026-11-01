// from server: 100% by colin
﻿// from server: 95% by EspClaude
// roc 2008-06 0044a1f0  unit: CRbxPlayDocTemplate  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044a1f0
//
// 0044a1f0  6aff                 push -1
// 0044a1f2  6809b77d00           push 0x7db709
// 0044a1f7  64a100000000         mov eax, dword ptr fs:[0]
// 0044a1fd  50                   push eax
// 0044a1fe  64892500000000       mov dword ptr fs:[0], esp
// 0044a205  83ec08               sub esp, 8
// 0044a208  56                   push esi
// 0044a209  57                   push edi
// 0044a20a  8b4958               mov ecx, dword ptr [ecx + 0x58]
// 0044a20d  8b7124               mov esi, dword ptr [ecx + 0x24]
// 0044a210  8b06                 mov eax, dword ptr [esi]
// 0044a212  8b505c               mov edx, dword ptr [eax + 0x5c]
// 0044a215  8bce                 mov ecx, esi
// 0044a217  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044a21f  ffd2                 call edx
// 0044a221  89442408             mov dword ptr [esp + 8], eax
// 0044a225  85c0                 test eax, eax
// 0044a227  743d                 je 0x44a266
// 0044a229  8da42400000000       lea esp, [esp]
// 0044a230  8b06                 mov eax, dword ptr [esi]
// 0044a232  8b5060               mov edx, dword ptr [eax + 0x60]
// 0044a235  8d4c2408             lea ecx, [esp + 8]
// 0044a239  51                   push ecx
// 0044a23a  8bce                 mov ecx, esi
// 0044a23c  ffd2                 call edx
// 0044a23e  83ec1c               sub esp, 0x1c
// 0044a241  8bf8                 mov edi, eax
// 0044a243  8d44243c             lea eax, [esp + 0x3c]
// 0044a247  8bcc                 mov ecx, esp
// 0044a249  89642428             mov dword ptr [esp + 0x28], esp
// 0044a24d  50                   push eax
// 0044a24e  ff155c248000         call dword ptr [0x80245c]
// 0044a254  8bcf                 mov ecx, edi
// 0044a256  e865a80000           call 0x454ac0
// 0044a25b  85c0                 test eax, eax
// 0044a25d  7431                 je 0x44a290
// 0044a25f  837c240800           cmp dword ptr [esp + 8], 0
// 0044a264  75ca                 jne 0x44a230
// 0044a266  8d4c2420             lea ecx, [esp + 0x20]
// 0044a26a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0044a272  ff1568248000         call dword ptr [0x802468]
// 0044a278  b801000000           mov eax, 1
// 0044a27d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044a281  64890d00000000       mov dword ptr fs:[0], ecx
// 0044a288  5f                   pop edi
// 0044a289  5e                   pop esi
// 0044a28a  83c414               add esp, 0x14
// 0044a28d  c21c00               ret 0x1c
// 0044a290  8d4c2420             lea ecx, [esp + 0x20]
// 0044a294  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0044a29c  ff1568248000         call dword ptr [0x802468]
// 0044a2a2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044a2a6  5f                   pop edi
// 0044a2a7  33c0                 xor eax, eax
// 0044a2a9  64890d00000000       mov dword ptr fs:[0], ecx
// 0044a2b0  5e                   pop esi
// 0044a2b1  83c414               add esp, 0x14
// 0044a2b4  c21c00               ret 0x1c

// from server: 65% by colin
// roc 2008-06 0044a1f0  unit: CRbxPlayDocTemplate  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044a1f0
// 0044a1f0  6aff                 push -1
// 0044a1f2  6809b77d00           push 0x7db709
// 0044a1f7  64a100000000         mov eax, dword ptr fs:[0]
// 0044a1fd  50                   push eax
// 0044a1fe  64892500000000       mov dword ptr fs:[0], esp
// 0044a205  83ec08               sub esp, 8
// 0044a208  56                   push esi
// 0044a209  57                   push edi
// 0044a20a  8b4958               mov ecx, dword ptr [ecx + 0x58]
// 0044a20d  8b7124               mov esi, dword ptr [ecx + 0x24]
// 0044a210  8b06                 mov eax, dword ptr [esi]
// 0044a212  8b505c               mov edx, dword ptr [eax + 0x5c]
// 0044a215  8bce                 mov ecx, esi
// 0044a217  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044a21f  ffd2                 call edx
// 0044a221  89442408             mov dword ptr [esp + 8], eax
// 0044a225  85c0                 test eax, eax
// 0044a227  743d                 je 0x44a266
// 0044a229  8da42400000000       lea esp, [esp]
// 0044a230  8b06                 mov eax, dword ptr [esi]
// 0044a232  8b5060               mov edx, dword ptr [eax + 0x60]
// 0044a235  8d4c2408             lea ecx, [esp + 8]
// 0044a239  51                   push ecx
// 0044a23a  8bce                 mov ecx, esi
// 0044a23c  ffd2                 call edx
// 0044a23e  83ec1c               sub esp, 0x1c
// 0044a241  8bf8                 mov edi, eax
// 0044a243  8d44243c             lea eax, [esp + 0x3c]
// 0044a247  8bcc                 mov ecx, esp
// 0044a249  89642428             mov dword ptr [esp + 0x28], esp
// 0044a24d  50                   push eax
// 0044a24e  ff155c248000         call dword ptr [0x80245c]
// 0044a254  8bcf                 mov ecx, edi
// 0044a256  e865a80000           call 0x454ac0
// 0044a25b  85c0                 test eax, eax
// 0044a25d  7431                 je 0x44a290
// 0044a25f  837c240800           cmp dword ptr [esp + 8], 0
// 0044a264  75ca                 jne 0x44a230
// 0044a266  8d4c2420             lea ecx, [esp + 0x20]
// 0044a26a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0044a272  ff1568248000         call dword ptr [0x802468]
// 0044a278  b801000000           mov eax, 1
// 0044a27d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044a281  64890d00000000       mov dword ptr fs:[0], ecx
// 0044a288  5f                   pop edi
// 0044a289  5e                   pop esi
// 0044a28a  83c414               add esp, 0x14
// 0044a28d  c21c00               ret 0x1c
// 0044a290  8d4c2420             lea ecx, [esp + 0x20]
// 0044a294  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0044a29c  ff1568248000         call dword ptr [0x802468]
// 0044a2a2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044a2a6  5f                   pop edi
// 0044a2a7  33c0                 xor eax, eax
// 0044a2a9  64890d00000000       mov dword ptr fs:[0], ecx
// 0044a2b0  5e                   pop esi
// 0044a2b1  83c414               add esp, 0x14
// 0044a2b4  c21c00               ret 0x1c
#include <string>

struct Doc {
    int check(std::string);
};

struct Template {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58();
    virtual void* GetFirstDocPosition();
    virtual Doc* GetNextDoc(void*& pos);
};

struct Container {
    char pad[0x24];
    Template* tmpl;
};

struct Outer {
    char pad[0x58];
    Container* field_58;
    int check(std::string name);
};

int Outer::check(std::string name)
{
    Container* c = field_58;
    Template* t = c->tmpl;
    void* pos = t->GetFirstDocPosition();
    while (pos) {
        Doc* doc = t->GetNextDoc(pos);
        if (!doc->check(name))
            return 0;
    }
    return 1;
}

