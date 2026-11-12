// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 0043cb80  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043cb80
//
// 0043cb80  6aff                 push -1
// 0043cb82  6838eb7300           push 0x73eb38
// 0043cb87  64a100000000         mov eax, dword ptr fs:[0]
// 0043cb8d  50                   push eax
// 0043cb8e  83ec0c               sub esp, 0xc
// 0043cb91  56                   push esi
// 0043cb92  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043cb97  33c4                 xor eax, esp
// 0043cb99  50                   push eax
// 0043cb9a  8d442414             lea eax, [esp + 0x14]
// 0043cb9e  64a300000000         mov dword ptr fs:[0], eax
// 0043cba4  8bf1                 mov esi, ecx
// 0043cba6  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 0043cbac  8b8888010000         mov ecx, dword ptr [eax + 0x188]
// 0043cbb2  51                   push ecx
// 0043cbb3  8d4c240c             lea ecx, [esp + 0xc]
// 0043cbb7  e894ccffff           call 0x439850
// 0043cbbc  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043cbc0  85c0                 test eax, eax
// 0043cbc2  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0043cbca  7405                 je 0x43cbd1
// 0043cbcc  83c004               add eax, 4
// 0043cbcf  eb02                 jmp 0x43cbd3
// 0043cbd1  33c0                 xor eax, eax
// 0043cbd3  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0043cbd9  8b742428             mov esi, dword ptr [esp + 0x28]
// 0043cbdd  8b11                 mov edx, dword ptr [ecx]
// 0043cbdf  56                   push esi
// 0043cbe0  50                   push eax
// 0043cbe1  8b4214               mov eax, dword ptr [edx + 0x14]
// 0043cbe4  ffd0                 call eax
// 0043cbe6  8d4c2408             lea ecx, [esp + 8]
// 0043cbea  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043cbf2  e8a9c91100           call 0x5595a0
// 0043cbf7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043cbfb  64890d00000000       mov dword ptr fs:[0], ecx
// 0043cc02  59                   pop ecx
// 0043cc03  5e                   pop esi
// 0043cc04  83c418               add esp, 0x18
// 0043cc07  c20800               ret 8

struct String;

struct Lock {
    void *a;
    void *b;
    void *c;
    explicit Lock(unsigned int);
    ~Lock();
};

struct Owner {
    char pad[0x188];
    unsigned int lockArg;
};

struct BaseA { void *p; };
struct BaseB { int q; };
struct Instance : BaseA, BaseB {};

struct StringProperty {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setValue(BaseB *obj, const String &value) const;
};

struct StringItem {
    char pad[0x114];
    Owner *owner;
    StringProperty *prop;
    void setValue(Instance *instance, const String &value);
};

void StringItem::setValue(Instance *instance, const String &value)
{
    Lock lock(owner->lockArg);
    prop->setValue(instance, value);
}
