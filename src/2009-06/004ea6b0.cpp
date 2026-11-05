// from server: 100% by EspClaude
// roc 2009-06 004ea6b0  unit: RBX::VMotor::?$FactoryProduct::Creator  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ea6b0
//
// 004ea6b0  6aff                 push -1
// 004ea6b2  6878c28500           push 0x85c278
// 004ea6b7  64a100000000         mov eax, dword ptr fs:[0]
// 004ea6bd  50                   push eax
// 004ea6be  64892500000000       mov dword ptr fs:[0], esp
// 004ea6c5  51                   push ecx
// 004ea6c6  56                   push esi
// 004ea6c7  8bf1                 mov esi, ecx
// 004ea6c9  89742404             mov dword ptr [esp + 4], esi
// 004ea6cd  a1c4e48900           mov eax, dword ptr [0x89e4c4]
// 004ea6d2  50                   push eax
// 004ea6d3  6880000000           push 0x80
// 004ea6d8  6a1c                 push 0x1c
// 004ea6da  8d4e20               lea ecx, [esi + 0x20]
// 004ea6dd  51                   push ecx
// 004ea6de  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004ea6e6  e88bf42200           call 0x719b76
// 004ea6eb  8bce                 mov ecx, esi
// 004ea6ed  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004ea6f5  e8062e0e00           call 0x5cd500
// 004ea6fa  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004ea6fe  5e                   pop esi
// 004ea6ff  64890d00000000       mov dword ptr fs:[0], ecx
// 004ea706  83c410               add esp, 0x10
// 004ea709  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX0000be@@QAE@XZ)

namespace ns_ROCX0000be {
typedef void (__thiscall *DestructorProc)(void *);

extern DestructorProc stringDestructor;

void __stdcall destroyArray(
    void *array, unsigned int elementSize,
    int elementCount, DestructorProc destructor);

struct Base {
    char storage[32];
    ~Base();
};

struct S : Base {
    char strings[128 * 28];
    ~S();
};

S::~S()
{
    destroyArray(strings, 28, 128, stringDestructor);
}
}
