// from server: 100% by EspClaude
// roc 2009-06 00427280  unit: CMainFrame  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427280
//
// 00427280  56                   push esi
// 00427281  8b742408             mov esi, dword ptr [esp + 8]
// 00427285  56                   push esi
// 00427286  e879212f00           call 0x719404
// 0042728b  85c0                 test eax, eax
// 0042728d  7504                 jne 0x427293
// 0042728f  5e                   pop esi
// 00427290  c20400               ret 4
// 00427293  e85e1a2f00           call 0x718cf6
// 00427298  6880000000           push 0x80
// 0042729d  6a0e                 push 0xe
// 0042729f  6880000000           push 0x80
// 004272a4  e80d212f00           call 0x7193b6
// 004272a9  50                   push eax
// 004272aa  ff15f0ed8900         call dword ptr [0x89edf0]
// 004272b0  50                   push eax
// 004272b1  6a00                 push 0
// 004272b3  6a00                 push 0
// 004272b5  6a00                 push 0
// 004272b7  e842212f00           call 0x7193fe
// 004272bc  894628               mov dword ptr [esi + 0x28], eax
// 004272bf  b801000000           mov eax, 1
// 004272c4  5e                   pop esi
// 004272c5  c20400               ret 4
// copied from an identical function in another client (function ?create@ns_ROCX0000da@@YGHPAUS@1@@Z)

namespace ns_ROCX0000da {
struct S {
    char pad[0x28];
    int value;
};

extern "C" int __stdcall sub_006a0f92(S*);
extern "C" void __stdcall sub_006a0926();
extern "C" void* __stdcall sub_006a0f2c(const char*, const char*);
extern "C" void* (__stdcall *LoadIconA)(void*, const char*);
extern "C" int __stdcall sub_006a0f8c(int, int, int, void*);

int __stdcall create(S* object)
{
    if (!sub_006a0f92(object))
        return 0;

    sub_006a0926();
    object->value = sub_006a0f8c(
        0, 0, 0,
        LoadIconA(sub_006a0f2c((const char*)128, (const char*)14),
                  (const char*)128));
    return 1;
}
}
