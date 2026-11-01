// from server: 100% by Yeetserama
// roc 2007-08 00460d60  unit: RBX::VRunService::?$MarshaledListener  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460d60
//
// 00460d60  6aff                 push -1
// 00460d62  6893287400           push 0x742893
// 00460d67  64a100000000         mov eax, dword ptr fs:[0]
// 00460d6d  50                   push eax
// 00460d6e  51                   push ecx
// 00460d6f  56                   push esi
// 00460d70  a188518b00           mov eax, dword ptr [0x8b5188]
// 00460d75  33c4                 xor eax, esp
// 00460d77  50                   push eax
// 00460d78  8d44240c             lea eax, [esp + 0xc]
// 00460d7c  64a300000000         mov dword ptr fs:[0], eax
// 00460d82  8bf1                 mov esi, ecx
// 00460d84  89742408             mov dword ptr [esp + 8], esi
// 00460d88  33c0                 xor eax, eax
// 00460d8a  c706884b7900         mov dword ptr [esi], 0x794b88
// 00460d90  894604               mov dword ptr [esi + 4], eax
// 00460d93  89442414             mov dword ptr [esp + 0x14], eax
// 00460d97  894608               mov dword ptr [esi + 8], eax
// 00460d9a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00460d9e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00460da2  8b542428             mov edx, dword ptr [esp + 0x28]
// 00460da6  89460c               mov dword ptr [esi + 0xc], eax
// 00460da9  8b442420             mov eax, dword ptr [esp + 0x20]
// 00460dad  894e10               mov dword ptr [esi + 0x10], ecx
// 00460db0  50                   push eax
// 00460db1  8bce                 mov ecx, esi
// 00460db3  c644241801           mov byte ptr [esp + 0x18], 1
// 00460db8  895614               mov dword ptr [esi + 0x14], edx
// 00460dbb  e89033ffff           call 0x454150
// 00460dc0  8bc6                 mov eax, esi
// 00460dc2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00460dc6  64890d00000000       mov dword ptr fs:[0], ecx
// 00460dcd  59                   pop ecx
// 00460dce  5e                   pop esi
// 00460dcf  83c410               add esp, 0x10
// 00460dd2  c21000               ret 0x10
// copied from an identical function in another client (function ??0Listener@ns_ROCX000018@@QAE@PAX000@Z)

namespace ns_ROCX000018 {
struct Slot
{
    void *pointer;
    Slot() : pointer(0) {}
    ~Slot();
};

class EventDataBase
{
public:
    virtual ~EventDataBase() {}
};
struct Listener : public EventDataBase
{
    virtual ~Listener();

    void *data;
    Slot first;
    void *argument;
    void *context;
    void *callback;

    Listener(void *, void *, void *, void *);
    void attach(void *);
};

Listener::Listener(void *a, void *b, void *c, void *d)
    : data(0), argument(a), context(c), callback(d)
{
    attach(b);
}
}
