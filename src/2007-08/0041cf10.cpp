// from server: 94% by EspClaude
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
    virtual bool slot2(S*);
    virtual unsigned char slot3(S*);

    char padding[256];
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
