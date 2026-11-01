// from server: 100% by EspClaude
// from server: 96% by king_originala
// roc 2008-06 00464af0  unit: RBX::VRunService::?$MarshaledListener  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00464af0
//
// 00464af0  6aff                 push -1
// 00464af2  6883327c00           push 0x7c3283
// 00464af7  64a100000000         mov eax, dword ptr fs:[0]
// 00464afd  50                   push eax
// 00464afe  64892500000000       mov dword ptr fs:[0], esp
// 00464b05  51                   push ecx
// 00464b06  56                   push esi
// 00464b07  8bf1                 mov esi, ecx
// 00464b09  89742404             mov dword ptr [esp + 4], esi
// 00464b0d  33c0                 xor eax, eax
// 00464b0f  c70690b38100         mov dword ptr [esi], 0x81b390
// 00464b15  894604               mov dword ptr [esi + 4], eax
// 00464b18  89442410             mov dword ptr [esp + 0x10], eax
// 00464b1c  894608               mov dword ptr [esi + 8], eax
// 00464b1f  8b442418             mov eax, dword ptr [esp + 0x18]
// 00464b23  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00464b27  8b542424             mov edx, dword ptr [esp + 0x24]
// 00464b2b  89460c               mov dword ptr [esi + 0xc], eax
// 00464b2e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00464b32  894e10               mov dword ptr [esi + 0x10], ecx
// 00464b35  50                   push eax
// 00464b36  8bce                 mov ecx, esi
// 00464b38  c644241401           mov byte ptr [esp + 0x14], 1
// 00464b3d  895614               mov dword ptr [esi + 0x14], edx
// 00464b40  e88b26ffff           call 0x4571d0
// 00464b45  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00464b49  8bc6                 mov eax, esi
// 00464b4b  5e                   pop esi
// 00464b4c  64890d00000000       mov dword ptr fs:[0], ecx
// 00464b53  83c410               add esp, 0x10
// 00464b56  c21000               ret 0x10

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
