// from server: 100% by Intel
// from server: 94% by EspClaude
// roc 2007-08 0041cf10  unit: InsertDecal  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041cf10
//
// 0041cf10  56                   push esi
// 0041cf11  57                   push edi
// 0041cf12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0041cf16  8bf1                 mov esi, ecx
// 0041cf18  56                   push esi
// 0041cf19  8bcf                 mov ecx, edi
// 0041cf1b  e8a0131200           call 0x53e2c0
// 0041cf20  84c0                 test al, al
// 0041cf22  7407                 je 0x41cf2b
// 0041cf24  5f                   pop edi
// 0041cf25  32c0                 xor al, al
// 0041cf27  5e                   pop esi
// 0041cf28  c20400               ret 4
// 0041cf2b  39b7bc000000         cmp dword ptr [edi + 0xbc], esi
// 0041cf31  74f1                 je 0x41cf24
// 0041cf33  8b06                 mov eax, dword ptr [esi]
// 0041cf35  8b500c               mov edx, dword ptr [eax + 0xc]
// 0041cf38  57                   push edi
// 0041cf39  8bce                 mov ecx, esi
// 0041cf3b  ffd2                 call edx
// 0041cf3d  84c0                 test al, al
// 0041cf3f  7407                 je 0x41cf48
// 0041cf41  5f                   pop edi
// 0041cf42  b001                 mov al, 1
// 0041cf44  5e                   pop esi
// 0041cf45  c20400               ret 4
// 0041cf48  8b07                 mov eax, dword ptr [edi]
// 0041cf4a  8b5010               mov edx, dword ptr [eax + 0x10]
// 0041cf4d  56                   push esi
// 0041cf4e  8bcf                 mov ecx, edi
// 0041cf50  ffd2                 call edx
// 0041cf52  84c0                 test al, al
// 0041cf54  5f                   pop edi
// 0041cf55  0f95c0               setne al
// 0041cf58  5e                   pop esi
// 0041cf59  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 0041f340  unit: InsertDecal  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041f340
//
// 0041f340  56                   push esi
// 0041f341  57                   push edi
// 0041f342  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0041f346  8bf1                 mov esi, ecx
// 0041f348  56                   push esi
// 0041f349  8bcf                 mov ecx, edi
// 0041f34b  e860811300           call 0x5574b0
// 0041f350  84c0                 test al, al
// 0041f352  7407                 je 0x41f35b
// 0041f354  5f                   pop edi
// 0041f355  32c0                 xor al, al
// 0041f357  5e                   pop esi
// 0041f358  c20400               ret 4
// 0041f35b  39b704010000         cmp dword ptr [edi + 0x104], esi
// 0041f361  74f1                 je 0x41f354
// 0041f363  8b06                 mov eax, dword ptr [esi]
// 0041f365  8b5008               mov edx, dword ptr [eax + 8]
// 0041f368  57                   push edi
// 0041f369  8bce                 mov ecx, esi
// 0041f36b  ffd2                 call edx
// 0041f36d  84c0                 test al, al
// 0041f36f  7407                 je 0x41f378
// 0041f371  5f                   pop edi
// 0041f372  b001                 mov al, 1
// 0041f374  5e                   pop esi
// 0041f375  c20400               ret 4
// 0041f378  8b07                 mov eax, dword ptr [edi]
// 0041f37a  8b500c               mov edx, dword ptr [eax + 0xc]
// 0041f37d  56                   push esi
// 0041f37e  8bcf                 mov ecx, edi
// 0041f380  ffd2                 call edx
// 0041f382  84c0                 test al, al
// 0041f384  5f                   pop edi
// 0041f385  0f95c0               setne al
// 0041f388  5e                   pop esi
// 0041f389  c20400               ret 4

struct S {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2a();
    virtual bool slot2(S*);
    virtual unsigned char slot3(S*);

    char padding[184];
    S* parent;

    bool contains(S*);
    bool f(S*);
};

bool S::f(S* other)
{
    if (other->contains(this))
        return false;
    if (other->parent == this)
        return false;
    if (slot2(other))
        return true;
    return other->slot3(this);
}
