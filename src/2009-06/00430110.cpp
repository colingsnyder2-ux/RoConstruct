// from server: 100% by EspClaude
// roc 2009-06 00430110  unit: COutputView  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00430110
//
// 00430110  6aff                 push -1
// 00430112  6848d38400           push 0x84d348
// 00430117  64a100000000         mov eax, dword ptr fs:[0]
// 0043011d  50                   push eax
// 0043011e  64892500000000       mov dword ptr fs:[0], esp
// 00430125  51                   push ecx
// 00430126  53                   push ebx
// 00430127  56                   push esi
// 00430128  57                   push edi
// 00430129  8bf9                 mov edi, ecx
// 0043012b  897c240c             mov dword ptr [esp + 0xc], edi
// 0043012f  e86c670300           call 0x4668a0
// 00430134  33db                 xor ebx, ebx
// 00430136  6a04                 push 4
// 00430138  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0043013c  c70794358b00         mov dword ptr [edi], 0x8b3594
// 00430142  8db7f8000000         lea esi, [edi + 0xf8]
// 00430148  e8eb882e00           call 0x718a38
// 0043014d  83c404               add esp, 4
// 00430150  3bc3                 cmp eax, ebx
// 00430152  7404                 je 0x430158
// 00430154  8930                 mov dword ptr [eax], esi
// 00430156  eb02                 jmp 0x43015a
// 00430158  33c0                 xor eax, eax
// 0043015a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043015e  8906                 mov dword ptr [esi], eax
// 00430160  895e10               mov dword ptr [esi + 0x10], ebx
// 00430163  895e14               mov dword ptr [esi + 0x14], ebx
// 00430166  895e18               mov dword ptr [esi + 0x18], ebx
// 00430169  895e1c               mov dword ptr [esi + 0x1c], ebx
// 0043016c  899f18010000         mov dword ptr [edi + 0x118], ebx
// 00430172  899f1c010000         mov dword ptr [edi + 0x11c], ebx
// 00430178  8bc7                 mov eax, edi
// 0043017a  5f                   pop edi
// 0043017b  5e                   pop esi
// 0043017c  5b                   pop ebx
// 0043017d  64890d00000000       mov dword ptr fs:[0], ecx
// 00430184  83c410               add esp, 0x10
// 00430187  c3                   ret 
// copied from an identical function in another client (function ??0COutputView@ns_ROCX000019@@QAE@XZ)

namespace ns_ROCX000019 {
struct VCSecureHtmlView {
    char pad[0xf0];
    char field_f4;

    VCSecureHtmlView();
    virtual ~VCSecureHtmlView();
};

struct COutputView : VCSecureHtmlView {
    struct Data {
        void** proxy;
        char pad[12];
        unsigned long field_10;
        unsigned long field_14;
        unsigned long field_18;
        unsigned long field_1c;

        Data();
    };

    Data data;
    unsigned long field_118;
    unsigned long field_11c;

    COutputView();
    virtual ~COutputView();
};

inline COutputView::Data::Data()
    : proxy(new void*(this)),
      field_10(0),
      field_14(0),
      field_18(0),
      field_1c(0)
{
}

COutputView::COutputView()
    : field_118(0), field_11c(0)
{
}
}
