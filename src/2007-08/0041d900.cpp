// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 0041d900  unit: CInstanceRecord::CNameItem  size: 245 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041d900
//
// 0041d900  6aff                 push -1
// 0041d902  688af87500           push 0x75f88a
// 0041d907  64a100000000         mov eax, dword ptr fs:[0]
// 0041d90d  50                   push eax
// 0041d90e  56                   push esi
// 0041d90f  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041d914  33c4                 xor eax, esp
// 0041d916  50                   push eax
// 0041d917  8d442408             lea eax, [esp + 8]
// 0041d91b  64a300000000         mov dword ptr fs:[0], eax
// 0041d921  8bf1                 mov esi, ecx
// 0041d923  8b442418             mov eax, dword ptr [esp + 0x18]
// 0041d927  50                   push eax
// 0041d928  e8f3482300           call 0x652220
// 0041d92d  83f8ff               cmp eax, -1
// 0041d930  7515                 jne 0x41d947
// 0041d932  0bc0                 or eax, eax
// 0041d934  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0041d938  64890d00000000       mov dword ptr fs:[0], ecx
// 0041d93f  59                   pop ecx
// 0041d940  5e                   pop esi
// 0041d941  83c40c               add esp, 0xc
// 0041d944  c20400               ret 4
// 0041d947  8b16                 mov edx, dword ptr [esi]
// 0041d949  8b828c010000         mov eax, dword ptr [edx + 0x18c]
// 0041d94f  8bce                 mov ecx, esi
// 0041d951  ffd0                 call eax
// 0041d953  8bf0                 mov esi, eax
// 0041d955  8b8600020000         mov eax, dword ptr [esi + 0x200]
// 0041d95b  c7808800000001000000 mov dword ptr [eax + 0x88], 1
// 0041d965  8b8600020000         mov eax, dword ptr [esi + 0x200]
// 0041d96b  c7407c00000000       mov dword ptr [eax + 0x7c], 0
// 0041d972  8b8e00020000         mov ecx, dword ptr [esi + 0x200]
// 0041d978  6a01                 push 1
// 0041d97a  e8412e2400           call 0x6607c0
// 0041d97f  68b4000000           push 0xb4
// 0041d984  e86d252100           call 0x62fef6
// 0041d989  83c404               add esp, 4
// 0041d98c  89442418             mov dword ptr [esp + 0x18], eax
// 0041d990  85c0                 test eax, eax
// 0041d992  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041d99a  741d                 je 0x41d9b9
// 0041d99c  6a01                 push 1
// 0041d99e  6a01                 push 1
// 0041d9a0  6aff                 push -1
// 0041d9a2  6a01                 push 1
// 0041d9a4  682c010000           push 0x12c
// 0041d9a9  68d47e7800           push 0x787ed4
// 0041d9ae  6a00                 push 0
// 0041d9b0  8bc8                 mov ecx, eax
// 0041d9b2  e8990d2400           call 0x65e750
// 0041d9b7  eb02                 jmp 0x41d9bb
// 0041d9b9  33c0                 xor eax, eax
// 0041d9bb  50                   push eax
// 0041d9bc  8bce                 mov ecx, esi
// 0041d9be  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0041d9c6  e835852300           call 0x655f00
// 0041d9cb  8bf0                 mov esi, eax
// 0041d9cd  6a01                 push 1
// 0041d9cf  8bce                 mov ecx, esi
// 0041d9d1  e85a0f2400           call 0x65e930
// 0041d9d6  c786ac00000000000000 mov dword ptr [esi + 0xac], 0
// 0041d9e0  33c0                 xor eax, eax
// 0041d9e2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0041d9e6  64890d00000000       mov dword ptr fs:[0], ecx
// 0041d9ed  59                   pop ecx
// 0041d9ee  5e                   pop esi
// 0041d9ef  83c40c               add esp, 0xc
// 0041d9f2  c20400               ret 4

struct Inner {
    char pad[0x7c];
    int f7c;
    char pad2[0x88 - 0x80];
    int f88;
    void m6607c0(int);
};

struct Item {
    Item(int, const char*, int, int, int, int, int);
    char pad[0xac];
    int fac;
    char pad2[0xb4 - 0xb0];
    void m65e930(int);
};

struct Owner {
    char pad[0x200];
    Inner* f200;
    Item* m655f00(Item*);
};

struct CNameItem {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b();
    virtual void v1c(); virtual void v1d(); virtual void v1e(); virtual void v1f();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v2a(); virtual void v2b();
    virtual void v2c(); virtual void v2d(); virtual void v2e(); virtual void v2f();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v3a(); virtual void v3b();
    virtual void v3c(); virtual void v3d(); virtual void v3e(); virtual void v3f();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v4a(); virtual void v4b();
    virtual void v4c(); virtual void v4d(); virtual void v4e(); virtual void v4f();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
    virtual void v58(); virtual void v59(); virtual void v5a(); virtual void v5b();
    virtual void v5c(); virtual void v5d(); virtual void v5e(); virtual void v5f();
    virtual void v60(); virtual void v61(); virtual void v62();
    virtual Owner* GetOwner();   // +0x18c
    int base652220(int);
    int f(int);
};

int CNameItem::f(int a)
{
    if (base652220(a) == -1)
        return -1;
    Owner* o = GetOwner();
    Inner* in = o->f200;
    in->f88 = 1;
    Inner* in2 = o->f200;
    in2->f7c = 0;
    o->f200->m6607c0(1);
    Item* it = o->m655f00(new Item(0, "Name", 0x12c, 1, -1, 1, 1));
    it->m65e930(1);
    it->fac = 0;
    return 0;
}
