// from server: 100% by EspClaude
// roc 2009-06 00466990  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00466990
//
// 00466990  56                   push esi
// 00466991  6a00                 push 0
// 00466993  6a00                 push 0
// 00466995  68007f0000           push 0x7f00
// 0046699a  6a00                 push 0
// 0046699c  8bf1                 mov esi, ecx
// 0046699e  ff15b0ed8900         call dword ptr [0x89edb0]
// 004669a4  50                   push eax
// 004669a5  6a08                 push 8
// 004669a7  e8522a2b00           call 0x7193fe
// 004669ac  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004669b0  81492000000006       or dword ptr [ecx + 0x20], 0x6000000
// 004669b7  894128               mov dword ptr [ecx + 0x28], eax
// 004669ba  51                   push ecx
// 004669bb  8bce                 mov ecx, esi
// 004669bd  e8aa2b2b00           call 0x71956c
// 004669c2  5e                   pop esi
// 004669c3  c20400               ret 4
// copied from an identical function in another client (function ?PreCreateWindow@S@ns_ROCX000006@@QAEHPAUCreateInfo@2@@Z)

namespace ns_ROCX000006 {
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
