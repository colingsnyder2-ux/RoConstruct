// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 00466350  unit: DxUserInput  size: 330 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00466350
// 00466350  6aff                 push -1
// 00466352  68c9317400           push 0x7431c9
// 00466357  64a100000000         mov eax, dword ptr fs:[0]
// 0046635d  50                   push eax
// 0046635e  83ec0c               sub esp, 0xc
// 00466361  53                   push ebx
// 00466362  55                   push ebp
// 00466363  56                   push esi
// 00466364  57                   push edi
// 00466365  a188518b00           mov eax, dword ptr [0x8b5188]
// 0046636a  33c4                 xor eax, esp
// 0046636c  50                   push eax
// 0046636d  8d442420             lea eax, [esp + 0x20]
// 00466371  64a300000000         mov dword ptr fs:[0], eax
// 00466377  8bf1                 mov esi, ecx
// 00466379  8b4604               mov eax, dword ptr [esi + 4]
// 0046637c  33ed                 xor ebp, ebp
// 0046637e  3bc5                 cmp eax, ebp
// 00466380  896e10               mov dword ptr [esi + 0x10], ebp
// 00466383  740c                 je 0x466391
// 00466385  50                   push eax
// 00466386  e89b9b1c00           call 0x62ff26
// 0046638b  83c404               add esp, 4
// 0046638e  896e04               mov dword ptr [esi + 4], ebp
// 00466391  8b442430             mov eax, dword ptr [esp + 0x30]
// 00466395  8d5e08               lea ebx, [esi + 8]
// 00466398  50                   push eax
// 00466399  8d4c2418             lea ecx, [esp + 0x18]
// 0046639d  66892e               mov word ptr [esi], bp
// 004663a0  66c74602e404         mov word ptr [esi + 2], 0x4e4
// 004663a6  892b                 mov dword ptr [ebx], ebp
// 004663a8  896e0c               mov dword ptr [esi + 0xc], ebp
// 004663ab  ff1574dd7700         call dword ptr [0x77dd74]
// 004663b1  8d4c2418             lea ecx, [esp + 0x18]
// 004663b5  51                   push ecx
// 004663b6  8d4c2418             lea ecx, [esp + 0x18]
// 004663ba  896c242c             mov dword ptr [esp + 0x2c], ebp
// 004663be  896c2420             mov dword ptr [esp + 0x20], ebp
// 004663c2  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004663c6  ff15acd57700         call dword ptr [0x77d5ac]
// 004663cc  50                   push eax
// 004663cd  e85e0d2c00           call 0x727130
// 004663d2  8bf8                 mov edi, eax
// 004663d4  3bfd                 cmp edi, ebp
// 004663d6  0f8487000000         je 0x466463
// 004663dc  57                   push edi
// 004663dd  e8509b1c00           call 0x62ff32
// 004663e2  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004663e6  83c404               add esp, 4
// 004663e9  50                   push eax
// 004663ea  57                   push edi
// 004663eb  52                   push edx
// 004663ec  8d4c2420             lea ecx, [esp + 0x20]
// 004663f0  894604               mov dword ptr [esi + 4], eax
// 004663f3  ff15acd57700         call dword ptr [0x77d5ac]
// 004663f9  50                   push eax
// 004663fa  e82b0d2c00           call 0x72712a
// 004663ff  85c0                 test eax, eax
// 00466401  7460                 je 0x466463
// 00466403  8b4e04               mov ecx, dword ptr [esi + 4]
// 00466406  8d442430             lea eax, [esp + 0x30]
// 0046640a  50                   push eax
// 0046640b  8d4610               lea eax, [esi + 0x10]
// 0046640e  50                   push eax
// 0046640f  6884a17800           push 0x78a184
// 00466414  51                   push ecx
// 00466415  896c2440             mov dword ptr [esp + 0x40], ebp
// 00466419  e8060d2c00           call 0x727124
// 0046641e  85c0                 test eax, eax
// 00466420  7441                 je 0x466463
// 00466422  8b4604               mov eax, dword ptr [esi + 4]
// 00466425  8d542430             lea edx, [esp + 0x30]
// 00466429  52                   push edx
// 0046642a  53                   push ebx
// 0046642b  68185c7900           push 0x795c18
// 00466430  50                   push eax
// 00466431  e8ee0c2c00           call 0x727124
// 00466436  85c0                 test eax, eax
// 00466438  741f                 je 0x466459
// 0046643a  8b442430             mov eax, dword ptr [esp + 0x30]
// 0046643e  83f804               cmp eax, 4
// 00466441  7216                 jb 0x466459
// 00466443  8b1b                 mov ebx, dword ptr [ebx]
// 00466445  c1e802               shr eax, 2
// 00466448  89460c               mov dword ptr [esi + 0xc], eax
// 0046644b  668b0b               mov cx, word ptr [ebx]
// 0046644e  66890e               mov word ptr [esi], cx
// 00466451  668b5302             mov dx, word ptr [ebx + 2]
// 00466455  66895602             mov word ptr [esi + 2], dx
// 00466459  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00466461  eb13                 jmp 0x466476
// 00466463  8b4604               mov eax, dword ptr [esi + 4]
// 00466466  3bc5                 cmp eax, ebp
// 00466468  740c                 je 0x466476
// 0046646a  50                   push eax
// 0046646b  e8b69a1c00           call 0x62ff26
// 00466470  83c404               add esp, 4
// 00466473  896e04               mov dword ptr [esi + 4], ebp
// 00466476  8d4c2414             lea ecx, [esp + 0x14]
// 0046647a  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00466480  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00466484  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00466488  64890d00000000       mov dword ptr fs:[0], ecx
// 0046648f  59                   pop ecx
// 00466490  5f                   pop edi
// 00466491  5e                   pop esi
// 00466492  5d                   pop ebp
// 00466493  5b                   pop ebx
// 00466494  83c418               add esp, 0x18
// 00466497  c20400               ret 4

typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef int BOOL;

extern "C" DWORD __stdcall GetFileVersionInfoSizeA(const char*, DWORD*);
extern "C" BOOL __stdcall GetFileVersionInfoA(const char*, DWORD, DWORD, void*);
extern "C" BOOL __stdcall VerQueryValueA(const void*, const char*, void**, UINT*);

class __declspec(dllimport) CStr {
public:
    CStr(const char* s);
    ~CStr() throw();
    operator const char*() const;
private:
    char* m_p;
};

struct FileVersionInfo {
    unsigned short lang;            // +0
    unsigned short codepage;        // +2
    unsigned char* data;            // +4
    unsigned short* translations;   // +8
    UINT translationCount;          // +0xc
    void* fixedInfo;                // +0x10
    BOOL load(const char* fileName);
};

BOOL FileVersionInfo::load(const char* fileName)
{
    fixedInfo = 0;
    if (data) {
        delete[] data;
        data = 0;
    }
    lang = 0;
    codepage = 0x4e4;
    translations = 0;
    translationCount = 0;

    CStr name(fileName);
    BOOL result = 0;
    DWORD handle = 0;
    DWORD size = GetFileVersionInfoSizeA(name, &handle);
    if (size) {
        data = new unsigned char[size];
        if (GetFileVersionInfoA(name, handle, size, data)) {
            UINT len = 0;
            if (VerQueryValueA(data, "\\", &fixedInfo, &len)) {
                if (VerQueryValueA(data, "\\VarFileInfo\\Translation", (void**)&translations, &len) && len >= 4) {
                    translationCount = len >> 2;
                    lang = translations[0];
                    codepage = translations[1];
                }
                result = 1;
                goto done;
            }
        }
    }
    if (data) {
        delete[] data;
        data = 0;
    }
done:
    return result;
}
