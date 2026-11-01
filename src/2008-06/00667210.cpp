// from server: 100% by colin
// from server: 94% by EspClaude
// roc 2008-06 00667210  unit: RBX::HUMAN::StrafingNoPhysics  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00667210
//
// 00667210  6aff                 push -1
// 00667212  6838c27d00           push 0x7dc238
// 00667217  64a100000000         mov eax, dword ptr fs:[0]
// 0066721d  50                   push eax
// 0066721e  64892500000000       mov dword ptr fs:[0], esp
// 00667225  51                   push ecx
// 00667226  56                   push esi
// 00667227  57                   push edi
// 00667228  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0066722c  8bf1                 mov esi, ecx
// 0066722e  57                   push edi
// 0066722f  8974240c             mov dword ptr [esp + 0xc], esi
// 00667233  e8387e0000           call 0x66f070
// 00667238  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00667240  c706b0cd8400         mov dword ptr [esi], 0x84cdb0
// 00667246  c74604a8cd8400       mov dword ptr [esi + 4], 0x84cda8
// 0066724d  c786a000000098cd8400 mov dword ptr [esi + 0xa0], 0x84cd98
// 00667257  85ff                 test edi, edi
// 00667259  7405                 je 0x667260
// 0066725b  8d4714               lea eax, [edi + 0x14]
// 0066725e  eb02                 jmp 0x667262
// 00667260  33c0                 xor eax, eax
// 00667262  50                   push eax
// 00667263  b948a39700           mov ecx, 0x97a348
// 00667268  e8b343f0ff           call 0x56b620
// 0066726d  85c0                 test eax, eax
// 0066726f  740f                 je 0x667280
// 00667271  6a00                 push 0
// 00667273  8d4c2420             lea ecx, [esp + 0x20]
// 00667277  51                   push ecx
// 00667278  8d4810               lea ecx, [eax + 0x10]
// 0066727b  e880acf7ff           call 0x5e1f00
// 00667280  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00667284  5f                   pop edi
// 00667285  8bc6                 mov eax, esi
// 00667287  5e                   pop esi
// 00667288  64890d00000000       mov dword ptr fs:[0], ecx
// 0066728f  83c410               add esp, 0x10
// 00667292  c20400               ret 4

// from server: 88% by colin
// roc 2008-06 00667210  unit: RBX::HUMAN::StrafingNoPhysics  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00667210
//
// 00667210  6aff                 push -1
// 00667212  6838c27d00           push 0x7dc238
// 00667217  64a100000000         mov eax, dword ptr fs:[0]
// 0066721d  50                   push eax
// 0066721e  64892500000000       mov dword ptr fs:[0], esp
// 00667225  51                   push ecx
// 00667226  56                   push esi
// 00667227  57                   push edi
// 00667228  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0066722c  8bf1                 mov esi, ecx
// 0066722e  57                   push edi
// 0066722f  8974240c             mov dword ptr [esp + 0xc], esi
// 00667233  e8387e0000           call 0x66f070
// 00667238  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00667240  c706b0cd8400         mov dword ptr [esi], 0x84cdb0
// 00667246  c74604a8cd8400       mov dword ptr [esi + 4], 0x84cda8
// 0066724d  c786a000000098cd8400 mov dword ptr [esi + 0xa0], 0x84cd98
// 00667257  85ff                 test edi, edi
// 00667259  7405                 je 0x667260
// 0066725b  8d4714               lea eax, [edi + 0x14]
// 0066725e  eb02                 jmp 0x667262
// 00667260  33c0                 xor eax, eax
// 00667262  50                   push eax
// 00667263  b948a39700           mov ecx, 0x97a348
// 00667268  e8b343f0ff           call 0x56b620
// 0066726d  85c0                 test eax, eax
// 0066726f  740f                 je 0x667280
// 00667271  6a00                 push 0
// 00667273  8d4c2420             lea ecx, [esp + 0x20]
// 00667277  51                   push ecx
// 00667278  8d4810               lea ecx, [eax + 0x10]
// 0066727b  e880acf7ff           call 0x5e1f00
// 00667280  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00667284  5f                   pop edi
// 00667285  8bc6                 mov eax, esi
// 00667287  5e                   pop esi
// 00667288  64890d00000000       mov dword ptr fs:[0], ecx
// 0066728f  83c410               add esp, 0x10
// 00667292  c20400               ret 4

struct Object
{
    unsigned char padding[20];
    unsigned long part;
};

extern unsigned char table_84cdb0[];
extern unsigned char table_84cda8[];
extern unsigned char table_84cd98[];

struct Base
{
    void* table0;
    void* table4;
    unsigned char padding[152];
    void* table160;

    Base(Object*);
    ~Base();
};

struct Unusable
{
    Unusable() {}
};

struct Signal
{
    Unusable invoke(int value);
};

struct Node
{
    unsigned char padding[16];
    Signal signal;
};

struct Registry
{
    Node* lookup(void*);
};

extern Registry registry_97a348;

struct S : Base
{
    S(Object*);
};

S::S(Object* object) : Base(object)
{
    table0 = table_84cdb0;
    table4 = table_84cda8;
    table160 = table_84cd98;

    Node* node = registry_97a348.lookup(object ? &object->part : 0);
    if (node) {
        node->signal.invoke(0);
    }
}
