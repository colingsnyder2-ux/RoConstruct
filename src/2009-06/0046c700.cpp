// from server: 100% by EspClaude
// from server: 73% by EspClaude
// roc 2009-06 0046c700  unit: DxUserInput  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046c700
//
// 0046c700  6aff                 push -1
// 0046c702  680c348500           push 0x85340c
// 0046c707  64a100000000         mov eax, dword ptr fs:[0]
// 0046c70d  50                   push eax
// 0046c70e  64892500000000       mov dword ptr fs:[0], esp
// 0046c715  81ecf4050000         sub esp, 0x5f4
// 0046c71b  56                   push esi
// 0046c71c  68f4010000           push 0x1f4
// 0046c721  8d842414020000       lea eax, [esp + 0x214]
// 0046c728  8bf1                 mov esi, ecx
// 0046c72a  8b8c240c060000       mov ecx, dword ptr [esp + 0x60c]
// 0046c731  50                   push eax
// 0046c732  51                   push ecx
// 0046c733  ff1588e28900         call dword ptr [0x89e288]
// 0046c739  6804010000           push 0x104
// 0046c73e  8d54240c             lea edx, [esp + 0xc]
// 0046c742  52                   push edx
// 0046c743  8d842418020000       lea eax, [esp + 0x218]
// 0046c74a  50                   push eax
// 0046c74b  ff1584e28900         call dword ptr [0x89e284]
// 0046c751  8d4c2408             lea ecx, [esp + 8]
// 0046c755  51                   push ecx
// 0046c756  8d4c2408             lea ecx, [esp + 8]
// 0046c75a  ff15c0fc8900         call dword ptr [0x89fcc0]
// 0046c760  50                   push eax
// 0046c761  8bce                 mov ecx, esi
// 0046c763  c784240406000000000000 mov dword ptr [esp + 0x604], 0
// 0046c76e  e89dfbffff           call 0x46c310
// 0046c773  8d4c2404             lea ecx, [esp + 4]
// 0046c777  8bf0                 mov esi, eax
// 0046c779  ff1510fd8900         call dword ptr [0x89fd10]
// 0046c77f  8b8c24f8050000       mov ecx, dword ptr [esp + 0x5f8]
// 0046c786  8bc6                 mov eax, esi
// 0046c788  5e                   pop esi
// 0046c789  64890d00000000       mov dword ptr fs:[0], ecx
// 0046c790  81c400060000         add esp, 0x600
// 0046c796  c20400               ret 4

// from server: 100% by colin
// roc 2008-06 0046a4f0  unit: DxUserInput  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046a4f0
//
// 0046a4f0  6aff                 push -1
// 0046a4f2  68fc377c00           push 0x7c37fc
// 0046a4f7  64a100000000         mov eax, dword ptr fs:[0]
// 0046a4fd  50                   push eax
// 0046a4fe  64892500000000       mov dword ptr fs:[0], esp
// 0046a505  81ecf8010000         sub esp, 0x1f8
// 0046a50b  56                   push esi
// 0046a50c  68f4010000           push 0x1f4
// 0046a511  8d44240c             lea eax, [esp + 0xc]
// 0046a515  8bf1                 mov esi, ecx
// 0046a517  8b8c2410020000       mov ecx, dword ptr [esp + 0x210]
// 0046a51e  50                   push eax
// 0046a51f  51                   push ecx
// 0046a520  ff15a4218000         call dword ptr [0x8021a4]
// 0046a526  8d542408             lea edx, [esp + 8]
// 0046a52a  52                   push edx
// 0046a52b  8d4c2408             lea ecx, [esp + 8]
// 0046a52f  ff15103f8000         call dword ptr [0x803f10]
// 0046a535  8d442404             lea eax, [esp + 4]
// 0046a539  50                   push eax
// 0046a53a  8bce                 mov ecx, esi
// 0046a53c  c784240802000000000000 mov dword ptr [esp + 0x208], 0
// 0046a547  e8d4fcffff           call 0x46a220
// 0046a54c  8d4c2404             lea ecx, [esp + 4]
// 0046a550  8bf0                 mov esi, eax
// 0046a552  ff15143f8000         call dword ptr [0x803f14]
// 0046a558  8b8c24fc010000       mov ecx, dword ptr [esp + 0x1fc]
// 0046a55f  8bc6                 mov eax, esi
// 0046a561  5e                   pop esi
// 0046a562  64890d00000000       mov dword ptr fs:[0], ecx
// 0046a569  81c404020000         add esp, 0x204
// 0046a56f  c20400               ret 4

extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameW(void *, wchar_t *, unsigned long);
extern "C" __declspec(dllimport) unsigned long __stdcall GetShortPathNameW(const wchar_t *, wchar_t *, unsigned long);

struct Text
{
    void *data;
    __declspec(dllimport) Text(const wchar_t *);
    __declspec(dllimport) ~Text() throw();
};

struct DxUserInput
{
    int process(const Text &);
    int func_0046a4f0(void *);
};

int DxUserInput::func_0046a4f0(void *module)
{
    wchar_t path[500];
    GetModuleFileNameW(module, path, 500);
    wchar_t shortPath[260];
    GetShortPathNameW(path, shortPath, 260);
    return process(Text(shortPath));
}
