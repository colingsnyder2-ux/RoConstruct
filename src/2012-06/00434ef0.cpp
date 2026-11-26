// from server: 100% by Xemicl
// roc 2012-06 00434ef0  unit: CMainFrame  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00434ef0
//
// 00434ef0  56                   push esi
// 00434ef1  8b742408             mov esi, dword ptr [esp + 8]
// 00434ef5  56                   push esi
// 00434ef6  e8bbdb5400           call 0x982ab6
// 00434efb  85c0                 test eax, eax
// 00434efd  7504                 jne 0x434f03
// 00434eff  5e                   pop esi
// 00434f00  c20400               ret 4
// 00434f03  e8cad45400           call 0x9823d2
// 00434f08  6880000000           push 0x80
// 00434f0d  6a0e                 push 0xe
// 00434f0f  6880000000           push 0x80
// 00434f14  e843db5400           call 0x982a5c
// 00434f19  50                   push eax
// 00434f1a  ff15fc3ab200         call dword ptr [0xb23afc]
// 00434f20  50                   push eax
// 00434f21  6a00                 push 0
// 00434f23  6a00                 push 0
// 00434f25  6a00                 push 0
// 00434f27  e884db5400           call 0x982ab0
// 00434f2c  894628               mov dword ptr [esi + 0x28], eax
// 00434f2f  b801000000           mov eax, 1
// 00434f34  5e                   pop esi
// 00434f35  c20400               ret 4
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