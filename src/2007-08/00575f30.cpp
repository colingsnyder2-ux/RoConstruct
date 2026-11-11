// from server: 100% by EspClaude
// from server: 91% by tajop
// roc 2007-08 00575f30  unit: G3D::VCoordinateFrame::?$TypedPropertyDescriptor  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00575f30
//
// 00575f30  83ec0c               sub esp, 0xc
// 00575f33  53                   push ebx
// 00575f34  55                   push ebp
// 00575f35  56                   push esi
// 00575f36  8bf1                 mov esi, ecx
// 00575f38  8b5608               mov edx, dword ptr [esi + 8]
// 00575f3b  33c0                 xor eax, eax
// 00575f3d  85d2                 test edx, edx
// 00575f3f  57                   push edi
// 00575f40  89442410             mov dword ptr [esp + 0x10], eax
// 00575f44  7504                 jne 0x575f4a
// 00575f46  33c9                 xor ecx, ecx
// 00575f48  eb08                 jmp 0x575f52
// 00575f4a  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00575f4d  2bca                 sub ecx, edx
// 00575f4f  c1f902               sar ecx, 2
// 00575f52  85c9                 test ecx, ecx
// 00575f54  8b5614               mov edx, dword ptr [esi + 0x14]
// 00575f57  8d7c2410             lea edi, [esp + 0x10]
// 00575f5b  894c2414             mov dword ptr [esp + 0x14], ecx
// 00575f5f  89542418             mov dword ptr [esp + 0x18], edx
// 00575f63  897e14               mov dword ptr [esi + 0x14], edi
// 00575f66  7656                 jbe 0x575fbe
// 00575f68  8a5c2420             mov bl, byte ptr [esp + 0x20]
// 00575f6c  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 00575f72  8b5608               mov edx, dword ptr [esi + 8]
// 00575f75  85d2                 test edx, edx
// 00575f77  8bf8                 mov edi, eax
// 00575f79  740c                 je 0x575f87
// 00575f7b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00575f7e  2bca                 sub ecx, edx
// 00575f80  c1f902               sar ecx, 2
// 00575f83  3bc1                 cmp eax, ecx
// 00575f85  7202                 jb 0x575f89
// 00575f87  ffd5                 call ebp
// 00575f89  8b4608               mov eax, dword ptr [esi + 8]
// 00575f8c  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00575f8f  50                   push eax
// 00575f90  51                   push ecx
// 00575f91  8bc4                 mov eax, esp
// 00575f93  8bce                 mov ecx, esi
// 00575f95  8818                 mov byte ptr [eax], bl
// 00575f97  e8f4eeffff           call 0x574e90
// 00575f9c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00575fa0  83c001               add eax, 1
// 00575fa3  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00575fa7  89442410             mov dword ptr [esp + 0x10], eax
// 00575fab  72c5                 jb 0x575f72
// 00575fad  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00575fb1  894e14               mov dword ptr [esi + 0x14], ecx
// 00575fb4  5f                   pop edi
// 00575fb5  5e                   pop esi
// 00575fb6  5d                   pop ebp
// 00575fb7  5b                   pop ebx
// 00575fb8  83c40c               add esp, 0xc
// 00575fbb  c20400               ret 4
// 00575fbe  5f                   pop edi
// 00575fbf  895614               mov dword ptr [esi + 0x14], edx
// 00575fc2  5e                   pop esi
// 00575fc3  5d                   pop ebp
// 00575fc4  5b                   pop ebx
// 00575fc5  83c40c               add esp, 0xc
// 00575fc8  c20400               ret 4

// call ebp with ebp = [IAT slot]: dllimport CRT call hoisted out of the loop by the compiler
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct Listener;

struct Event
{
    char value;
    Event(const Event& o) : value(o.value) {}
};

struct ListenerVector
{
    void* proxy;
    Listener** first;
    Listener** last;
    Listener** endOfStorage;

    unsigned size() const { return first == 0 ? 0 : (unsigned)(last - first); }
    Listener* at(unsigned pos) const
    {
        if (pos >= size())
            _invalid_parameter_noinfo();
        return first[pos];
    }
};

struct RaiseContext
{
    unsigned index;
    unsigned count;
    RaiseContext* prev;
};

struct Notifier
{
    void* vtbl;
    ListenerVector listeners;
    RaiseContext* raising;

    void raise(Event e);
    void raiseTo(Event e, Listener* listener);
};

void Notifier::raise(Event e)
{
    RaiseContext ctx;
    ctx.index = 0;
    ctx.count = listeners.size();
    ctx.prev = raising;
    raising = &ctx;
    for (; ctx.index < ctx.count; ++ctx.index)
        raiseTo(e, listeners.at(ctx.index));
    raising = ctx.prev;
}
