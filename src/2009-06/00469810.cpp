// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00467380  unit: CSettingsDialog  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00467380
//
// 00467380  83ec18               sub esp, 0x18
// 00467383  53                   push ebx
// 00467384  56                   push esi
// 00467385  8bf1                 mov esi, ecx
// 00467387  8b8e6c010000         mov ecx, dword ptr [esi + 0x16c]
// 0046738d  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00467390  57                   push edi
// 00467391  8d442414             lea eax, [esp + 0x14]
// 00467395  50                   push eax
// 00467396  52                   push edx
// 00467397  ff15842d8000         call dword ptr [0x802d84]
// 0046739d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004673a1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004673a5  8944240c             mov dword ptr [esp + 0xc], eax
// 004673a9  894c2410             mov dword ptr [esp + 0x10], ecx
// 004673ad  8bf8                 mov edi, eax
// 004673af  8bd9                 mov ebx, ecx
// 004673b1  8b8e6c010000         mov ecx, dword ptr [esi + 0x16c]
// 004673b7  8b5120               mov edx, dword ptr [ecx + 0x20]
// 004673ba  8d44240c             lea eax, [esp + 0xc]
// 004673be  50                   push eax
// 004673bf  52                   push edx
// 004673c0  ff15802d8000         call dword ptr [0x802d80]
// 004673c6  397c240c             cmp dword ptr [esp + 0xc], edi
// 004673ca  750f                 jne 0x4673db
// 004673cc  395c2410             cmp dword ptr [esp + 0x10], ebx
// 004673d0  7509                 jne 0x4673db
// 004673d2  5f                   pop edi
// 004673d3  5e                   pop esi
// 004673d4  b001                 mov al, 1
// 004673d6  5b                   pop ebx
// 004673d7  83c418               add esp, 0x18
// 004673da  c3                   ret 
// 004673db  5f                   pop edi
// 004673dc  5e                   pop esi
// 004673dd  32c0                 xor al, al
// 004673df  5b                   pop ebx
// 004673e0  83c418               add esp, 0x18
// 004673e3  c3                   ret 

struct POINT {
    long x, y;
};

struct RECT {
    long left, top, right, bottom;
};

extern "C" {
    extern int (__stdcall *GetClientRect)(void*, RECT*);
    extern int (__stdcall *ClientToScreen)(void*, POINT*);
}

struct Window {
    char padding[0x20];
    void* handle;
};

struct CSettingsDialog {
    char padding[0x16c];
    Window* window;
    bool f();
};

bool CSettingsDialog::f()
{
    RECT rect;
    GetClientRect(window->handle, &rect);

    POINT point;
    point.x = rect.left;
    point.y = rect.top;

    long x = point.x;
    long y = point.y;
    ClientToScreen(window->handle, &point);

    if (point.x != x || point.y != y)
        return false;
    return true;
}
