// from server: 73% by EspClaude
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

extern "C" unsigned long (__stdcall *GetModuleFileNameA)(
    void *, char *, unsigned long);

struct Text;

struct Text
{
    void *data;
    __declspec(dllimport) Text(const char *);
    __declspec(dllimport) ~Text() throw();
};





struct DxUserInput
{
    int process(const Text &);
    int func_0046a4f0(void *);
};

int DxUserInput::func_0046a4f0(void *module)
{
    char path[500];
    GetModuleFileNameA(module, path, 500);
    Text text(path);
    return process(text);
}
