// from server: 100% by EspClaude
// roc 2009-06 0045aca0  unit: CRobloxWnd  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0045aca0
//
// 0045aca0  56                   push esi
// 0045aca1  6a00                 push 0
// 0045aca3  6a00                 push 0
// 0045aca5  68007f0000           push 0x7f00
// 0045acaa  6a00                 push 0
// 0045acac  8bf1                 mov esi, ecx
// 0045acae  ff15b0ed8900         call dword ptr [0x89edb0]
// 0045acb4  50                   push eax
// 0045acb5  6a2b                 push 0x2b
// 0045acb7  e842e72b00           call 0x7193fe
// 0045acbc  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0045acc0  81492000000006       or dword ptr [ecx + 0x20], 0x6000000
// 0045acc7  894128               mov dword ptr [ecx + 0x28], eax
// 0045acca  83791464             cmp dword ptr [ecx + 0x14], 0x64
// 0045acce  8d4114               lea eax, [ecx + 0x14]
// 0045acd1  c744240864000000     mov dword ptr [esp + 8], 0x64
// 0045acd9  8d542408             lea edx, [esp + 8]
// 0045acdd  7c02                 jl 0x45ace1
// 0045acdf  8bd0                 mov edx, eax
// 0045ace1  8b12                 mov edx, dword ptr [edx]
// 0045ace3  8910                 mov dword ptr [eax], edx
// 0045ace5  83791064             cmp dword ptr [ecx + 0x10], 0x64
// 0045ace9  8d4110               lea eax, [ecx + 0x10]
// 0045acec  c744240864000000     mov dword ptr [esp + 8], 0x64
// 0045acf4  8d542408             lea edx, [esp + 8]
// 0045acf8  7c02                 jl 0x45acfc
// 0045acfa  8bd0                 mov edx, eax
// 0045acfc  8b12                 mov edx, dword ptr [edx]
// 0045acfe  51                   push ecx
// 0045acff  8bce                 mov ecx, esi
// 0045ad01  8910                 mov dword ptr [eax], edx
// 0045ad03  e8b4dd2b00           call 0x718abc
// 0045ad08  5e                   pop esi
// 0045ad09  c20400               ret 4
// copied from an identical function in another client (function ?PreCreateWindow@CRobloxWnd@ns_ROCX000035@@QAEHPAUCreateStruct@2@@Z)

namespace ns_ROCX000035 {
extern "C" void* (__stdcall *LoadCursorA)(void*, const char*);
extern const char* __stdcall RegisterWindowClass(unsigned int, void*, void*, void*);

struct CreateStruct {
    void* createParams;
    void* instance;
    void* menu;
    void* parent;
    int cy;
    int cx;
    int y;
    int x;
    long style;
    const char* name;
    const char* className;
    unsigned long extendedStyle;
};

template<class T>
inline const T& maximum(const T& a, const T& b)
{
    return a < b ? b : a;
}

struct WindowBase {
    int PreCreateWindow(CreateStruct*);
};

struct CRobloxWnd : WindowBase {
    int PreCreateWindow(CreateStruct*);
};

int CRobloxWnd::PreCreateWindow(CreateStruct* cs)
{
    cs->className = RegisterWindowClass(
        0x2b, LoadCursorA(0, (const char*)0x7f00), 0, 0);
    cs->style |= 0x06000000;
    cs->cx = maximum(cs->cx, 100);
    cs->cy = maximum(cs->cy, 100);
    return WindowBase::PreCreateWindow(cs);
}
}
