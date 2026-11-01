// from server: 100% by EspClaude
// roc 2009-06 006b7ec0  unit: RBX::NullTool  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b7ec0
//
// 006b7ec0  56                   push esi
// 006b7ec1  8bf1                 mov esi, ecx
// 006b7ec3  c7066cad8e00         mov dword ptr [esi], 0x8ead6c
// 006b7ec9  c7460454ad8e00       mov dword ptr [esi + 4], 0x8ead54
// 006b7ed0  e8abdcffff           call 0x6b5b80
// 006b7ed5  f644240801           test byte ptr [esp + 8], 1
// 006b7eda  7409                 je 0x6b7ee5
// 006b7edc  56                   push esi
// 006b7edd  e8500b0600           call 0x718a32
// 006b7ee2  83c404               add esp, 4
// 006b7ee5  8bc6                 mov eax, esi
// 006b7ee7  5e                   pop esi
// 006b7ee8  c20400               ret 4
// copied from an identical function in another client (function ??_GTool@ns_ROCX000002@@UAEPAXI@Z)

namespace ns_ROCX000002 {
struct First {
    virtual ~First();
};

struct Second {
    virtual ~Second();
};

struct Base : First, Second {
    ~Base();
};

struct Tool : Base {
    ~Tool();
};

Tool::~Tool()
{
}
}
