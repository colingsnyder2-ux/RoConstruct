// from server: 100% by Yeetserama
// roc 2010-06 0043b510  unit: _NVCXTPPropertyGridItemBool::?$XItem  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0043b510
//
// 0043b510  56                   push esi
// 0043b511  8bf1                 mov esi, ecx
// 0043b513  8b8630010000         mov eax, dword ptr [esi + 0x130]
// 0043b519  85c0                 test eax, eax
// 0043b51b  7409                 je 0x43b526
// 0043b51d  50                   push eax
// 0043b51e  e877c43600           call 0x7a799a
// 0043b523  83c404               add esp, 4
// 0043b526  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 0043b52c  50                   push eax
// 0043b52d  c7863001000000000000 mov dword ptr [esi + 0x130], 0
// 0043b537  c7863401000000000000 mov dword ptr [esi + 0x134], 0
// 0043b541  c7863801000000000000 mov dword ptr [esi + 0x138], 0
// 0043b54b  e84ac43600           call 0x7a799a
// 0043b550  83c404               add esp, 4
// 0043b553  8bce                 mov ecx, esi
// 0043b555  e846373e00           call 0x81eca0
// 0043b55a  f644240801           test byte ptr [esp + 8], 1
// 0043b55f  7409                 je 0x43b56a
// 0043b561  56                   push esi
// 0043b562  e833c43600           call 0x7a799a
// 0043b567  83c404               add esp, 4
// 0043b56a  8bc6                 mov eax, esi
// 0043b56c  5e                   pop esi
// 0043b56d  c20400               ret 4
// copied from an identical function in another client (function ?Cleanup@CXTPPropertyGridItemBool@ns_ROCX000005@@QAEPAXH@Z)

namespace ns_ROCX000005 {
// from server: 100% by atomic.potato
extern "C" void __cdecl free(void *p);

struct CXTPPropertyGridItemBool
{
    void Destructor();
    void* Cleanup(int bDelete);
};

void* CXTPPropertyGridItemBool::Cleanup(int bDelete)
{
    if (*(void **)((char *)this + 0x130))
    {
        free(*(void **)((char *)this + 0x130));
    }
    void *p = *(void **)((char *)this + 0x124);
    *(void **)((char *)this + 0x130) = 0;
    *(void **)((char *)this + 0x134) = 0;
    *(void **)((char *)this + 0x138) = 0;
    free(p);
    Destructor();

    if (bDelete & 1)
    {
        free(this);
    }

    return this;
}
}
