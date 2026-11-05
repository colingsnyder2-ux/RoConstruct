// from server: 100% by Yeetserama
// roc 2010-06 004751d0  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004751d0
//
// 004751d0  56                   push esi
// 004751d1  6a00                 push 0
// 004751d3  6a00                 push 0
// 004751d5  68007f0000           push 0x7f00
// 004751da  6a00                 push 0
// 004751dc  8bf1                 mov esi, ecx
// 004751de  ff15ccbb9e00         call dword ptr [0x9ebbcc]
// 004751e4  50                   push eax
// 004751e5  6a08                 push 8
// 004751e7  e87a313300           call 0x7a8366
// 004751ec  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004751f0  81492000000006       or dword ptr [ecx + 0x20], 0x6000000
// 004751f7  894128               mov dword ptr [ecx + 0x28], eax
// 004751fa  51                   push ecx
// 004751fb  8bce                 mov ecx, esi
// 004751fd  e8d8323300           call 0x7a84da
// 00475202  5e                   pop esi
// 00475203  c20400               ret 4
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
