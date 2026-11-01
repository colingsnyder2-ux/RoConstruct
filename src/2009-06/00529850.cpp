// from server: 100% by EspClaude
// from server: 97% by EspClaude
// roc 2009-06 00529850  unit: RBX::ViewG3D  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00529850
//
// 00529850  6aff                 push -1
// 00529852  68feeb8500           push 0x85ebfe
// 00529857  64a100000000         mov eax, dword ptr fs:[0]
// 0052985d  50                   push eax
// 0052985e  64892500000000       mov dword ptr fs:[0], esp
// 00529865  51                   push ecx
// 00529866  56                   push esi
// 00529867  8bf1                 mov esi, ecx
// 00529869  89742404             mov dword ptr [esp + 4], esi
// 0052986d  c706d4a18c00         mov dword ptr [esi], 0x8ca1d4
// 00529873  8b4e04               mov ecx, dword ptr [esi + 4]
// 00529876  8b01                 mov eax, dword ptr [ecx]
// 00529878  8b500c               mov edx, dword ptr [eax + 0xc]
// 0052987b  c744241002000000     mov dword ptr [esp + 0x10], 2
// 00529883  ffd2                 call edx
// 00529885  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00529888  85c9                 test ecx, ecx
// 0052988a  7405                 je 0x529891
// 0052988c  e85f0bfcff           call 0x4ea3f0
// 00529891  e88aa40300           call 0x563d20
// 00529896  e835ebffff           call 0x5283d0
// 0052989b  e870edffff           call 0x528610
// 005298a0  e8abe6ffff           call 0x527f50
// 005298a5  e806eaffff           call 0x5282b0
// 005298aa  e841ecffff           call 0x5284f0
// 005298af  e87ceeffff           call 0x528730
// 005298b4  8d4e34               lea ecx, [esi + 0x34]
// 005298b7  c644241001           mov byte ptr [esp + 0x10], 1
// 005298bc  e81f0a0c00           call 0x5ea2e0
// 005298c1  8b4630               mov eax, dword ptr [esi + 0x30]
// 005298c4  c644241000           mov byte ptr [esp + 0x10], 0
// 005298c9  85c0                 test eax, eax
// 005298cb  742c                 je 0x5298f9
// 005298cd  83c004               add eax, 4
// 005298d0  50                   push eax
// 005298d1  ff15a4e18900         call dword ptr [0x89e1a4]
// 005298d7  85c0                 test eax, eax
// 005298d9  7517                 jne 0x5298f2
// 005298db  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 005298de  e89db4f1ff           call 0x444d80
// 005298e3  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 005298e6  85c9                 test ecx, ecx
// 005298e8  7408                 je 0x5298f2
// 005298ea  8b01                 mov eax, dword ptr [ecx]
// 005298ec  8b10                 mov edx, dword ptr [eax]
// 005298ee  6a01                 push 1
// 005298f0  ffd2                 call edx
// 005298f2  c7463000000000       mov dword ptr [esi + 0x30], 0
// 005298f9  8bce                 mov ecx, esi
// 005298fb  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00529903  e8b8cbffff           call 0x5264c0
// 00529908  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0052990c  5e                   pop esi
// 0052990d  64890d00000000       mov dword ptr fs:[0], ecx
// 00529914  83c410               add esp, 0x10
// 00529917  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 004dc270  unit: RBX::ViewNew::ViewG3D  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dc270
//
// 004dc270  6aff                 push -1
// 004dc272  685ea27c00           push 0x7ca25e
// 004dc277  64a100000000         mov eax, dword ptr fs:[0]
// 004dc27d  50                   push eax
// 004dc27e  64892500000000       mov dword ptr fs:[0], esp
// 004dc285  51                   push ecx
// 004dc286  56                   push esi
// 004dc287  8bf1                 mov esi, ecx
// 004dc289  89742404             mov dword ptr [esp + 4], esi
// 004dc28d  c706046e8200         mov dword ptr [esi], 0x826e04
// 004dc293  8b4e04               mov ecx, dword ptr [esi + 4]
// 004dc296  8b01                 mov eax, dword ptr [ecx]
// 004dc298  8b500c               mov edx, dword ptr [eax + 0xc]
// 004dc29b  c744241002000000     mov dword ptr [esp + 0x10], 2
// 004dc2a3  ffd2                 call edx
// 004dc2a5  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004dc2a8  85c9                 test ecx, ecx
// 004dc2aa  7405                 je 0x4dc2b1
// 004dc2ac  e8cf70fdff           call 0x4b3380
// 004dc2b1  e87aeeffff           call 0x4db130
// 004dc2b6  e885edffff           call 0x4db040
// 004dc2bb  e890ecffff           call 0x4daf50
// 004dc2c0  e8ab930000           call 0x4e5670
// 004dc2c5  e846f0ffff           call 0x4db310
// 004dc2ca  e851efffff           call 0x4db220
// 004dc2cf  e82cf1ffff           call 0x4db400
// 004dc2d4  8d4e4c               lea ecx, [esi + 0x4c]
// 004dc2d7  c644241001           mov byte ptr [esp + 0x10], 1
// 004dc2dc  e89f7a0700           call 0x553d80
// 004dc2e1  8b4648               mov eax, dword ptr [esi + 0x48]
// 004dc2e4  c644241000           mov byte ptr [esp + 0x10], 0
// 004dc2e9  85c0                 test eax, eax
// 004dc2eb  742c                 je 0x4dc319
// 004dc2ed  83c004               add eax, 4
// 004dc2f0  50                   push eax
// 004dc2f1  ff15ac218000         call dword ptr [0x8021ac]
// 004dc2f7  85c0                 test eax, eax
// 004dc2f9  7517                 jne 0x4dc312
// 004dc2fb  8b4e48               mov ecx, dword ptr [esi + 0x48]
// 004dc2fe  e88deaf7ff           call 0x45ad90
// 004dc303  8b4e48               mov ecx, dword ptr [esi + 0x48]
// 004dc306  85c9                 test ecx, ecx
// 004dc308  7408                 je 0x4dc312
// 004dc30a  8b01                 mov eax, dword ptr [ecx]
// 004dc30c  8b10                 mov edx, dword ptr [eax]
// 004dc30e  6a01                 push 1
// 004dc310  ffd2                 call edx
// 004dc312  c7464800000000       mov dword ptr [esi + 0x48], 0
// 004dc319  8bce                 mov ecx, esi
// 004dc31b  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004dc323  e8f8c5ffff           call 0x4d8920
// 004dc328  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004dc32c  5e                   pop esi
// 004dc32d  64890d00000000       mov dword ptr fs:[0], ecx
// 004dc334  83c410               add esp, 0x10
// 004dc337  c3                   ret 

extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void close();
};

struct Auxiliary {
    void destroy();
};

struct Image {
    virtual ~Image();
    volatile long references;
    void releaseResources();
};

struct ImageReference {
    Image *pointer;
    ~ImageReference();
};

inline ImageReference::~ImageReference() {
    if (pointer) {
        if (InterlockedDecrement(&pointer->references) == 0) {
            pointer->releaseResources();
            if (pointer)
                delete pointer;
        }
        pointer = 0;
    }
}

struct Resource {
    ~Resource();
};

struct Base {
    virtual ~Base();
};

void shutdown1();
void shutdown2();
void shutdown3();
void shutdown4();
void shutdown5();
void shutdown6();
void shutdown7();

struct S : Base {
    Interface *interfacePointer;
    unsigned char padding08[12];
    Auxiliary *auxiliary;
    unsigned char padding18[24];
    ImageReference image;
    Resource resource;

    virtual ~S();
};

S::~S() {
    interfacePointer->close();
    if (auxiliary)
        auxiliary->destroy();
    shutdown1();
    shutdown2();
    shutdown3();
    shutdown4();
    shutdown5();
    shutdown6();
    shutdown7();
}
