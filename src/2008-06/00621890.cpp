// from server: 100% by 2gx

// roc 2008-06 00621890  unit: lua_exception  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00621890
//
// 00621890  6aff                 push -1
// 00621892  6859cd7b00           push 0x7bcd59
// 00621897  64a100000000         mov eax, dword ptr fs:[0]
// 0062189d  50                   push eax
// 0062189e  64892500000000       mov dword ptr fs:[0], esp
// 006218a5  51                   push ecx
// 006218a6  56                   push esi
// 006218a7  8bf1                 mov esi, ecx
// 006218a9  89742404             mov dword ptr [esp + 4], esi
// 006218ad  c706cc478400         mov dword ptr [esi], 0x8447cc
// 006218b3  33c0                 xor eax, eax
// 006218b5  89442410             mov dword ptr [esp + 0x10], eax
// 006218b9  384614               cmp byte ptr [esi + 0x14], al
// 006218bc  7514                 jne 0x6218d2
// 006218be  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006218c1  894108               mov dword ptr [ecx + 8], eax
// 006218c4  8b560c               mov edx, dword ptr [esi + 0xc]
// 006218c7  6afe                 push -2
// 006218c9  52                   push edx
// 006218ca  e85103ffff           call 0x611c20
// 006218cf  83c408               add esp, 8
// 006218d2  8bce                 mov ecx, esi
// 006218d4  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006218dc  ff159c288000         call dword ptr [0x80289c]
// 006218e2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006218e6  5e                   pop esi
// 006218e7  64890d00000000       mov dword ptr fs:[0], ecx
// 006218ee  83c410               add esp, 0x10
// 006218f1  c3                   ret

typedef unsigned char u8;
typedef unsigned int u32;

struct __declspec(dllimport) lua_exception_base {
    virtual ~lua_exception_base();
};

void __cdecl lua_cleanup(void*, int);

struct lua_exception : lua_exception_base {
    u32 field04;
    u32 field08;
    void* field0C;
    u32* field10;
    u8 flag14;

    virtual ~lua_exception();
};

lua_exception::~lua_exception()
{
    if (!flag14) {
        field10[2] = 0;
        lua_cleanup(field0C, -2);
    }
}

void func_00621890()
{
}
