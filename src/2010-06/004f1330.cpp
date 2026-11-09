// from server: 100% by Yeetserama
// roc 2010-06 004f1330  unit: RBX::VMotor6D::?$FactoryProduct::Creator  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004f1330
//
// 004f1330  6aff                 push -1
// 004f1332  6898c19800           push 0x98c198
// 004f1337  64a100000000         mov eax, dword ptr fs:[0]
// 004f133d  50                   push eax
// 004f133e  64892500000000       mov dword ptr fs:[0], esp
// 004f1345  51                   push ecx
// 004f1346  56                   push esi
// 004f1347  8bf1                 mov esi, ecx
// 004f1349  89742404             mov dword ptr [esp + 4], esi
// 004f134d  a100a49e00           mov eax, dword ptr [0x9ea400]
// 004f1352  50                   push eax
// 004f1353  6880000000           push 0x80
// 004f1358  6a1c                 push 0x1c
// 004f135a  8d4e20               lea ecx, [esi + 0x20]
// 004f135d  51                   push ecx
// 004f135e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004f1366  e873772b00           call 0x7a8ade
// 004f136b  8bce                 mov ecx, esi
// 004f136d  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004f1375  e846c4f8ff           call 0x47d7c0
// 004f137a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004f137e  5e                   pop esi
// 004f137f  64890d00000000       mov dword ptr fs:[0], ecx
// 004f1386  83c410               add esp, 0x10
// 004f1389  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX000014@@QAE@XZ)

namespace ns_ROCX000014 {
// from server: 100% by king_originala
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
