// from server: 100% by EspClaude
// from server: 47% by colin
// roc 2007-08 0042a840  unit: CLuaHtmlView  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042a840
//
// 0042a840  6aff                 push -1
// 0042a842  6888cf7300           push 0x73cf88
// 0042a847  64a100000000         mov eax, dword ptr fs:[0]
// 0042a84d  50                   push eax
// 0042a84e  53                   push ebx
// 0042a84f  55                   push ebp
// 0042a850  56                   push esi
// 0042a851  57                   push edi
// 0042a852  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042a857  33c4                 xor eax, esp
// 0042a859  50                   push eax
// 0042a85a  8d442414             lea eax, [esp + 0x14]
// 0042a85e  64a300000000         mov dword ptr fs:[0], eax
// 0042a864  8bf1                 mov esi, ecx
// 0042a866  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0042a86a  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0042a86e  33db                 xor ebx, ebx
// 0042a870  3bfb                 cmp edi, ebx
// 0042a872  c70608a27800         mov dword ptr [esi], 0x78a208
// 0042a878  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0042a87c  895e04               mov dword ptr [esi + 4], ebx
// 0042a87f  895e08               mov dword ptr [esi + 8], ebx
// 0042a882  895e0c               mov dword ptr [esi + 0xc], ebx
// 0042a885  7414                 je 0x42a89b
// 0042a887  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0042a88b  53                   push ebx
// 0042a88c  55                   push ebp
// 0042a88d  89460c               mov dword ptr [esi + 0xc], eax
// 0042a890  897e04               mov dword ptr [esi + 4], edi
// 0042a893  ffd7                 call edi
// 0042a895  83c408               add esp, 8
// 0042a898  894608               mov dword ptr [esi + 8], eax
// 0042a89b  3bfb                 cmp edi, ebx
// 0042a89d  895e10               mov dword ptr [esi + 0x10], ebx
// 0042a8a0  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0042a8a8  7408                 je 0x42a8b2
// 0042a8aa  6a01                 push 1
// 0042a8ac  55                   push ebp
// 0042a8ad  ffd7                 call edi
// 0042a8af  83c408               add esp, 8
// 0042a8b2  8bc6                 mov eax, esi
// 0042a8b4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042a8b8  64890d00000000       mov dword ptr fs:[0], ecx
// 0042a8bf  59                   pop ecx
// 0042a8c0  5f                   pop edi
// 0042a8c1  5e                   pop esi
// 0042a8c2  5d                   pop ebp
// 0042a8c3  5b                   pop ebx
// 0042a8c4  83c40c               add esp, 0xc
// 0042a8c7  c20c00               ret 0xc

typedef void* (__cdecl *Fn)(void*, int);

struct Holder {
    Fn fn_;
    void* obj_;
    void* ctx_;
    Holder(Holder const& o) : fn_(0), obj_(0), ctx_(0)
    {
        if (o.fn_ != 0) {
            ctx_ = o.ctx_;
            fn_ = o.fn_;
            obj_ = o.fn_(o.obj_, 0);
        }
    }
    ~Holder()
    {
        if (fn_ != 0)
            fn_(obj_, 1);
    }
};

class CLuaHtmlView {
public:
    virtual ~CLuaHtmlView();
    Holder h;
    void* field_10;
    CLuaHtmlView(Holder h);
};

CLuaHtmlView::CLuaHtmlView(Holder h_)
    : h(h_), field_10(0)
{
}
