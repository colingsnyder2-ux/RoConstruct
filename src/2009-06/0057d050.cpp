// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005196b0  unit: G3D::_internal::DialogTemplate  size: 253 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005196b0
//
// 005196b0  83ec0c               sub esp, 0xc
// 005196b3  56                   push esi
// 005196b4  8bf1                 mov esi, ecx
// 005196b6  68c8878200           push 0x8287c8
// 005196bb  56                   push esi
// 005196bc  ff156c238000         call dword ptr [0x80236c]
// 005196c2  83c408               add esp, 8
// 005196c5  84c0                 test al, al
// 005196c7  7426                 je 0x5196ef
// 005196c9  8d442414             lea eax, [esp + 0x14]
// 005196cd  50                   push eax
// 005196ce  8d4c2408             lea ecx, [esp + 8]
// 005196d2  c7442418e88c8200     mov dword ptr [esp + 0x18], 0x828ce8
// 005196da  ff15a4288000         call dword ptr [0x8028a4]
// 005196e0  687c998d00           push 0x8d997c
// 005196e5  8d4c2408             lea ecx, [esp + 8]
// 005196e9  51                   push ecx
// 005196ea  e89d7e1800           call 0x6a158c
// 005196ef  55                   push ebp
// 005196f0  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005196f4  3b6e38               cmp ebp, dword ptr [esi + 0x38]
// 005196f7  7e26                 jle 0x51971f
// 005196f9  8d542418             lea edx, [esp + 0x18]
// 005196fd  52                   push edx
// 005196fe  8d4c240c             lea ecx, [esp + 0xc]
// 00519702  c744241c888c8200     mov dword ptr [esp + 0x1c], 0x828c88
// 0051970a  ff15a4288000         call dword ptr [0x8028a4]
// 00519710  687c998d00           push 0x8d997c
// 00519715  8d44240c             lea eax, [esp + 0xc]
// 00519719  50                   push eax
// 0051971a  e86d7e1800           call 0x6a158c
// 0051971f  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00519722  b856555555           mov eax, 0x55555556
// 00519727  f7e9                 imul ecx
// 00519729  53                   push ebx
// 0051972a  57                   push edi
// 0051972b  8b7e34               mov edi, dword ptr [esi + 0x34]
// 0051972e  8bc2                 mov eax, edx
// 00519730  c1e81f               shr eax, 0x1f
// 00519733  81ef0000a000         sub edi, 0xa00000
// 00519739  03c2                 add eax, edx
// 0051973b  3bf8                 cmp edi, eax
// 0051973d  7d02                 jge 0x519741
// 0051973f  8bf9                 mov edi, ecx
// 00519741  837e4400             cmp dword ptr [esi + 0x44], 0
// 00519745  b9808c8200           mov ecx, 0x828c80
// 0051974a  7705                 ja 0x519751
// 0051974c  b9b43e8200           mov ecx, 0x823eb4
// 00519751  837e1810             cmp dword ptr [esi + 0x18], 0x10
// 00519755  7205                 jb 0x51975c
// 00519757  8b4604               mov eax, dword ptr [esi + 4]
// 0051975a  eb03                 jmp 0x51975f
// 0051975c  8d4604               lea eax, [esi + 4]
// 0051975f  51                   push ecx
// 00519760  50                   push eax
// 00519761  ff1514288000         call dword ptr [0x802814]
// 00519767  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 0051976a  8bd8                 mov ebx, eax
// 0051976c  53                   push ebx
// 0051976d  57                   push edi
// 0051976e  6a01                 push 1
// 00519770  51                   push ecx
// 00519771  ff15d0278000         call dword ptr [0x8027d0]
// 00519777  53                   push ebx
// 00519778  ff15d4278000         call dword ptr [0x8027d4]
// 0051977e  297e34               sub dword ptr [esi + 0x34], edi
// 00519781  8b4630               mov eax, dword ptr [esi + 0x30]
// 00519784  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00519787  017e44               add dword ptr [esi + 0x44], edi
// 0051978a  297e3c               sub dword ptr [esi + 0x3c], edi
// 0051978d  51                   push ecx
// 0051978e  8d1438               lea edx, [eax + edi]
// 00519791  52                   push edx
// 00519792  50                   push eax
// 00519793  e848f2feff           call 0x5089e0
// 00519798  83c428               add esp, 0x28
// 0051979b  55                   push ebp
// 0051979c  8bce                 mov ecx, esi
// 0051979e  e88d13ffff           call 0x50ab30
// 005197a3  5f                   pop edi
// 005197a4  5b                   pop ebx
// 005197a5  5d                   pop ebp
// 005197a6  5e                   pop esi
// 005197a7  83c40c               add esp, 0xc
// 005197aa  c20400               ret 4

struct String {
    void* proxy;
    union {
        char local[16];
        char* heap;
    };
    unsigned size;
    unsigned capacity;
};

struct Exception {
    void* vtable;
    const char* message;
    int owned;
};

struct S {
    String filename;
    char reserved[20];
    char* buffer;
    int used;
    int capacity;
    int position;
    int reserved40;
    unsigned written;

    void flush(int count);
    void reserve(int count);
};

extern bool (__cdecl *string_equal)(const String*, const char*);
extern Exception* (__thiscall *exception_construct)(Exception*, const char* const*);
extern void* (__cdecl *file_open)(const char*, const char*);
extern unsigned (__cdecl *file_write)(const void*, unsigned, unsigned, void*);
extern int (__cdecl *file_close)(void*);
extern char exception_type;
extern "C" __declspec(noreturn) void __stdcall throw_exception(void*, void*);
extern "C" void* __cdecl move_bytes(void*, const void*, unsigned);

void S::flush(int count)
{
    if (string_equal(&filename, "<memory>")) {
        const char* message =
            "Out of memory while writing to memory in BinaryOutput (no RAM left).";
        Exception error;
        exception_construct(&error, &message);
        throw_exception(&error, &exception_type);
    }

    if (count > capacity) {
        const char* message =
            "Out of memory while writing to disk in BinaryOutput (could not create a large enough buffer).";
        Exception error;
        exception_construct(&error, &message);
        throw_exception(&error, &exception_type);
    }

    int amount = used - 0xA00000;
    if (amount < used / 3)
        amount = used;

    const char* mode = written > 0 ? "ab" : "wb";
    const char* name = filename.capacity >= 16
        ? filename.heap : filename.local;
    void* file = file_open(name, mode);
    file_write(buffer, 1, amount, file);
    file_close(file);

    used -= amount;
    written += amount;
    position -= amount;
    move_bytes(buffer, buffer + amount, used);
    reserve(count);
}
