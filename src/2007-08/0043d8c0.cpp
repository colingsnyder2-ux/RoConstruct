// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 0043d8c0  unit: RBX::VSoundId::?$XItem  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043d8c0
//
// 0043d8c0  6aff                 push -1
// 0043d8c2  6881eb7300           push 0x73eb81
// 0043d8c7  64a100000000         mov eax, dword ptr fs:[0]
// 0043d8cd  50                   push eax
// 0043d8ce  83ec10               sub esp, 0x10
// 0043d8d1  56                   push esi
// 0043d8d2  57                   push edi
// 0043d8d3  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043d8d8  33c4                 xor eax, esp
// 0043d8da  50                   push eax
// 0043d8db  8d44241c             lea eax, [esp + 0x1c]
// 0043d8df  64a300000000         mov dword ptr fs:[0], eax
// 0043d8e5  8bf1                 mov esi, ecx
// 0043d8e7  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0043d8ef  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 0043d8f5  8b8888010000         mov ecx, dword ptr [eax + 0x188]
// 0043d8fb  51                   push ecx
// 0043d8fc  8d4c2414             lea ecx, [esp + 0x14]
// 0043d900  e84bbfffff           call 0x439850
// 0043d905  8b442430             mov eax, dword ptr [esp + 0x30]
// 0043d909  85c0                 test eax, eax
// 0043d90b  c744242401000000     mov dword ptr [esp + 0x24], 1
// 0043d913  7405                 je 0x43d91a
// 0043d915  83c004               add eax, 4
// 0043d918  eb02                 jmp 0x43d91c
// 0043d91a  33c0                 xor eax, eax
// 0043d91c  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0043d920  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0043d926  50                   push eax
// 0043d927  57                   push edi
// 0043d928  e853211800           call 0x5bfa80
// 0043d92d  8d4c2410             lea ecx, [esp + 0x10]
// 0043d931  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0043d939  c644242400           mov byte ptr [esp + 0x24], 0
// 0043d93e  e85dbc1100           call 0x5595a0
// 0043d943  8bc7                 mov eax, edi
// 0043d945  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0043d949  64890d00000000       mov dword ptr fs:[0], ecx
// 0043d950  59                   pop ecx
// 0043d951  5f                   pop edi
// 0043d952  5e                   pop esi
// 0043d953  83c41c               add esp, 0x1c
// 0043d956  c20800               ret 8

struct Mutex;
struct Lock {
    int s[3];
    Lock(Mutex* m);
    ~Lock();
};

struct Result {
    void* px;
    void* pn;
    ~Result();
};

struct BaseA { int a; };
struct BaseB { int b; };
struct Item : BaseA, BaseB { };

struct Owner { char pad[0x188]; Mutex* mutex; };

struct Service {
    Result find(BaseB* item);
};

struct SoundId {
    char pad[0x114];
    Owner* owner;
    Service* service;
    Result method(Item* item);
};

Result SoundId::method(Item* item)
{
    Lock lock(owner->mutex);
    return service->find(item);
}
