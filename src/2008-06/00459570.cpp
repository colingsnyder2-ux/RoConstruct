// from server: 100% by Espeon
// from server: 93% by colin
// from server: 92% by king_originala
// roc 2008-06 00459570  unit: CRobloxView  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00459570
//
// 00459570  6aff                 push -1
// 00459572  6809287c00           push 0x7c2809
// 00459577  64a100000000         mov eax, dword ptr fs:[0]
// 0045957d  50                   push eax
// 0045957e  64892500000000       mov dword ptr fs:[0], esp
// 00459585  83ec18               sub esp, 0x18
// 00459588  56                   push esi
// 00459589  8bf1                 mov esi, ecx
// 0045958b  8b8ed0000000         mov ecx, dword ptr [esi + 0xd0]
// 00459591  8d44240c             lea eax, [esp + 0xc]
// 00459595  50                   push eax
// 00459596  51                   push ecx
// 00459597  ff15842d8000         call dword ptr [0x802d84]
// 0045959d  6af4                 push -0xc
// 0045959f  6af4                 push -0xc
// 004595a1  8d542414             lea edx, [esp + 0x14]
// 004595a5  52                   push edx
// 004595a6  ff15282d8000         call dword ptr [0x802d28]
// 004595ac  8b442414             mov eax, dword ptr [esp + 0x14]
// 004595b0  2b44240c             sub eax, dword ptr [esp + 0xc]
// 004595b4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004595b8  99                   cdq 
// 004595b9  2bc2                 sub eax, edx
// 004595bb  d1f8                 sar eax, 1
// 004595bd  89442414             mov dword ptr [esp + 0x14], eax
// 004595c1  8b442418             mov eax, dword ptr [esp + 0x18]
// 004595c5  2bc1                 sub eax, ecx
// 004595c7  89442404             mov dword ptr [esp + 4], eax
// 004595cb  3de0010000           cmp eax, 0x1e0
// 004595d0  c7442408e0010000     mov dword ptr [esp + 8], 0x1e0
// 004595d8  8d442404             lea eax, [esp + 4]
// 004595dc  7c04                 jl 0x4595e2
// 004595de  8d442408             lea eax, [esp + 8]
// 004595e2  8b00                 mov eax, dword ptr [eax]
// 004595e4  2bc1                 sub eax, ecx
// 004595e6  8d4c2408             lea ecx, [esp + 8]
// 004595ea  6a00                 push 0
// 004595ec  51                   push ecx
// 004595ed  89442420             mov dword ptr [esp + 0x20], eax
// 004595f1  e8dacafaff           call 0x4060d0
// 004595f6  8bd4                 mov edx, esp
// 004595f8  8964240c             mov dword ptr [esp + 0xc], esp
// 004595fc  685c918100           push 0x81915c
// 00459601  50                   push eax
// 00459602  52                   push edx
// 00459603  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0045960b  e8504bfbff           call 0x40e160
// 00459610  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00459614  8b542424             mov edx, dword ptr [esp + 0x24]
// 00459618  83c40c               add esp, 0xc
// 0045961b  81c6b0000000         add esi, 0xb0
// 00459621  56                   push esi
// 00459622  83ec10               sub esp, 0x10
// 00459625  8bc4                 mov eax, esp
// 00459627  8908                 mov dword ptr [eax], ecx
// 00459629  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0045962d  895004               mov dword ptr [eax + 4], edx
// 00459630  8b542434             mov edx, dword ptr [esp + 0x34]
// 00459634  894808               mov dword ptr [eax + 8], ecx
// 00459637  89500c               mov dword ptr [eax + 0xc], edx
// 0045963a  e8115afbff           call 0x40f050
// 0045963f  83c41c               add esp, 0x1c
// 00459642  8d4c2408             lea ecx, [esp + 8]
// 00459646  ff15143f8000         call dword ptr [0x803f14]
// 0045964c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00459650  64890d00000000       mov dword ptr fs:[0], ecx
// 00459657  5e                   pop esi
// 00459658  83c424               add esp, 0x24
// 0045965b  c3                   ret 

struct Rect {
    int left, top, right, bottom;
};

extern "C" {
    extern int (__stdcall *GetClientRect)(void *, Rect *);
    extern int (__stdcall *InflateRect)(Rect *, int, int);
}



typedef void (__thiscall *StringDestructor)(void *);
extern StringDestructor destroyString;

struct String {
    void *data;

    String(const String &);
    __declspec(dllimport) ~String() throw();
};

extern String __cdecl getBaseUrl();

extern String __cdecl concatenate(const String &, const char *);
extern void __cdecl showHelp(Rect, void *, String, int);

inline const int &minimum(const int &a, const int &b)
{
    return a < b ? a : b;
}

struct S {
    char padding[0xb0];
    char browser[0x20];
    void *window;
    void f();
};

void S::f()
{
    Rect rect;
    GetClientRect(window, &rect);
    InflateRect(&rect, -12, -12);

    rect.right = (rect.right - rect.left) / 2;
    int height = rect.bottom - rect.top;
    int limit = 480;
    rect.bottom = minimum(height, limit) - rect.top;

    showHelp(rect, browser, concatenate(getBaseUrl(), "/Game/Help.aspx"), 0);
}
