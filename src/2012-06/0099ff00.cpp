// from server: 100% by Xemicl
// roc 2012-06 0099ff00  unit: CXTPCommandBar  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0099ff00
//
// 0099ff00  51                   push ecx
// 0099ff01  55                   push ebp
// 0099ff02  8be9                 mov ebp, ecx
// 0099ff04  8b8dfc000000         mov ecx, dword ptr [ebp + 0xfc]
// 0099ff0a  57                   push edi
// 0099ff0b  0fb77c2410           movzx edi, word ptr [esp + 0x10]
// 0099ff10  e87bf20200           call 0x9cf190
// 0099ff15  85ff                 test edi, edi
// 0099ff17  7508                 jne 0x99ff21
// 0099ff19  5f                   pop edi
// 0099ff1a  33c0                 xor eax, eax
// 0099ff1c  5d                   pop ebp
// 0099ff1d  59                   pop ecx
// 0099ff1e  c20800               ret 8
// 0099ff21  56                   push esi
// 0099ff22  68f1000000           push 0xf1
// 0099ff27  57                   push edi
// 0099ff28  e82f2bfeff           call 0x982a5c
// 0099ff2d  8bf0                 mov esi, eax
// 0099ff2f  85f6                 test esi, esi
// 0099ff31  742e                 je 0x99ff61
// 0099ff33  68f1000000           push 0xf1
// 0099ff38  57                   push edi
// 0099ff39  56                   push esi
// 0099ff3a  ff154022b200         call dword ptr [0xb22240]
// 0099ff40  85c0                 test eax, eax
// 0099ff42  741d                 je 0x99ff61
// 0099ff44  50                   push eax
// 0099ff45  56                   push esi
// 0099ff46  ff158421b200         call dword ptr [0xb22184]
// 0099ff4c  8944240c             mov dword ptr [esp + 0xc], eax
// 0099ff50  85c0                 test eax, eax
// 0099ff52  740d                 je 0x99ff61
// 0099ff54  50                   push eax
// 0099ff55  ff15d422b200         call dword ptr [0xb222d4]
// 0099ff5b  8bf0                 mov esi, eax
// 0099ff5d  85f6                 test esi, esi
// 0099ff5f  7509                 jne 0x99ff6a
// 0099ff61  5e                   pop esi
// 0099ff62  5f                   pop edi
// 0099ff63  33c0                 xor eax, eax
// 0099ff65  5d                   pop ebp
// 0099ff66  59                   pop ecx
// 0099ff67  c20800               ret 8
// 0099ff6a  0fb74606             movzx eax, word ptr [esi + 6]
// 0099ff6e  33c9                 xor ecx, ecx
// 0099ff70  ba04000000           mov edx, 4
// 0099ff75  f7e2                 mul edx
// 0099ff77  0f90c1               seto cl
// 0099ff7a  f7d9                 neg ecx
// 0099ff7c  0bc8                 or ecx, eax
// 0099ff7e  51                   push ecx
// 0099ff7f  e86c24feff           call 0x9823f0
// 0099ff84  8bf8                 mov edi, eax
// 0099ff86  33c0                 xor eax, eax
// 0099ff88  83c404               add esp, 4
// 0099ff8b  33c9                 xor ecx, ecx
// 0099ff8d  663b4606             cmp ax, word ptr [esi + 6]
// 0099ff91  731d                 jae 0x99ffb0
// 0099ff93  8bc6                 mov eax, esi
// 0099ff95  e8d6f7ffff           call 0x99f770
// 0099ff9a  8d9b00000000         lea ebx, [ebx]
// 0099ffa0  0fb71448             movzx edx, word ptr [eax + ecx*2]
// 0099ffa4  89148f               mov dword ptr [edi + ecx*4], edx
// 0099ffa7  0fb75606             movzx edx, word ptr [esi + 6]
// 0099ffab  41                   inc ecx
// 0099ffac  3bca                 cmp ecx, edx
// 0099ffae  7cf0                 jl 0x99ffa0
// 0099ffb0  0fb74606             movzx eax, word ptr [esi + 6]
// 0099ffb4  53                   push ebx
// 0099ffb5  50                   push eax
// 0099ffb6  57                   push edi
// 0099ffb7  8bcd                 mov ecx, ebp
// 0099ffb9  e842fdffff           call 0x99fd00
// 0099ffbe  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 0099ffc3  8bd8                 mov ebx, eax
// 0099ffc5  7448                 je 0x9a000f
// 0099ffc7  8bcd                 mov ecx, ebp
// 0099ffc9  e8622effff           call 0x992e30
// 0099ffce  0fb75604             movzx edx, word ptr [esi + 4]
// 0099ffd2  0fb74e02             movzx ecx, word ptr [esi + 2]
// 0099ffd6  6a00                 push 0
// 0099ffd8  52                   push edx
// 0099ffd9  8b542420             mov edx, dword ptr [esp + 0x20]
// 0099ffdd  51                   push ecx
// 0099ffde  0fb74e06             movzx ecx, word ptr [esi + 6]
// 0099ffe2  51                   push ecx
// 0099ffe3  57                   push edi
// 0099ffe4  52                   push edx
// 0099ffe5  8bc8                 mov ecx, eax
// 0099ffe7  e8d4e6ffff           call 0x99e6c0
// 0099ffec  85c0                 test eax, eax
// 0099ffee  7502                 jne 0x99fff2
// 0099fff0  33db                 xor ebx, ebx
// 0099fff2  0fb74602             movzx eax, word ptr [esi + 2]
// 0099fff6  6683f810             cmp ax, 0x10
// 0099fffa  7413                 je 0x9a000f
// 0099fffc  0fb74e04             movzx ecx, word ptr [esi + 4]
// 009a0000  0fb7c0               movzx eax, ax
// 009a0003  89850c010000         mov dword ptr [ebp + 0x10c], eax
// 009a0009  898d10010000         mov dword ptr [ebp + 0x110], ecx
// 009a000f  57                   push edi
// 009a0010  e8a523feff           call 0x9823ba
// 009a0015  8b442414             mov eax, dword ptr [esp + 0x14]
// 009a0019  83c404               add esp, 4
// 009a001c  50                   push eax
// 009a001d  ff15d022b200         call dword ptr [0xb222d0]
// 009a0023  8bc3                 mov eax, ebx
// 009a0025  5b                   pop ebx
// 009a0026  5e                   pop esi
// 009a0027  5f                   pop edi
// 009a0028  5d                   pop ebp
// 009a0029  59                   pop ecx
// 009a002a  c20800               ret 8
// copied from an identical function in another client (function ?LoadToolbar@CommandBar@@QAEHIH@Z)

// from server: 100% by king_originala
// roc 2008-06 006c26f0  unit: CXTPCommandBar  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006c26f0
//
// 006c26f0  51                   push ecx
// 006c26f1  55                   push ebp
// 006c26f2  8be9                 mov ebp, ecx
// 006c26f4  8b8dfc000000         mov ecx, dword ptr [ebp + 0xfc]
// 006c26fa  57                   push edi
// 006c26fb  0fb77c2410           movzx edi, word ptr [esp + 0x10]
// 006c2700  e8bbf40200           call 0x6f1bc0
// 006c2705  85ff                 test edi, edi
// 006c2707  7508                 jne 0x6c2711
// 006c2709  5f                   pop edi
// 006c270a  33c0                 xor eax, eax
// 006c270c  5d                   pop ebp
// 006c270d  59                   pop ecx
// 006c270e  c20800               ret 8
// 006c2711  56                   push esi
// 006c2712  68f1000000           push 0xf1
// 006c2717  57                   push edi
// 006c2718  e80fe8fdff           call 0x6a0f2c
// 006c271d  8bf0                 mov esi, eax
// 006c271f  85f6                 test esi, esi
// 006c2721  742e                 je 0x6c2751
// 006c2723  68f1000000           push 0xf1
// 006c2728  57                   push edi
// 006c2729  56                   push esi
// 006c272a  ff1590218000         call dword ptr [0x802190]
// 006c2730  85c0                 test eax, eax
// 006c2732  741d                 je 0x6c2751
// 006c2734  50                   push eax
// 006c2735  56                   push esi
// 006c2736  ff15a8218000         call dword ptr [0x8021a8]
// 006c273c  8944240c             mov dword ptr [esp + 0xc], eax
// 006c2740  85c0                 test eax, eax
// 006c2742  740d                 je 0x6c2751
// 006c2744  50                   push eax
// 006c2745  ff1510228000         call dword ptr [0x802210]
// 006c274b  8bf0                 mov esi, eax
// 006c274d  85f6                 test esi, esi
// 006c274f  7509                 jne 0x6c275a
// 006c2751  5e                   pop esi
// 006c2752  5f                   pop edi
// 006c2753  33c0                 xor eax, eax
// 006c2755  5d                   pop ebp
// 006c2756  59                   pop ecx
// 006c2757  c20800               ret 8
// 006c275a  0fb74606             movzx eax, word ptr [esi + 6]
// 006c275e  33c9                 xor ecx, ecx
// 006c2760  ba04000000           mov edx, 4
// 006c2765  f7e2                 mul edx
// 006c2767  0f90c1               seto cl
// 006c276a  f7d9                 neg ecx
// 006c276c  0bc8                 or ecx, eax
// 006c276e  51                   push ecx
// 006c276f  e8e2e1fdff           call 0x6a0956
// 006c2774  8bf8                 mov edi, eax
// 006c2776  33c0                 xor eax, eax
// 006c2778  83c404               add esp, 4
// 006c277b  33c9                 xor ecx, ecx
// 006c277d  663b4606             cmp ax, word ptr [esi + 6]
// 006c2781  731d                 jae 0x6c27a0
// 006c2783  8bc6                 mov eax, esi
// 006c2785  e8f673ffff           call 0x6b9b80
// 006c278a  8d9b00000000         lea ebx, [ebx]
// 006c2790  0fb71448             movzx edx, word ptr [eax + ecx*2]
// 006c2794  89148f               mov dword ptr [edi + ecx*4], edx
// 006c2797  0fb75606             movzx edx, word ptr [esi + 6]
// 006c279b  41                   inc ecx
// 006c279c  3bca                 cmp ecx, edx
// 006c279e  7cf0                 jl 0x6c2790
// 006c27a0  0fb74606             movzx eax, word ptr [esi + 6]
// 006c27a4  53                   push ebx
// 006c27a5  50                   push eax
// 006c27a6  57                   push edi
// 006c27a7  8bcd                 mov ecx, ebp
// 006c27a9  e842fdffff           call 0x6c24f0
// 006c27ae  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 006c27b3  8bd8                 mov ebx, eax
// 006c27b5  7448                 je 0x6c27ff
// 006c27b7  8bcd                 mov ecx, ebp
// 006c27b9  e89227ffff           call 0x6b4f50
// 006c27be  0fb75604             movzx edx, word ptr [esi + 4]
// 006c27c2  0fb74e02             movzx ecx, word ptr [esi + 2]
// 006c27c6  6a00                 push 0
// 006c27c8  52                   push edx
// 006c27c9  8b542420             mov edx, dword ptr [esp + 0x20]
// 006c27cd  51                   push ecx
// 006c27ce  0fb74e06             movzx ecx, word ptr [esi + 6]
// 006c27d2  51                   push ecx
// 006c27d3  57                   push edi
// 006c27d4  52                   push edx
// 006c27d5  8bc8                 mov ecx, eax
// 006c27d7  e8f4e3ffff           call 0x6c0bd0
// 006c27dc  85c0                 test eax, eax
// 006c27de  7502                 jne 0x6c27e2
// 006c27e0  33db                 xor ebx, ebx
// 006c27e2  0fb74602             movzx eax, word ptr [esi + 2]
// 006c27e6  6683f810             cmp ax, 0x10
// 006c27ea  7413                 je 0x6c27ff
// 006c27ec  0fb74e04             movzx ecx, word ptr [esi + 4]
// 006c27f0  0fb7c0               movzx eax, ax
// 006c27f3  89850c010000         mov dword ptr [ebp + 0x10c], eax
// 006c27f9  898d10010000         mov dword ptr [ebp + 0x110], ecx
// 006c27ff  57                   push edi
// 006c2800  e845e1fdff           call 0x6a094a
// 006c2805  8b442414             mov eax, dword ptr [esp + 0x14]
// 006c2809  83c404               add esp, 4
// 006c280c  50                   push eax
// 006c280d  ff150c228000         call dword ptr [0x80220c]
// 006c2813  8bc3                 mov eax, ebx
// 006c2815  5b                   pop ebx
// 006c2816  5e                   pop esi
// 006c2817  5f                   pop edi
// 006c2818  5d                   pop ebp
// 006c2819  59                   pop ecx
// 006c281a  c20800               ret 8

typedef unsigned short WORD;
typedef unsigned int UINT;

extern "C" {
extern void* (__stdcall *FindResourceA)(void*, const char*, const char*);
extern void* (__stdcall *LoadResource)(void*, void*);
extern void* (__stdcall *LockResource)(void*);
extern int (__stdcall *FreeResource)(void*);
}

extern void* __stdcall FindResourceModule(const char*, const char*);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete[](void*);

struct Controls
{
    void Clear();
};

struct ToolbarResource
{
    WORD version;
    WORD width;
    WORD height;
    WORD count;
};

static __declspec(noinline) WORD* Items(ToolbarResource* data)
{
    return (WORD*)(data + 1);
}

struct Size
{
    int cx;
    int cy;
    Size(int, int);
};

inline Size::Size(int x, int y)
{
    cx = x;
    cy = y;
}

struct Images
{
    int Load(UINT, UINT*, int, Size, int);
};

struct CommandBar
{
    char padding0[0xfc];
    Controls* controls;
    char padding1[0x0c];
    Size dimensions;

    int SetButtons(UINT*, int);
    Images* GetImages();
    int LoadToolbar(UINT, int);
};

int CommandBar::LoadToolbar(UINT id, int loadImages)
{
    UINT resourceId = (WORD)id;
    controls->Clear();

    if (!resourceId)
        return 0;

    void* module = FindResourceModule((const char*)resourceId,
                                     (const char*)241);
    if (!module)
        return 0;

    void* resource = FindResourceA(module, (const char*)resourceId,
                                  (const char*)241);
    if (!resource)
        return 0;

    void* handle = LoadResource(module, resource);
    if (!handle)
        return 0;

    ToolbarResource* data = (ToolbarResource*)LockResource(handle);
    if (!data)
        return 0;

    UINT* buttons = new UINT[data->count];
    int i = 0;
    if ((WORD)i < data->count)
    {
        WORD* items = Items(data);
        do
        {
            buttons[i] = items[i];
            ++i;
        } while (i < data->count);
    }

    int result = SetButtons(buttons, data->count);

    if (loadImages)
    {
        Images* images = GetImages();
        if (!images->Load(id, buttons, data->count,
                          Size(data->width, data->height), 0))
            result = 0;

        if (data->width != 16)
            dimensions = Size(data->width, data->height);
    }

    delete[] buttons;
    FreeResource(handle);
    return result;
}