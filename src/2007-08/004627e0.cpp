// from server: 92% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 00466880  unit: RBX::VSelection::?$FilteredListener  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00466880
//
// 00466880  6aff                 push -1
// 00466882  6836357c00           push 0x7c3536
// 00466887  64a100000000         mov eax, dword ptr fs:[0]
// 0046688d  50                   push eax
// 0046688e  64892500000000       mov dword ptr fs:[0], esp
// 00466895  51                   push ecx
// 00466896  53                   push ebx
// 00466897  55                   push ebp
// 00466898  56                   push esi
// 00466899  8bf1                 mov esi, ecx
// 0046689b  57                   push edi
// 0046689c  89742410             mov dword ptr [esp + 0x10], esi
// 004668a0  e81b252b00           call 0x718dc0
// 004668a5  8d9e90010000         lea ebx, [esi + 0x190]
// 004668ab  33ed                 xor ebp, ebp
// 004668ad  8bcb                 mov ecx, ebx
// 004668af  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004668b3  e898f4f9ff           call 0x405d50
// 004668b8  8dbe94010000         lea edi, [esi + 0x194]
// 004668be  8bcf                 mov ecx, edi
// 004668c0  c644241c01           mov byte ptr [esp + 0x1c], 1
// 004668c5  e816f9ffff           call 0x4661e0
// 004668ca  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004668ce  c70778bb8100         mov dword ptr [edi], 0x81bb78
// 004668d4  c706c4bb8100         mov dword ptr [esi], 0x81bbc4
// 004668da  c74654b0bb8100       mov dword ptr [esi + 0x54], 0x81bbb0
// 004668e1  c703a8bb8100         mov dword ptr [ebx], 0x81bba8
// 004668e7  c70790bb8100         mov dword ptr [edi], 0x81bb90
// 004668ed  89aeb8010000         mov dword ptr [esi + 0x1b8], ebp
// 004668f3  89aebc010000         mov dword ptr [esi + 0x1bc], ebp
// 004668f9  89aec0010000         mov dword ptr [esi + 0x1c0], ebp
// 004668ff  5f                   pop edi
// 00466900  89aec4010000         mov dword ptr [esi + 0x1c4], ebp
// 00466906  8bc6                 mov eax, esi
// 00466908  5e                   pop esi
// 00466909  5d                   pop ebp
// 0046690a  5b                   pop ebx
// 0046690b  64890d00000000       mov dword ptr fs:[0], ecx
// 00466912  83c410               add esp, 0x10
// 00466915  c3                   ret 

extern unsigned long baseTable[];
extern unsigned long secondaryTable[];
extern unsigned long registryTable[];
extern unsigned long listenerBaseTable[];
extern unsigned long listenerTable[];

struct Base {
    unsigned long* volatile tablePointer;
    char padding0[0x50];
    unsigned long* volatile secondaryTable;
    char padding1[0x138];

    Base();
    ~Base();
};

struct S {
    unsigned long* volatile tablePointer;

    S();
    ~S();
    S* initialize();
};

inline S::S()
{
    initialize();
}

struct ListenerBase {
    unsigned long* volatile tablePointer;
    char padding[0x20];

    ListenerBase();
    ~ListenerBase();
};

struct Listener : ListenerBase {
    Listener();
};

inline Listener::Listener()
{
    tablePointer = listenerBaseTable;
}

struct FilteredListener : Base {
    S registryEntry;
    Listener listener;
    volatile unsigned long first;
    volatile unsigned long second;
    volatile unsigned long third;
    volatile unsigned long fourth;

    FilteredListener();
};

FilteredListener::FilteredListener()
{
    tablePointer = baseTable;
    Base::secondaryTable = ::secondaryTable;
    registryEntry.tablePointer = registryTable;
    listener.tablePointer = listenerTable;
    first = 0;
    second = 0;
    third = 0;
    fourth = 0;
}
