// from server: 100% by Yeetserama
// roc 2010-06 00671020  unit: RBX::VHumanoid::?$BoundFuncDesc  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00671020
//
// 00671020  6aff                 push -1
// 00671022  68cec59900           push 0x99c5ce
// 00671027  64a100000000         mov eax, dword ptr fs:[0]
// 0067102d  50                   push eax
// 0067102e  64892500000000       mov dword ptr fs:[0], esp
// 00671035  51                   push ecx
// 00671036  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0067103a  56                   push esi
// 0067103b  8bf1                 mov esi, ecx
// 0067103d  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00671041  50                   push eax
// 00671042  51                   push ecx
// 00671043  8974240c             mov dword ptr [esp + 0xc], esi
// 00671047  e8a446f4ff           call 0x5b56f0
// 0067104c  50                   push eax
// 0067104d  8bce                 mov ecx, esi
// 0067104f  e8ac910000           call 0x67a200
// 00671054  8b542418             mov edx, dword ptr [esp + 0x18]
// 00671058  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0067105c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00671060  895638               mov dword ptr [esi + 0x38], edx
// 00671063  89463c               mov dword ptr [esi + 0x3c], eax
// 00671066  894e40               mov dword ptr [esi + 0x40], ecx
// 00671069  8d4e44               lea ecx, [esi + 0x44]
// 0067106c  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00671074  c70680cba300         mov dword ptr [esi], 0xa3cb80
// 0067107a  e80177faff           call 0x618780
// 0067107f  8d4e4c               lea ecx, [esi + 0x4c]
// 00671082  c644241001           mov byte ptr [esp + 0x10], 1
// 00671087  e8f476faff           call 0x618780
// 0067108c  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00671090  8b442428             mov eax, dword ptr [esp + 0x28]
// 00671094  52                   push edx
// 00671095  50                   push eax
// 00671096  8bce                 mov ecx, esi
// 00671098  c644241802           mov byte ptr [esp + 0x18], 2
// 0067109d  e8fec6ffff           call 0x66d7a0
// 006710a2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006710a6  8bc6                 mov eax, esi
// 006710a8  5e                   pop esi
// 006710a9  64890d00000000       mov dword ptr fs:[0], ecx
// 006710b0  83c410               add esp, 0x10
// 006710b3  c21c00               ret 0x1c
// copied from an identical function in another client (function ??0S@ns_ROCX000017@@QAE@UMember@1@PBDPAX2H@Z)

namespace ns_ROCX000017 {
// from server: 100% by king_originala
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
