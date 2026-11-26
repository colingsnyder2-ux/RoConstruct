// from server: 100% by Xemicl
// roc 2012-06 0056d3b0  unit: RBX::Network::IdSerializer  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056d3b0
//
// 0056d3b0  6aff                 push -1
// 0056d3b2  684961ab00           push 0xab6149
// 0056d3b7  64a100000000         mov eax, dword ptr fs:[0]
// 0056d3bd  50                   push eax
// 0056d3be  64892500000000       mov dword ptr fs:[0], esp
// 0056d3c5  83ec1c               sub esp, 0x1c
// 0056d3c8  8d0c24               lea ecx, [esp]
// 0056d3cb  ff155426b200         call dword ptr [0xb22654]
// 0056d3d1  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0056d3d5  8d0424               lea eax, [esp]
// 0056d3d8  50                   push eax
// 0056d3d9  51                   push ecx
// 0056d3da  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0056d3e2  e819f3ffff           call 0x56c700
// 0056d3e7  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0056d3eb  8b4104               mov eax, dword ptr [ecx + 4]
// 0056d3ee  83c408               add esp, 8
// 0056d3f1  85c0                 test eax, eax
// 0056d3f3  7411                 je 0x56d406
// 0056d3f5  8b09                 mov ecx, dword ptr [ecx]
// 0056d3f7  8b11                 mov edx, dword ptr [ecx]
// 0056d3f9  56                   push esi
// 0056d3fa  8d742404             lea esi, [esp + 4]
// 0056d3fe  56                   push esi
// 0056d3ff  50                   push eax
// 0056d400  8b4220               mov eax, dword ptr [edx + 0x20]
// 0056d403  ffd0                 call eax
// 0056d405  5e                   pop esi
// 0056d406  8d0c24               lea ecx, [esp]
// 0056d409  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0056d411  ff153c26b200         call dword ptr [0xb2263c]
// 0056d417  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056d41b  64890d00000000       mov dword ptr fs:[0], ecx
// 0056d422  83c428               add esp, 0x28
// 0056d425  c3                   ret 
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