// from server: 100% by EspClaude
// roc 2009-06 004241e0  unit: MainLogManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004241e0
//
// 004241e0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004241e4  8b01                 mov eax, dword ptr [ecx]
// 004241e6  8b5004               mov edx, dword ptr [eax + 4]
// 004241e9  56                   push esi
// 004241ea  ffd2                 call edx
// 004241ec  8bf0                 mov esi, eax
// 004241ee  56                   push esi
// 004241ef  6a01                 push 1
// 004241f1  e8eaebffff           call 0x422de0
// 004241f6  8b442410             mov eax, dword ptr [esp + 0x10]
// 004241fa  83c408               add esp, 8
// 004241fd  6a00                 push 0
// 004241ff  6880128f00           push 0x8f1280
// 00424204  6a00                 push 0
// 00424206  6a00                 push 0
// 00424208  56                   push esi
// 00424209  50                   push eax
// 0042420a  e881fcffff           call 0x423e90
// 0042420f  5e                   pop esi
// 00424210  c3                   ret 
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
