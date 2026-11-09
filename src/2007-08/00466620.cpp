// from server: 100% by Yeetserama
// roc 2007-08 00466620  unit: DxUserInput  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00466620
//
// 00466620  6aff                 push -1
// 00466622  683c327400           push 0x74323c
// 00466627  64a100000000         mov eax, dword ptr fs:[0]
// 0046662d  50                   push eax
// 0046662e  81ecfc010000         sub esp, 0x1fc
// 00466634  a188518b00           mov eax, dword ptr [0x8b5188]
// 00466639  33c4                 xor eax, esp
// 0046663b  898424f8010000       mov dword ptr [esp + 0x1f8], eax
// 00466642  56                   push esi
// 00466643  a188518b00           mov eax, dword ptr [0x8b5188]
// 00466648  33c4                 xor eax, esp
// 0046664a  50                   push eax
// 0046664b  8d842404020000       lea eax, [esp + 0x204]
// 00466652  64a300000000         mov dword ptr fs:[0], eax
// 00466658  8b842414020000       mov eax, dword ptr [esp + 0x214]
// 0046665f  8bf1                 mov esi, ecx
// 00466661  68f4010000           push 0x1f4
// 00466666  8d4c2410             lea ecx, [esp + 0x10]
// 0046666a  51                   push ecx
// 0046666b  50                   push eax
// 0046666c  ff15e0d27700         call dword ptr [0x77d2e0]
// 00466672  8d54240c             lea edx, [esp + 0xc]
// 00466676  52                   push edx
// 00466677  8d4c240c             lea ecx, [esp + 0xc]
// 0046667b  ff15b8dd7700         call dword ptr [0x77ddb8]
// 00466681  8d442408             lea eax, [esp + 8]
// 00466685  50                   push eax
// 00466686  8bce                 mov ecx, esi
// 00466688  c784241002000000000000 mov dword ptr [esp + 0x210], 0
// 00466693  e8b8fcffff           call 0x466350
// 00466698  8d4c2408             lea ecx, [esp + 8]
// 0046669c  8bf0                 mov esi, eax
// 0046669e  ff15bcdd7700         call dword ptr [0x77ddbc]
// 004666a4  8bc6                 mov eax, esi
// 004666a6  8b8c2404020000       mov ecx, dword ptr [esp + 0x204]
// 004666ad  64890d00000000       mov dword ptr fs:[0], ecx
// 004666b4  59                   pop ecx
// 004666b5  5e                   pop esi
// 004666b6  8b8c24f8010000       mov ecx, dword ptr [esp + 0x1f8]
// 004666bd  33cc                 xor ecx, esp
// 004666bf  e85aa31c00           call 0x630a1e
// 004666c4  81c408020000         add esp, 0x208
// 004666ca  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000002_0046a4f0@DxUserInput@ns_ROCX000002@@QAEHPAX@Z)

namespace ns_ROCX000002 {
// from server: 100% by colin
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
    int fn_ROCX000002_0046a4f0(void *);
};

int DxUserInput::fn_ROCX000002_0046a4f0(void *module)
{
    char path[500];
    GetModuleFileNameA(module, path, 500);
    Text text(path);
    return process(text);
}
}
