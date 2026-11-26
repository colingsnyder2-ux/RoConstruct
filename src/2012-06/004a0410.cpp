// from server: 100% by Xemicl
// roc 2012-06 004a0410  unit: CObjectBrowser  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0410
//
// 004a0410  833d64a9e10000       cmp dword ptr [0xe1a964], 0
// 004a0417  56                   push esi
// 004a0418  8bf1                 mov esi, ecx
// 004a041a  751b                 jne 0x4a0437
// 004a041c  686407b600           push 0xb60764
// 004a0421  ff154822b200         call dword ptr [0xb22248]
// 004a0427  a360a9e100           mov dword ptr [0xe1a960], eax
// 004a042c  85c0                 test eax, eax
// 004a042e  7507                 jne 0x4a0437
// 004a0430  83c8ff               or eax, 0xffffffff
// 004a0433  5e                   pop esi
// 004a0434  c20400               ret 4
// 004a0437  8b442408             mov eax, dword ptr [esp + 8]
// 004a043b  ff0564a9e100         inc dword ptr [0xe1a964]
// 004a0441  50                   push eax
// 004a0442  8bce                 mov ecx, esi
// 004a0444  e867f1ffff           call 0x49f5b0
// 004a0449  40                   inc eax
// 004a044a  f7d8                 neg eax
// 004a044c  1bc0                 sbb eax, eax
// 004a044e  f7d8                 neg eax
// 004a0450  48                   dec eax
// 004a0451  5e                   pop esi
// 004a0452  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00001f_00463930@CObjectBrowser@ns_ROCX00001f@@QAEHPAX@Z)

namespace ns_ROCX00001f {
extern "C" void* (__stdcall *LoadLibraryA)(const char*);
extern void* moduleHandle;
extern int referenceCount;

struct CObjectBrowser
{
    int fn_ROCX00001f_00462c60(void* argument);
    int fn_ROCX00001f_00463930(void* argument);
};

int CObjectBrowser::fn_ROCX00001f_00463930(void* argument)
{
    if (referenceCount == 0)
    {
        moduleHandle = LoadLibraryA("SciLexer.dll");
        if (moduleHandle == 0)
            return -1;
    }

    ++referenceCount;
    return fn_ROCX00001f_00462c60(argument) == -1 ? -1 : 0;
}
}
