// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00642210  unit: RBX::VWidget::?$NonFactoryProduct  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00642210
//
// 00642210  8b81d0feffff         mov eax, dword ptr [ecx - 0x8c]
// 00642216  8b5078               mov edx, dword ptr [eax + 0x78]
// 00642219  56                   push esi
// 0064221a  8db1d0feffff         lea esi, [ecx - 0x8c]
// 00642220  8bce                 mov ecx, esi
// 00642222  ffd2                 call edx
// 00642224  84c0                 test al, al
// 00642226  7425                 je 0x64224d
// 00642228  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0064222c  8b01                 mov eax, dword ptr [ecx]
// 0064222e  83f801               cmp eax, 1
// 00642231  7c1a                 jl 0x64224d
// 00642233  83f807               cmp eax, 7
// 00642236  7f15                 jg 0x64224d
// 00642238  57                   push edi
// 00642239  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0064223d  51                   push ecx
// 0064223e  57                   push edi
// 0064223f  8bce                 mov ecx, esi
// 00642241  e8aafdffff           call 0x641ff0
// 00642246  8bc7                 mov eax, edi
// 00642248  5f                   pop edi
// 00642249  5e                   pop esi
// 0064224a  c20800               ret 8
// 0064224d  8b442408             mov eax, dword ptr [esp + 8]
// 00642251  c7400400000000       mov dword ptr [eax + 4], 0
// 00642258  c70000000000         mov dword ptr [eax], 0
// 0064225e  5e                   pop esi
// 0064225f  c20800               ret 8



enum EventType {
    EventNone = 0,
    EventFirst = 1,
    EventLast = 7
};

struct Event {
    EventType type;
};

struct Result {
    void* first;
    void* second;
    __forceinline Result();
};

__forceinline Result::Result()
{
    second = 0;
    first = 0;
}

struct Base;

struct Table {
    void* slots[31];
    bool (__thiscall* enabled)(Base*);
};

struct Base {
    Table* table;
    Result process(Event*);
};

struct Widget {
    Result handle(Event*);
};

Result Widget::handle(Event* event)
{
    Base* base = reinterpret_cast<Base*>(
        reinterpret_cast<char*>(this) - 0x8c);

    if (base->table->enabled(base)) {
        int type = (int)event->type;
        if (type < 1)
            return Result();
        if (type > 7)
            return Result();
        return base->process(event);
    }

    return Result();
}
