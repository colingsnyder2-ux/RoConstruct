// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_selectionvector_86be58efb53b983a.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
// from server: 97% by king_originala
// roc 2008-06 005d8740  unit: RBX::VHumanoid::?$FactoryProduct  size: 258 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d8740
//
// 005d8740  6aff                 push -1
// 005d8742  6865907d00           push 0x7d9065
// 005d8747  64a100000000         mov eax, dword ptr fs:[0]
// 005d874d  50                   push eax
// 005d874e  64892500000000       mov dword ptr fs:[0], esp
// 005d8755  83ec24               sub esp, 0x24
// 005d8758  53                   push ebx
// 005d8759  56                   push esi
// 005d875a  8bf1                 mov esi, ecx
// 005d875c  57                   push edi
// 005d875d  89742410             mov dword ptr [esp + 0x10], esi
// 005d8761  e8fa11e3ff           call 0x409960
// 005d8766  33db                 xor ebx, ebx
// 005d8768  c70644d58300         mov dword ptr [esi], 0x83d544
// 005d876e  c7461038d58300       mov dword ptr [esi + 0x10], 0x83d538
// 005d8775  c7461430d58300       mov dword ptr [esi + 0x14], 0x83d530
// 005d877c  c7462028d58300       mov dword ptr [esi + 0x20], 0x83d528
// 005d8783  c7462418d58300       mov dword ptr [esi + 0x24], 0x83d518
// 005d878a  c7464408d58300       mov dword ptr [esi + 0x44], 0x83d508
// 005d8791  c74664f8d48300       mov dword ptr [esi + 0x64], 0x83d4f8
// 005d8798  c78684000000e8d48300 mov dword ptr [esi + 0x84], 0x83d4e8
// 005d87a2  c786a4000000d8d48300 mov dword ptr [esi + 0xa4], 0x83d4d8
// 005d87ac  c786c4000000c8d48300 mov dword ptr [esi + 0xc4], 0x83d4c8
// 005d87b6  c78630010000c0d48300 mov dword ptr [esi + 0x130], 0x83d4c0
// 005d87c0  899e34010000         mov dword ptr [esi + 0x134], ebx
// 005d87c6  895c2438             mov dword ptr [esp + 0x38], ebx
// 005d87ca  899e38010000         mov dword ptr [esi + 0x138], ebx
// 005d87d0  6a04                 push 4
// 005d87d2  c644243c01           mov byte ptr [esp + 0x3c], 1
// 005d87d7  8dbe3c010000         lea edi, [esi + 0x13c]
// 005d87dd  e83e810c00           call 0x6a0920
// 005d87e2  83c404               add esp, 4
// 005d87e5  3bc3                 cmp eax, ebx
// 005d87e7  7404                 je 0x5d87ed
// 005d87e9  8938                 mov dword ptr [eax], edi
// 005d87eb  eb02                 jmp 0x5d87ef
// 005d87ed  33c0                 xor eax, eax
// 005d87ef  8907                 mov dword ptr [edi], eax
// 005d87f1  895f0c               mov dword ptr [edi + 0xc], ebx
// 005d87f4  895f10               mov dword ptr [edi + 0x10], ebx
// 005d87f7  895f14               mov dword ptr [edi + 0x14], ebx
// 005d87fa  b303                 mov bl, 3
// 005d87fc  68a4088300           push 0x8308a4
// 005d8801  8d4c2418             lea ecx, [esp + 0x18]
// 005d8805  885c243c             mov byte ptr [esp + 0x3c], bl
// 005d8809  ff1558248000         call dword ptr [0x802458]
// 005d880f  8d442414             lea eax, [esp + 0x14]
// 005d8813  50                   push eax
// 005d8814  8bce                 mov ecx, esi
// 005d8816  c644243c04           mov byte ptr [esp + 0x3c], 4
// 005d881b  e87027f8ff           call 0x55af90
// 005d8820  8d4c2414             lea ecx, [esp + 0x14]
// 005d8824  885c2438             mov byte ptr [esp + 0x38], bl
// 005d8828  ff1568248000         call dword ptr [0x802468]
// 005d882e  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005d8832  5f                   pop edi
// 005d8833  8bc6                 mov eax, esi
// 005d8835  5e                   pop esi
// 005d8836  5b                   pop ebx
// 005d8837  64890d00000000       mov dword ptr fs:[0], ecx
// 005d883e  83c430               add esp, 0x30
// 005d8841  c3                   ret 

typedef unsigned long DWORD;

void* __cdecl operator new(unsigned int);

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

extern String* (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

inline String::String(const char* text) {
    stringConstruct(this, text);
}

inline String::~String() {
    stringDestroy(this);
}

struct Base {
    DWORD words[77];
    Base();
    ~Base();
    void setValue(const String&);
};

struct Pointer {
    void* value;
    Pointer();
    ~Pointer();
};

inline Pointer::Pointer() : value(0) {}

struct Signal {
    struct Node {
        Signal* owner;
        Node(Signal*);
    };

    struct Owner {
        Node* value;
        Owner(Signal*);
        ~Owner();
    };

    Owner node;
    DWORD reserved[2];
    DWORD first;
    DWORD second;
    DWORD third;

    Signal();
    ~Signal();
};

inline Signal::Node::Node(Signal* signal) : owner(signal) {}

inline Signal::Owner::Owner(Signal* signal)
    : value(new Node(signal)) {}

inline Signal::Signal()
    : node(this), first(0), second(0), third(0) {}

struct S : Base {
    DWORD firstPointer;
    Pointer secondPointer;
    std::vector<void*> signal;

    S();
    int initializeTables();
};

__forceinline int S::initializeTables() {
    words[0] = 0x83d544;
    words[4] = 0x83d538;
    words[5] = 0x83d530;
    words[8] = 0x83d528;
    words[9] = 0x83d518;
    words[17] = 0x83d508;
    words[25] = 0x83d4f8;
    words[33] = 0x83d4e8;
    words[41] = 0x83d4d8;
    words[49] = 0x83d4c8;
    words[76] = 0x83d4c0;
    return 0;
}

S::S()
    : Base(),
      firstPointer(initializeTables()),
      secondPointer(),
      signal() {
    setValue(String("FilteredSelection"));
}
