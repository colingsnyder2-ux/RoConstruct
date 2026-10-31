// from server: 100% by EspClaude
// roc 2009-06 004ddd20  unit: RBX::Network::ConcurrentRakPeer::PacketJob  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ddd20
//
// 004ddd20  6aff                 push -1
// 004ddd22  68d9b88500           push 0x85b8d9
// 004ddd27  64a100000000         mov eax, dword ptr fs:[0]
// 004ddd2d  50                   push eax
// 004ddd2e  64892500000000       mov dword ptr fs:[0], esp
// 004ddd35  83ec1c               sub esp, 0x1c
// 004ddd38  8d0c24               lea ecx, [esp]
// 004ddd3b  ff15c0e48900         call dword ptr [0x89e4c0]
// 004ddd41  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004ddd45  8d0424               lea eax, [esp]
// 004ddd48  50                   push eax
// 004ddd49  51                   push ecx
// 004ddd4a  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004ddd52  e8c9f7ffff           call 0x4dd520
// 004ddd57  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004ddd5b  8b4104               mov eax, dword ptr [ecx + 4]
// 004ddd5e  83c408               add esp, 8
// 004ddd61  85c0                 test eax, eax
// 004ddd63  7411                 je 0x4ddd76
// 004ddd65  8b09                 mov ecx, dword ptr [ecx]
// 004ddd67  8b11                 mov edx, dword ptr [ecx]
// 004ddd69  56                   push esi
// 004ddd6a  8d742404             lea esi, [esp + 4]
// 004ddd6e  56                   push esi
// 004ddd6f  50                   push eax
// 004ddd70  8b4220               mov eax, dword ptr [edx + 0x20]
// 004ddd73  ffd0                 call eax
// 004ddd75  5e                   pop esi
// 004ddd76  8d0c24               lea ecx, [esp]
// 004ddd79  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004ddd81  ff15c4e48900         call dword ptr [0x89e4c4]
// 004ddd87  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004ddd8b  64890d00000000       mov dword ptr fs:[0], ecx
// 004ddd92  83c428               add esp, 0x28
// 004ddd95  c3                   ret 
// copied from an identical function in another client (function ?create@ns_ROCX000069@@YAXPAUContext@1@PBD@Z)

namespace ns_ROCX000069 {
struct String;
extern String* (__thiscall* stringDefaultConstruct)(String*);
extern void (__thiscall* stringDestroy)(String*);

struct String {
    char storage[28];
    String();
    ~String();
};

inline String::String()
{
    stringDefaultConstruct(this);
}

inline String::~String()
{
    stringDestroy(this);
}

extern void __cdecl makeString(const char*, String*);

struct Receiver {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void notify(int, const String&) = 0;
};

struct Context {
    Receiver* receiver;
    int value;
};

void __cdecl create(Context* context, const char* text)
{
    String string;
    makeString(text, &string);
    if (context->value)
        context->receiver->notify(context->value, string);
}
}
