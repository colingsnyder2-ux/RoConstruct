// roc 2012-06 00825820  unit: RBX::$01::?$SurfaceDescriptor  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00825820
//
// 00825820  83ec60               sub esp, 0x60
// 00825823  53                   push ebx
// 00825824  56                   push esi
// 00825825  57                   push edi
// 00825826  8b7c2470             mov edi, dword ptr [esp + 0x70]
// 0082582a  837f1810             cmp dword ptr [edi + 0x18], 0x10
// 0082582e  8d7704               lea esi, [edi + 4]
// 00825831  7204                 jb 0x825837
// 00825833  8b06                 mov eax, dword ptr [esi]
// 00825835  eb02                 jmp 0x825839
// 00825837  8bc6                 mov eax, esi
// 00825839  8b1d7429b200         mov ebx, dword ptr [0xb22974]
// 0082583f  8d4c240c             lea ecx, [esp + 0xc]
// 00825843  51                   push ecx
// 00825844  50                   push eax
// 00825845  ffd3                 call ebx
// 00825847  83c408               add esp, 8
// 0082584a  85c0                 test eax, eax
// 0082584c  7409                 je 0x825857
// 0082584e  5f                   pop edi
// 0082584f  5e                   pop esi
// 00825850  32c0                 xor al, al
// 00825852  5b                   pop ebx
// 00825853  83c460               add esp, 0x60
// 00825856  c3                   ret 
// 00825857  8b442474             mov eax, dword ptr [esp + 0x74]
// 0082585b  83781810             cmp dword ptr [eax + 0x18], 0x10
// 0082585f  7205                 jb 0x825866
// 00825861  8b4004               mov eax, dword ptr [eax + 4]
// 00825864  eb03                 jmp 0x825869
// 00825866  83c004               add eax, 4
// 00825869  8d54243c             lea edx, [esp + 0x3c]
// 0082586d  52                   push edx
// 0082586e  50                   push eax
// 0082586f  ffd3                 call ebx
// 00825871  8b442438             mov eax, dword ptr [esp + 0x38]
// 00825875  83c408               add esp, 8
// 00825878  3b442460             cmp eax, dword ptr [esp + 0x60]
// 0082587c  7c17                 jl 0x825895
// 0082587e  7f0a                 jg 0x82588a
// 00825880  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00825884  3b4c245c             cmp ecx, dword ptr [esp + 0x5c]
// 00825888  720b                 jb 0x825895
// 0082588a  5f                   pop edi
// 0082588b  b301                 mov bl, 1
// 0082588d  5e                   pop esi
// 0082588e  8ac3                 mov al, bl
// 00825890  5b                   pop ebx
// 00825891  83c460               add esp, 0x60
// 00825894  c3                   ret 
// 00825895  32db                 xor bl, bl
// 00825897  837f1810             cmp dword ptr [edi + 0x18], 0x10
// 0082589b  7202                 jb 0x82589f
// 0082589d  8b36                 mov esi, dword ptr [esi]
// 0082589f  56                   push esi
// 008258a0  ff159c2ab200         call dword ptr [0xb22a9c]
// 008258a6  83c404               add esp, 4
// 008258a9  5f                   pop edi
// 008258aa  5e                   pop esi
// 008258ab  8ac3                 mov al, bl
// 008258ad  5b                   pop ebx
// 008258ae  83c460               add esp, 0x60
// 008258b1  c3                   ret 
// copied from an identical function in another client (function ?compareFiles@@YA_NABUString@@0@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct String {
    unsigned int proxy;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct StatData {
    char prefix[32];
    __int64 modificationTime;
    char suffix[8];
};

extern "C" {
    extern int (__cdecl *_stat64i32)(const char*, StatData*);
    extern int (__cdecl *_unlink)(const char*);
}

bool __cdecl compareFiles(const String& first, const String& second)
{
    StatData a, b;

    const char* path = first.capacity >= 16
        ? first.storage.pointer : first.storage.buffer;

    int (__cdecl *statFile)(const char*, StatData*) = _stat64i32;
    if (statFile(path, &a) != 0)
        return false;

    path = second.capacity >= 16
        ? second.storage.pointer : second.storage.buffer;
    statFile(path, &b);

    bool result;
    if (a.modificationTime >= b.modificationTime) {
        result = true;
    } else {
        result = false;
        path = first.capacity >= 16
            ? first.storage.pointer : first.storage.buffer;
        _unlink(path);
    }
    return result;
}