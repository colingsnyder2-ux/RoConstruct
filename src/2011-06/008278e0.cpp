// from server: 100% by Yeetserama
// roc 2011-06 008278e0  unit: CXTPCommandBar  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008278e0
//
// 008278e0  51                   push ecx
// 008278e1  55                   push ebp
// 008278e2  8be9                 mov ebp, ecx
// 008278e4  8b8dfc000000         mov ecx, dword ptr [ebp + 0xfc]
// 008278ea  57                   push edi
// 008278eb  0fb77c2410           movzx edi, word ptr [esp + 0x10]
// 008278f0  e8cbf30200           call 0x856cc0
// 008278f5  85ff                 test edi, edi
// 008278f7  7508                 jne 0x827901
// 008278f9  5f                   pop edi
// 008278fa  33c0                 xor eax, eax
// 008278fc  5d                   pop ebp
// 008278fd  59                   pop ecx
// 008278fe  c20800               ret 8
// 00827901  56                   push esi
// 00827902  68f1000000           push 0xf1
// 00827907  57                   push edi
// 00827908  e8cf30feff           call 0x80a9dc
// 0082790d  8bf0                 mov esi, eax
// 0082790f  85f6                 test esi, esi
// 00827911  742e                 je 0x827941
// 00827913  68f1000000           push 0xf1
// 00827918  57                   push edi
// 00827919  56                   push esi
// 0082791a  ff153803a400         call dword ptr [0xa40338]
// 00827920  85c0                 test eax, eax
// 00827922  741d                 je 0x827941
// 00827924  50                   push eax
// 00827925  56                   push esi
// 00827926  ff153c03a400         call dword ptr [0xa4033c]
// 0082792c  8944240c             mov dword ptr [esp + 0xc], eax
// 00827930  85c0                 test eax, eax
// 00827932  740d                 je 0x827941
// 00827934  50                   push eax
// 00827935  ff15d001a400         call dword ptr [0xa401d0]
// 0082793b  8bf0                 mov esi, eax
// 0082793d  85f6                 test esi, esi
// 0082793f  7509                 jne 0x82794a
// 00827941  5e                   pop esi
// 00827942  5f                   pop edi
// 00827943  33c0                 xor eax, eax
// 00827945  5d                   pop ebp
// 00827946  59                   pop ecx
// 00827947  c20800               ret 8
// 0082794a  0fb74606             movzx eax, word ptr [esi + 6]
// 0082794e  33c9                 xor ecx, ecx
// 00827950  ba04000000           mov edx, 4
// 00827955  f7e2                 mul edx
// 00827957  0f90c1               seto cl
// 0082795a  f7d9                 neg ecx
// 0082795c  0bc8                 or ecx, eax
// 0082795e  51                   push ecx
// 0082795f  e8dc29feff           call 0x80a340
// 00827964  8bf8                 mov edi, eax
// 00827966  33c0                 xor eax, eax
// 00827968  83c404               add esp, 4
// 0082796b  33c9                 xor ecx, ecx
// 0082796d  663b4606             cmp ax, word ptr [esi + 6]
// 00827971  731d                 jae 0x827990
// 00827973  8bc6                 mov eax, esi
// 00827975  e8d6f7ffff           call 0x827150
// 0082797a  8d9b00000000         lea ebx, [ebx]
// 00827980  0fb71448             movzx edx, word ptr [eax + ecx*2]
// 00827984  89148f               mov dword ptr [edi + ecx*4], edx
// 00827987  0fb75606             movzx edx, word ptr [esi + 6]
// 0082798b  41                   inc ecx
// 0082798c  3bca                 cmp ecx, edx
// 0082798e  7cf0                 jl 0x827980
// 00827990  0fb74606             movzx eax, word ptr [esi + 6]
// 00827994  53                   push ebx
// 00827995  50                   push eax
// 00827996  57                   push edi
// 00827997  8bcd                 mov ecx, ebp
// 00827999  e842fdffff           call 0x8276e0
// 0082799e  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 008279a3  8bd8                 mov ebx, eax
// 008279a5  7448                 je 0x8279ef
// 008279a7  8bcd                 mov ecx, ebp
// 008279a9  e82232ffff           call 0x81abd0
// 008279ae  0fb75604             movzx edx, word ptr [esi + 4]
// 008279b2  0fb74e02             movzx ecx, word ptr [esi + 2]
// 008279b6  6a00                 push 0
// 008279b8  52                   push edx
// 008279b9  8b542420             mov edx, dword ptr [esp + 0x20]
// 008279bd  51                   push ecx
// 008279be  0fb74e06             movzx ecx, word ptr [esi + 6]
// 008279c2  51                   push ecx
// 008279c3  57                   push edi
// 008279c4  52                   push edx
// 008279c5  8bc8                 mov ecx, eax
// 008279c7  e8c4e6ffff           call 0x826090
// 008279cc  85c0                 test eax, eax
// 008279ce  7502                 jne 0x8279d2
// 008279d0  33db                 xor ebx, ebx
// 008279d2  0fb74602             movzx eax, word ptr [esi + 2]
// 008279d6  6683f810             cmp ax, 0x10
// 008279da  7413                 je 0x8279ef
// 008279dc  0fb74e04             movzx ecx, word ptr [esi + 4]
// 008279e0  0fb7c0               movzx eax, ax
// 008279e3  89850c010000         mov dword ptr [ebp + 0x10c], eax
// 008279e9  898d10010000         mov dword ptr [ebp + 0x110], ecx
// 008279ef  57                   push edi
// 008279f0  e80f29feff           call 0x80a304
// 008279f5  8b442414             mov eax, dword ptr [esp + 0x14]
// 008279f9  83c404               add esp, 4
// 008279fc  50                   push eax
// 008279fd  ff15cc01a400         call dword ptr [0xa401cc]
// 00827a03  8bc3                 mov eax, ebx
// 00827a05  5b                   pop ebx
// 00827a06  5e                   pop esi
// 00827a07  5f                   pop edi
// 00827a08  5d                   pop ebp
// 00827a09  59                   pop ecx
// 00827a0a  c20800               ret 8
// copied from an identical function in another client (function ?LoadToolbar@CommandBar@@QAEHIH@Z)

// from server: 100% by king_originala
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