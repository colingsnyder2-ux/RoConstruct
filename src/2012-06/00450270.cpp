// from server: 100% by Xemicl
// roc 2012-06 00450270  unit: boost::gregorian::Vdate::?$date_facet  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00450270
//
// 00450270  6aff                 push -1
// 00450272  68584aaa00           push 0xaa4a58
// 00450277  64a100000000         mov eax, dword ptr fs:[0]
// 0045027d  50                   push eax
// 0045027e  64892500000000       mov dword ptr fs:[0], esp
// 00450285  51                   push ecx
// 00450286  53                   push ebx
// 00450287  56                   push esi
// 00450288  57                   push edi
// 00450289  8bf9                 mov edi, ecx
// 0045028b  897c240c             mov dword ptr [esp + 0xc], edi
// 0045028f  e8bc4d0500           call 0x4a5050
// 00450294  33db                 xor ebx, ebx
// 00450296  6a04                 push 4
// 00450298  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0045029c  c7078432b500         mov dword ptr [edi], 0xb53284
// 004502a2  8db7f8000000         lea esi, [edi + 0xf8]
// 004502a8  e86d1e5300           call 0x98211a
// 004502ad  83c404               add esp, 4
// 004502b0  3bc3                 cmp eax, ebx
// 004502b2  7404                 je 0x4502b8
// 004502b4  8930                 mov dword ptr [eax], esi
// 004502b6  eb02                 jmp 0x4502ba
// 004502b8  33c0                 xor eax, eax
// 004502ba  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004502be  8906                 mov dword ptr [esi], eax
// 004502c0  895e10               mov dword ptr [esi + 0x10], ebx
// 004502c3  895e14               mov dword ptr [esi + 0x14], ebx
// 004502c6  895e18               mov dword ptr [esi + 0x18], ebx
// 004502c9  895e1c               mov dword ptr [esi + 0x1c], ebx
// 004502cc  899f18010000         mov dword ptr [edi + 0x118], ebx
// 004502d2  899f1c010000         mov dword ptr [edi + 0x11c], ebx
// 004502d8  8bc7                 mov eax, edi
// 004502da  5f                   pop edi
// 004502db  5e                   pop esi
// 004502dc  5b                   pop ebx
// 004502dd  64890d00000000       mov dword ptr fs:[0], ecx
// 004502e4  83c410               add esp, 0x10
// 004502e7  c3                   ret 
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