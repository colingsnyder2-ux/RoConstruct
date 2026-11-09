// from server: 100% by colin
// from server: 95% by king_originala
// roc 2008-06 00432000  unit: CDataModelPropGrid  size: 309 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00432000
//
// 00432000  6aff                 push -1
// 00432002  68d7fc7b00           push 0x7bfcd7
// 00432007  64a100000000         mov eax, dword ptr fs:[0]
// 0043200d  50                   push eax
// 0043200e  64892500000000       mov dword ptr fs:[0], esp
// 00432015  51                   push ecx
// 00432016  56                   push esi
// 00432017  8bf1                 mov esi, ecx
// 00432019  57                   push edi
// 0043201a  8dbef0000000         lea edi, [esi + 0xf0]
// 00432020  89742408             mov dword ptr [esp + 8], esi
// 00432024  c7061c1a8100         mov dword ptr [esi], 0x811a1c
// 0043202a  c7070c1a8100         mov dword ptr [edi], 0x811a0c
// 00432030  8b8e00010000         mov ecx, dword ptr [esi + 0x100]
// 00432036  c744241409000000     mov dword ptr [esp + 0x14], 9
// 0043203e  85c9                 test ecx, ecx
// 00432040  740f                 je 0x432051
// 00432042  e89deb2600           call 0x6a0be4
// 00432047  c7860001000000000000 mov dword ptr [esi + 0x100], 0
// 00432051  57                   push edi
// 00432052  b9a06f9700           mov ecx, 0x976fa0
// 00432057  e8243a1b00           call 0x5e5a80
// 0043205c  8d8ee0030000         lea ecx, [esi + 0x3e0]
// 00432062  c644241408           mov byte ptr [esp + 0x14], 8
// 00432067  e8d4dd2d00           call 0x70fe40
// 0043206c  8d8eb4030000         lea ecx, [esi + 0x3b4]
// 00432072  c644241407           mov byte ptr [esp + 0x14], 7
// 00432077  e804b92d00           call 0x70d980
// 0043207c  8b8eb0030000         mov ecx, dword ptr [esi + 0x3b0]
// 00432082  c644241406           mov byte ptr [esp + 0x14], 6
// 00432087  85c9                 test ecx, ecx
// 00432089  7409                 je 0x432094
// 0043208b  8b01                 mov eax, dword ptr [ecx]
// 0043208d  8b5004               mov edx, dword ptr [eax + 4]
// 00432090  6a01                 push 1
// 00432092  ffd2                 call edx
// 00432094  8b8eac030000         mov ecx, dword ptr [esi + 0x3ac]
// 0043209a  c644241405           mov byte ptr [esp + 0x14], 5
// 0043209f  85c9                 test ecx, ecx
// 004320a1  7409                 je 0x4320ac
// 004320a3  8b01                 mov eax, dword ptr [ecx]
// 004320a5  8b5004               mov edx, dword ptr [eax + 4]
// 004320a8  6a01                 push 1
// 004320aa  ffd2                 call edx
// 004320ac  8b8ea8030000         mov ecx, dword ptr [esi + 0x3a8]
// 004320b2  c644241404           mov byte ptr [esp + 0x14], 4
// 004320b7  85c9                 test ecx, ecx
// 004320b9  7409                 je 0x4320c4
// 004320bb  8b01                 mov eax, dword ptr [ecx]
// 004320bd  8b5004               mov edx, dword ptr [eax + 4]
// 004320c0  6a01                 push 1
// 004320c2  ffd2                 call edx
// 004320c4  8d8e84020000         lea ecx, [esi + 0x284]
// 004320ca  c644241403           mov byte ptr [esp + 0x14], 3
// 004320cf  e81c322d00           call 0x7052f0
// 004320d4  8d8e38010000         lea ecx, [esi + 0x138]
// 004320da  c644241402           mov byte ptr [esp + 0x14], 2
// 004320df  e8bc2c2b00           call 0x6e4da0
// 004320e4  8d8e08010000         lea ecx, [esi + 0x108]
// 004320ea  ff15143f8000         call dword ptr [0x803f14]
// 004320f0  8bbef4000000         mov edi, dword ptr [esi + 0xf4]
// 004320f6  c644241400           mov byte ptr [esp + 0x14], 0
// 004320fb  85ff                 test edi, edi
// 004320fd  7410                 je 0x43210f
// 004320ff  8bcf                 mov ecx, edi
// 00432101  e89a52ffff           call 0x4273a0
// 00432106  57                   push edi
// 00432107  e86ee52600           call 0x6a067a
// 0043210c  83c404               add esp, 4
// 0043210f  8bce                 mov ecx, esi
// 00432111  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00432119  c70684128100         mov dword ptr [esi], 0x811284
// 0043211f  e86ce3ffff           call 0x430490
// 00432124  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00432128  5f                   pop edi
// 00432129  5e                   pop esi
// 0043212a  64890d00000000       mov dword ptr fs:[0], ecx
// 00432131  83c410               add esp, 0x10
// 00432134  c3                   ret 

struct Resource {
    void release();
};

struct Object {
    virtual void unused();
    virtual ~Object();
};

struct OwnedObject {
    Object* p;
    ~OwnedObject() { if (p) delete p; }
};

struct Auxiliary {
    ~Auxiliary();
};

struct OwnedAuxiliary {
    Auxiliary* p;
    ~OwnedAuxiliary() { if (p) delete p; }
};

struct Member108 {
    char data[0x30];
    __declspec(dllimport) ~Member108() throw();
};

struct Member138 {
    char data[0x14c];
    ~Member138();
};

struct Member284 {
    char data[0x124];
    ~Member284();
};

struct Member3B4 {
    char data[0x2c];
    ~Member3B4();
};

struct Member3E0 {
    ~Member3E0();
};

struct Base {
    virtual void baseMethod();
    char data[0xec];
    void cleanup();
    ~Base() { cleanup(); }
};

struct Interface {
    virtual void interfaceMethod();
};

struct Registry {
    void remove(Interface*);
};

extern Registry registry;

struct CDataModelPropGrid : Base, Interface {
    OwnedAuxiliary auxiliary;
    char paddingF8[8];
    Resource* resource;
    char padding104[4];
    Member108 member108;
    Member138 member138;
    Member284 member284;
    OwnedObject member3A8;
    OwnedObject member3AC;
    OwnedObject member3B0;
    Member3B4 member3B4;
    Member3E0 member3E0;

    virtual void baseMethod();
    virtual void interfaceMethod();
    ~CDataModelPropGrid();
};

CDataModelPropGrid::~CDataModelPropGrid()
{
    if (resource) {
        resource->release();
        resource = 0;
    }
    registry.remove(this);
}
