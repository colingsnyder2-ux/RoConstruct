// from server: 100% by Yeetserama
// roc 2011-06 00491f20  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00491f20
//
// 00491f20  56                   push esi
// 00491f21  6a00                 push 0
// 00491f23  6a00                 push 0
// 00491f25  68007f0000           push 0x7f00
// 00491f2a  6a00                 push 0
// 00491f2c  8bf1                 mov esi, ecx
// 00491f2e  ff15081aa400         call dword ptr [0xa41a08]
// 00491f34  50                   push eax
// 00491f35  6a08                 push 8
// 00491f37  e8ee8a3700           call 0x80aa2a
// 00491f3c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00491f40  81492000000006       or dword ptr [ecx + 0x20], 0x6000000
// 00491f47  894128               mov dword ptr [ecx + 0x28], eax
// 00491f4a  51                   push ecx
// 00491f4b  8bce                 mov ecx, esi
// 00491f4d  e84c8c3700           call 0x80ab9e
// 00491f52  5e                   pop esi
// 00491f53  c20400               ret 4
// copied from an identical function in another client (function ?PreCreateWindow@S@ns_ROCX00001c@@QAEHPAUCreateInfo@2@@Z)

namespace ns_ROCX00001c {
// from server: 100% by king_originala
extern "C" void *(__stdcall *LoadCursorA)(void *, const char *);
extern const char *__stdcall RegisterWindowClass(
    unsigned int, void *, void *, void *);

struct CreateInfo {
    char reserved[0x20];
    unsigned int style;
    const char *name;
    const char *className;
};

struct S {
    int BasePreCreateWindow(CreateInfo *);
    int PreCreateWindow(CreateInfo *);
};

int S::PreCreateWindow(CreateInfo *info)
{
    const char *className = RegisterWindowClass(
        8, LoadCursorA(0, (const char *)0x7f00), 0, 0);
    info->style |= 0x06000000;
    info->className = className;
    return BasePreCreateWindow(info);
}
}
