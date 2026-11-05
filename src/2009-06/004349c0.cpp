// from server: 100% by EspClaude
// roc 2009-06 004349c0  unit: _NVCXTPPropertyGridItemBool::?$XItem  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004349c0
//
// 004349c0  56                   push esi
// 004349c1  8bf1                 mov esi, ecx
// 004349c3  8b8630010000         mov eax, dword ptr [esi + 0x130]
// 004349c9  85c0                 test eax, eax
// 004349cb  7409                 je 0x4349d6
// 004349cd  50                   push eax
// 004349ce  e85f402e00           call 0x718a32
// 004349d3  83c404               add esp, 4
// 004349d6  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 004349dc  50                   push eax
// 004349dd  c7863001000000000000 mov dword ptr [esi + 0x130], 0
// 004349e7  c7863401000000000000 mov dword ptr [esi + 0x134], 0
// 004349f1  c7863801000000000000 mov dword ptr [esi + 0x138], 0
// 004349fb  e832402e00           call 0x718a32
// 00434a00  83c404               add esp, 4
// 00434a03  8bce                 mov ecx, esi
// 00434a05  e8a6b23500           call 0x78fcb0
// 00434a0a  f644240801           test byte ptr [esp + 8], 1
// 00434a0f  7409                 je 0x434a1a
// 00434a11  56                   push esi
// 00434a12  e81b402e00           call 0x718a32
// 00434a17  83c404               add esp, 4
// 00434a1a  8bc6                 mov eax, esi
// 00434a1c  5e                   pop esi
// 00434a1d  c20400               ret 4
// copied from an identical function in another client (function ?Cleanup@CXTPPropertyGridItemBool@ns_ROCX000004@@QAEPAXH@Z)

namespace ns_ROCX000004 {
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
