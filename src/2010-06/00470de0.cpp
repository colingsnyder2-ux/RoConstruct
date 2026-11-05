// from server: 100% by Yeetserama
// roc 2010-06 00470de0  unit: CScriptEditor  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00470de0
//
// 00470de0  833d0821c00000       cmp dword ptr [0xc02108], 0
// 00470de7  56                   push esi
// 00470de8  8bf1                 mov esi, ecx
// 00470dea  751b                 jne 0x470e07
// 00470dec  681c0ea100           push 0xa10e1c
// 00470df1  ff1548a39e00         call dword ptr [0x9ea348]
// 00470df7  a30421c000           mov dword ptr [0xc02104], eax
// 00470dfc  85c0                 test eax, eax
// 00470dfe  7507                 jne 0x470e07
// 00470e00  83c8ff               or eax, 0xffffffff
// 00470e03  5e                   pop esi
// 00470e04  c20400               ret 4
// 00470e07  8b442408             mov eax, dword ptr [esp + 8]
// 00470e0b  ff050821c000         inc dword ptr [0xc02108]
// 00470e11  50                   push eax
// 00470e12  8bce                 mov ecx, esi
// 00470e14  e867f1ffff           call 0x46ff80
// 00470e19  40                   inc eax
// 00470e1a  f7d8                 neg eax
// 00470e1c  1bc0                 sbb eax, eax
// 00470e1e  f7d8                 neg eax
// 00470e20  48                   dec eax
// 00470e21  5e                   pop esi
// 00470e22  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000012_00463930@CObjectBrowser@ns_ROCX000012@@QAEHPAX@Z)

namespace ns_ROCX000012 {
// from server: 100% by king_originala
extern "C" void* (__stdcall *LoadLibraryA)(const char*);
extern void* moduleHandle;
extern int referenceCount;

struct CObjectBrowser
{
    int fn_ROCX000012_00462c60(void* argument);
    int fn_ROCX000012_00463930(void* argument);
};

int CObjectBrowser::fn_ROCX000012_00463930(void* argument)
{
    if (referenceCount == 0)
    {
        moduleHandle = LoadLibraryA("SciLexer.dll");
        if (moduleHandle == 0)
            return -1;
    }

    ++referenceCount;
    return fn_ROCX000012_00462c60(argument) == -1 ? -1 : 0;
}
}
