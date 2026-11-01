// from server: 97% by EspClaude
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
    unsigned char padding18[48];
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
