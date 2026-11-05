// from server: 100% by colin
// roc 2007-08 0040d190  unit: ChatEnter  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040d190
//
// 0040d190  8b442404             mov eax, dword ptr [esp + 4]
// 0040d194  6a00                 push 0
// 0040d196  68301f8800           push 0x881f30
// 0040d19b  684c1f8800           push 0x881f4c
// 0040d1a0  6a00                 push 0
// 0040d1a2  50                   push eax
// 0040d1a3  e88e3b2200           call 0x630d36
// 0040d1a8  83c414               add esp, 0x14
// 0040d1ab  f7d8                 neg eax
// 0040d1ad  1bc0                 sbb eax, eax
// 0040d1af  f7d8                 neg eax
// 0040d1b1  c20400               ret 4

extern "C" int __cdecl sub_630d36(int, int, int, int, int);

int __stdcall ChatEnter(int a1)
{
    int r = sub_630d36(a1, 0, 0x881f4c, 0x881f30, 0);
    return r != 0;
}
