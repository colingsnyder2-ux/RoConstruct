// from server: 100% by EspClaude
// roc 2007-08 00422680  unit: CRobloxTreeCtrlNode  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00422680
//
// 00422680  6aff                 push -1
// 00422682  68c0be7300           push 0x73bec0
// 00422687  64a100000000         mov eax, dword ptr fs:[0]
// 0042268d  50                   push eax
// 0042268e  83ec18               sub esp, 0x18
// 00422691  53                   push ebx
// 00422692  56                   push esi
// 00422693  57                   push edi
// 00422694  a188518b00           mov eax, dword ptr [0x8b5188]
// 00422699  33c4                 xor eax, esp
// 0042269b  50                   push eax
// 0042269c  8d442428             lea eax, [esp + 0x28]
// 004226a0  64a300000000         mov dword ptr fs:[0], eax
// 004226a6  8bf1                 mov esi, ecx
// 004226a8  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 004226ab  8b01                 mov eax, dword ptr [ecx]
// 004226ad  8b804c010000         mov eax, dword ptr [eax + 0x14c]
// 004226b3  8d542414             lea edx, [esp + 0x14]
// 004226b7  52                   push edx
// 004226b8  ffd0                 call eax
// 004226ba  8b10                 mov edx, dword ptr [eax]
// 004226bc  83ec08               sub esp, 8
// 004226bf  8bcc                 mov ecx, esp
// 004226c1  8911                 mov dword ptr [ecx], edx
// 004226c3  8b4004               mov eax, dword ptr [eax + 4]
// 004226c6  85c0                 test eax, eax
// 004226c8  c744243800000000     mov dword ptr [esp + 0x38], 0
// 004226d0  89642418             mov dword ptr [esp + 0x18], esp
// 004226d4  894104               mov dword ptr [ecx + 4], eax
// 004226d7  740c                 je 0x4226e5
// 004226d9  83c004               add eax, 4
// 004226dc  b901000000           mov ecx, 1
// 004226e1  f00fc108             lock xadd dword ptr [eax], ecx
// 004226e5  8d4c2424             lea ecx, [esp + 0x24]
// 004226e9  e862aefeff           call 0x40d550
// 004226ee  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004226f2  85ff                 test edi, edi
// 004226f4  c644243002           mov byte ptr [esp + 0x30], 2
// 004226f9  742a                 je 0x422725
// 004226fb  8d5704               lea edx, [edi + 4]
// 004226fe  83c8ff               or eax, 0xffffffff
// 00422701  f00fc102             lock xadd dword ptr [edx], eax
// 00422705  751e                 jne 0x422725
// 00422707  8b17                 mov edx, dword ptr [edi]
// 00422709  8b4204               mov eax, dword ptr [edx + 4]
// 0042270c  8bcf                 mov ecx, edi
// 0042270e  ffd0                 call eax
// 00422710  8d4f08               lea ecx, [edi + 8]
// 00422713  83caff               or edx, 0xffffffff
// 00422716  f00fc111             lock xadd dword ptr [ecx], edx
// 0042271a  7509                 jne 0x422725
// 0042271c  8b07                 mov eax, dword ptr [edi]
// 0042271e  8b5008               mov edx, dword ptr [eax + 8]
// 00422721  8bcf                 mov ecx, edi
// 00422723  ffd2                 call edx
// 00422725  817c243cbc148c00     cmp dword ptr [esp + 0x3c], 0x8c14bc
// 0042272d  8d4c241c             lea ecx, [esp + 0x1c]
// 00422731  0f94c3               sete bl
// 00422734  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 0042273c  e85f6e1300           call 0x5595a0
// 00422741  84db                 test bl, bl
// 00422743  7412                 je 0x422757
// 00422745  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 00422748  804e2c01             or byte ptr [esi + 0x2c], 1
// 0042274c  8b01                 mov eax, dword ptr [ecx]
// 0042274e  8b9054010000         mov edx, dword ptr [eax + 0x154]
// 00422754  56                   push esi
// 00422755  ffd2                 call edx
// 00422757  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0042275b  64890d00000000       mov dword ptr fs:[0], ecx
// 00422762  59                   pop ecx
// 00422763  5f                   pop edi
// 00422764  5e                   pop esi
// 00422765  5b                   pop ebx
// 00422766  83c424               add esp, 0x24
// 00422769  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

template<class T>
struct shared_ptr {
    T* px;
    Control* pn;
    shared_ptr(const shared_ptr& other) : px(other.px), pn(other.pn)
    {
        if (pn)
            _InterlockedIncrement(&pn->strong);
    }
    ~shared_ptr()
    {
        Control* p = pn;
        if (p && _InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
    template<class Y>
    shared_ptr(const shared_ptr<Y>& other) : px(other.px), pn(other.pn)
    {
        if (pn)
            _InterlockedIncrement(&pn->strong);
    }
    T* operator->() const { return px; }
    T* get() const { return px; }
};

struct DataModel;

struct Lock {
    void* first;
    void* second;
    void* third;
    explicit Lock(shared_ptr<const DataModel> dataModel);
    ~Lock();
};

struct PropertyDescriptor;
extern const PropertyDescriptor desc_Name;

struct CRobloxTreeCtrlNode;

struct CRobloxTreeCtrl {
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c();
    virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c();
    virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c();
    virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac();
    virtual void v0b0(); virtual void v0b4(); virtual void v0b8(); virtual void v0bc();
    virtual void v0c0(); virtual void v0c4(); virtual void v0c8(); virtual void v0cc();
    virtual void v0d0(); virtual void v0d4(); virtual void v0d8(); virtual void v0dc();
    virtual void v0e0(); virtual void v0e4(); virtual void v0e8(); virtual void v0ec();
    virtual void v0f0(); virtual void v0f4(); virtual void v0f8(); virtual void v0fc();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10c();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11c();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12c();
    virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13c();
    virtual void v140(); virtual void v144(); virtual void v148();
    virtual shared_ptr<DataModel> getDataModel();
    virtual void v150();
    virtual void invalidateNode(CRobloxTreeCtrlNode* node);
};

struct CRobloxTreeCtrlNode {
    char pad[0x2c];
    unsigned char flags;
    char pad2[3];
    CRobloxTreeCtrl* tree;

    void onPropertyChanged(void* instance, const PropertyDescriptor* descriptor, void* extra);
};

void CRobloxTreeCtrlNode::onPropertyChanged(void* instance, const PropertyDescriptor* descriptor, void* extra)
{
    bool nameChanged;
    {
        Lock lock(tree->getDataModel());
        nameChanged = (descriptor == &desc_Name);
    }
    if (nameChanged) {
        flags |= 1;
        tree->invalidateNode(this);
    }
}
