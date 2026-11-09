// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2008-06 004339d0  unit: CObjectBrowser  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004339d0
//
// 004339d0  83ec14               sub esp, 0x14
// 004339d3  57                   push edi
// 004339d4  8bf9                 mov edi, ecx
// 004339d6  e88dd22600           call 0x6a0c68
// 004339db  837c241c01           cmp dword ptr [esp + 0x1c], 1
// 004339e0  0f84b7000000         je 0x433a9d
// 004339e6  8b4778               mov eax, dword ptr [edi + 0x78]
// 004339e9  85c0                 test eax, eax
// 004339eb  0f84ac000000         je 0x433a9d
// 004339f1  53                   push ebx
// 004339f2  56                   push esi
// 004339f3  8d4c2410             lea ecx, [esp + 0x10]
// 004339f7  51                   push ecx
// 004339f8  50                   push eax
// 004339f9  ff15842d8000         call dword ptr [0x802d84]
// 004339ff  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00433a03  8b542428             mov edx, dword ptr [esp + 0x28]
// 00433a07  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00433a0b  2b442414             sub eax, dword ptr [esp + 0x14]
// 00433a0f  6a01                 push 1
// 00433a11  53                   push ebx
// 00433a12  52                   push edx
// 00433a13  6a00                 push 0
// 00433a15  8bf3                 mov esi, ebx
// 00433a17  6a00                 push 0
// 00433a19  8d4f58               lea ecx, [edi + 0x58]
// 00433a1c  2bf0                 sub esi, eax
// 00433a1e  e829d02600           call 0x6a0a4c
// 00433a23  83bf9001000000       cmp dword ptr [edi + 0x190], 0
// 00433a2a  746f                 je 0x433a9b
// 00433a2c  8d44240c             lea eax, [esp + 0xc]
// 00433a30  50                   push eax
// 00433a31  8d4c2430             lea ecx, [esp + 0x30]
// 00433a35  51                   push ecx
// 00433a36  81c770010000         add edi, 0x170
// 00433a3c  6a00                 push 0
// 00433a3e  8bcf                 mov ecx, edi
// 00433a40  e8a3d62600           call 0x6a10e8
// 00433a45  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00433a49  8d0416               lea eax, [esi + edx]
// 00433a4c  8d8b6affffff         lea ecx, [ebx - 0x96]
// 00433a52  89442424             mov dword ptr [esp + 0x24], eax
// 00433a56  3bc1                 cmp eax, ecx
// 00433a58  894c2428             mov dword ptr [esp + 0x28], ecx
// 00433a5c  8d442424             lea eax, [esp + 0x24]
// 00433a60  7c04                 jl 0x433a66
// 00433a62  8d442428             lea eax, [esp + 0x28]
// 00433a66  8b00                 mov eax, dword ptr [eax]
// 00433a68  89442424             mov dword ptr [esp + 0x24], eax
// 00433a6c  83f832               cmp eax, 0x32
// 00433a6f  c744242832000000     mov dword ptr [esp + 0x28], 0x32
// 00433a77  8d442424             lea eax, [esp + 0x24]
// 00433a7b  7f04                 jg 0x433a81
// 00433a7d  8d442428             lea eax, [esp + 0x28]
// 00433a81  8b00                 mov eax, dword ptr [eax]
// 00433a83  6a00                 push 0
// 00433a85  50                   push eax
// 00433a86  6a00                 push 0
// 00433a88  8bcf                 mov ecx, edi
// 00433a8a  e8b7d52600           call 0x6a1046
// 00433a8f  8b07                 mov eax, dword ptr [edi]
// 00433a91  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 00433a97  8bcf                 mov ecx, edi
// 00433a99  ffd2                 call edx
// 00433a9b  5e                   pop esi
// 00433a9c  5b                   pop ebx
// 00433a9d  5f                   pop edi
// 00433a9e  83c414               add esp, 0x14
// 00433aa1  c20c00               ret 0xc

// from server: 95% by king_originala
// roc 2008-06 004339d0  unit: CObjectBrowser  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004339d0
//
// 004339d0  83ec14               sub esp, 0x14
// 004339d3  57                   push edi
// 004339d4  8bf9                 mov edi, ecx
// 004339d6  e88dd22600           call 0x6a0c68
// 004339db  837c241c01           cmp dword ptr [esp + 0x1c], 1
// 004339e0  0f84b7000000         je 0x433a9d
// 004339e6  8b4778               mov eax, dword ptr [edi + 0x78]
// 004339e9  85c0                 test eax, eax
// 004339eb  0f84ac000000         je 0x433a9d
// 004339f1  53                   push ebx
// 004339f2  56                   push esi
// 004339f3  8d4c2410             lea ecx, [esp + 0x10]
// 004339f7  51                   push ecx
// 004339f8  50                   push eax
// 004339f9  ff15842d8000         call dword ptr [0x802d84]
// 004339ff  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00433a03  8b542428             mov edx, dword ptr [esp + 0x28]
// 00433a07  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00433a0b  2b442414             sub eax, dword ptr [esp + 0x14]
// 00433a0f  6a01                 push 1
// 00433a11  53                   push ebx
// 00433a12  52                   push edx
// 00433a13  6a00                 push 0
// 00433a15  8bf3                 mov esi, ebx
// 00433a17  6a00                 push 0
// 00433a19  8d4f58               lea ecx, [edi + 0x58]
// 00433a1c  2bf0                 sub esi, eax
// 00433a1e  e829d02600           call 0x6a0a4c
// 00433a23  83bf9001000000       cmp dword ptr [edi + 0x190], 0
// 00433a2a  746f                 je 0x433a9b
// 00433a2c  8d44240c             lea eax, [esp + 0xc]
// 00433a30  50                   push eax
// 00433a31  8d4c2430             lea ecx, [esp + 0x30]
// 00433a35  51                   push ecx
// 00433a36  81c770010000         add edi, 0x170
// 00433a3c  6a00                 push 0
// 00433a3e  8bcf                 mov ecx, edi
// 00433a40  e8a3d62600           call 0x6a10e8
// 00433a45  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00433a49  8d0416               lea eax, [esi + edx]
// 00433a4c  8d8b6affffff         lea ecx, [ebx - 0x96]
// 00433a52  89442424             mov dword ptr [esp + 0x24], eax
// 00433a56  3bc1                 cmp eax, ecx
// 00433a58  894c2428             mov dword ptr [esp + 0x28], ecx
// 00433a5c  8d442424             lea eax, [esp + 0x24]
// 00433a60  7c04                 jl 0x433a66
// 00433a62  8d442428             lea eax, [esp + 0x28]
// 00433a66  8b00                 mov eax, dword ptr [eax]
// 00433a68  89442424             mov dword ptr [esp + 0x24], eax
// 00433a6c  83f832               cmp eax, 0x32
// 00433a6f  c744242832000000     mov dword ptr [esp + 0x28], 0x32
// 00433a77  8d442424             lea eax, [esp + 0x24]
// 00433a7b  7f04                 jg 0x433a81
// 00433a7d  8d442428             lea eax, [esp + 0x28]
// 00433a81  8b00                 mov eax, dword ptr [eax]
// 00433a83  6a00                 push 0
// 00433a85  50                   push eax
// 00433a86  6a00                 push 0
// 00433a88  8bcf                 mov ecx, edi
// 00433a8a  e8b7d52600           call 0x6a1046
// 00433a8f  8b07                 mov eax, dword ptr [edi]
// 00433a91  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 00433a97  8bcf                 mov ecx, edi
// 00433a99  ffd2                 call edx
// 00433a9b  5e                   pop esi
// 00433a9c  5b                   pop ebx
// 00433a9d  5f                   pop edi
// 00433a9e  83c414               add esp, 0x14
// 00433aa1  c20c00               ret 0xc

struct Rect
{
    int left, top, right, bottom;
};

extern "C" int (__stdcall *GetClientRect)(void *, Rect *);

struct Window;
typedef void (__thiscall *RefreshFunction)(Window *);

struct WindowTable
{
    void *reserved[84];
    RefreshFunction refresh;
};

struct Window
{
    WindowTable *table;
    char reserved0[28];
    void *handle;
    char reserved1[244];

    void move(int, int, int, int, int);
    void getRow(int, int *, int *);
    void setRow(int, int, int);
};

struct CObjectBrowser
{
    char reserved[88];
    Window first;
    Window second;

    void initial();
    void func_004339d0(int, int, int);
};

void CObjectBrowser::func_004339d0(int type, int width, int height)
{
    initial();
    if (type != 1 && first.handle)
    {
        Rect rect;
        int minimum;
        GetClientRect(first.handle, &rect);
        int h = rect.bottom - rect.top;

        {
        int cur; (void)cur;
        int difference = height - h;
        if (h != h) difference = h;
        first.move(0, 0, width, height, 1);

        if (second.handle)
        {
            second.getRow(0, &cur, &minimum);
            type = difference + cur;
            width = height - 150;
            type = *(type < width ? &type : &width);
            width = 50;
            type = *(type > width ? &type : &width);
            second.setRow(0, type, 0);
            second.table->refresh(&second);
        }
        }
    }
}
