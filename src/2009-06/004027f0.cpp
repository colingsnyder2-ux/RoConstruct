// from server: 100% by EspClaude
// roc 2009-06 004027f0  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004027f0
//
// 004027f0  83ec10               sub esp, 0x10
// 004027f3  56                   push esi
// 004027f4  8bf1                 mov esi, ecx
// 004027f6  8d442404             lea eax, [esp + 4]
// 004027fa  50                   push eax
// 004027fb  8d4c240c             lea ecx, [esp + 0xc]
// 004027ff  51                   push ecx
// 00402800  b9f096a300           mov ecx, 0xa396f0
// 00402805  c7062cca8a00         mov dword ptr [esi], 0x8aca2c
// 0040280b  8974240c             mov dword ptr [esp + 0xc], esi
// 0040280f  e81c490e00           call 0x4e7130
// 00402814  8bc6                 mov eax, esi
// 00402816  5e                   pop esi
// 00402817  83c410               add esp, 0x10
// 0040281a  c3                   ret 
// copied from an identical function in another client (function ?initialize@S@ns_ROCX000024@@QAEPAU12@XZ)

namespace ns_ROCX000024 {
struct S;

struct InsertResult {
    unsigned long data[3];
};

struct Registry {
    void insert(InsertResult* result, S** value);
};

extern Registry registry;
extern unsigned long table[];

struct S {
    unsigned long* tablePointer;
    S* initialize();
};

S* S::initialize()
{
    InsertResult result;
    S* value;
    tablePointer = table;
    value = this;
    registry.insert(&result, &value);
    return this;
}
}
