// from server: 100% by Xemicl
// roc 2012-06 00432b60  unit: ThreadLogManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00432b60
//
// 00432b60  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00432b64  8b01                 mov eax, dword ptr [ecx]
// 00432b66  8b5004               mov edx, dword ptr [eax + 4]
// 00432b69  56                   push esi
// 00432b6a  ffd2                 call edx
// 00432b6c  8bf0                 mov esi, eax
// 00432b6e  56                   push esi
// 00432b6f  6a01                 push 1
// 00432b71  e8faeaffff           call 0x431670
// 00432b76  8b442410             mov eax, dword ptr [esp + 0x10]
// 00432b7a  83c408               add esp, 8
// 00432b7d  6a00                 push 0
// 00432b7f  6868cdc000           push 0xc0cd68
// 00432b84  6a00                 push 0
// 00432b86  6a00                 push 0
// 00432b88  56                   push esi
// 00432b89  50                   push eax
// 00432b8a  e841fcffff           call 0x4327d0
// 00432b8f  5e                   pop esi
// 00432b90  c3                   ret 
// copied from an identical function in another client (function ?function_429360@ns_ROCX0000ae@@YAHHPAUS@1@@Z)

namespace ns_ROCX0000ae {
struct S {
    virtual void slot0();
    virtual int slot1();
};

extern char data_8501ec[];

extern "C" void __cdecl prepare(int, int);
extern "C" int __stdcall finish(int, int, int, int, const char *, int);

int __cdecl function_429360(int arg, S *object)
{
    int value = object->slot1();
    prepare(1, value);
    return finish(arg, value, 0, 0, data_8501ec, 0);
}
}