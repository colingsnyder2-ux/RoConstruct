// from server: 100% by EspClaude
// roc 2009-06 0066a280  unit: RBX::VModelInstance::?$BoundFuncDesc  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0066a280
//
// 0066a280  6aff                 push -1
// 0066a282  688ec58600           push 0x86c58e
// 0066a287  64a100000000         mov eax, dword ptr fs:[0]
// 0066a28d  50                   push eax
// 0066a28e  64892500000000       mov dword ptr fs:[0], esp
// 0066a295  51                   push ecx
// 0066a296  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0066a29a  56                   push esi
// 0066a29b  8bf1                 mov esi, ecx
// 0066a29d  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0066a2a1  50                   push eax
// 0066a2a2  51                   push ecx
// 0066a2a3  8974240c             mov dword ptr [esp + 0xc], esi
// 0066a2a7  e8f423f8ff           call 0x5ec6a0
// 0066a2ac  50                   push eax
// 0066a2ad  8bce                 mov ecx, esi
// 0066a2af  e8ecd00000           call 0x6773a0
// 0066a2b4  8b542418             mov edx, dword ptr [esp + 0x18]
// 0066a2b8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0066a2bc  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0066a2c0  895638               mov dword ptr [esi + 0x38], edx
// 0066a2c3  89463c               mov dword ptr [esi + 0x3c], eax
// 0066a2c6  894e40               mov dword ptr [esi + 0x40], ecx
// 0066a2c9  8d4e44               lea ecx, [esi + 0x44]
// 0066a2cc  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0066a2d4  c70630308e00         mov dword ptr [esi], 0x8e3030
// 0066a2da  e82121fdff           call 0x63c400
// 0066a2df  8d4e4c               lea ecx, [esi + 0x4c]
// 0066a2e2  c644241001           mov byte ptr [esp + 0x10], 1
// 0066a2e7  e81421fdff           call 0x63c400
// 0066a2ec  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0066a2f0  8b442428             mov eax, dword ptr [esp + 0x28]
// 0066a2f4  52                   push edx
// 0066a2f5  50                   push eax
// 0066a2f6  8bce                 mov ecx, esi
// 0066a2f8  c644241802           mov byte ptr [esp + 0x18], 2
// 0066a2fd  e87ed2ffff           call 0x667580
// 0066a302  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0066a306  8bc6                 mov eax, esi
// 0066a308  5e                   pop esi
// 0066a309  64890d00000000       mov dword ptr fs:[0], ecx
// 0066a310  83c410               add esp, 0x10
// 0066a313  c21c00               ret 0x1c
// copied from an identical function in another client (function ??0S@ns_ROCX000013@@QAE@UMember@1@PBDPAX2H@Z)

namespace ns_ROCX000013 {
extern "C" void* __stdcall makeDescriptor(const char*, int);

struct Base {
    virtual ~Base();
    char storage[0x34];
    Base(void*);
};

struct Value {
    void* type;
    int data;
    Value();
    ~Value();
};

struct Member {
    int a;
    int b;
    int c;
};

struct S : Base {
    Member member;
    Value value0;
    Value value1;

    S(Member, const char*, void*, void*, int);
    virtual ~S();
    void initialize(void*, void*);
};

S::S(Member m, const char* name, void* first, void* second, int flags)
    : Base(makeDescriptor(name, flags)),
      member(m), value0(), value1()
{
    initialize(first, second);
}
}
