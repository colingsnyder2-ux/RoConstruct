// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00609a60  unit: RBX::Controller::W4ControllerType::?$EnumDesc  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00609a60
//
// 00609a60  56                   push esi
// 00609a61  57                   push edi
// 00609a62  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00609a66  6a00                 push 0
// 00609a68  68289a9500           push 0x959a28
// 00609a6d  687c909200           push 0x92907c
// 00609a72  6a00                 push 0
// 00609a74  57                   push edi
// 00609a75  e84c7d0900           call 0x6a17c6
// 00609a7a  8b742424             mov esi, dword ptr [esp + 0x24]
// 00609a7e  83c414               add esp, 0x14
// 00609a81  85c0                 test eax, eax
// 00609a83  741b                 je 0x609aa0
// 00609a85  6a00                 push 0
// 00609a87  68089a9500           push 0x959a08
// 00609a8c  687c909200           push 0x92907c
// 00609a91  6a00                 push 0
// 00609a93  56                   push esi
// 00609a94  e82d7d0900           call 0x6a17c6
// 00609a99  83c414               add esp, 0x14
// 00609a9c  85c0                 test eax, eax
// 00609a9e  7536                 jne 0x609ad6
// 00609aa0  6a00                 push 0
// 00609aa2  68289a9500           push 0x959a28
// 00609aa7  687c909200           push 0x92907c
// 00609aac  6a00                 push 0
// 00609aae  56                   push esi
// 00609aaf  e8127d0900           call 0x6a17c6
// 00609ab4  83c414               add esp, 0x14
// 00609ab7  85c0                 test eax, eax
// 00609ab9  7423                 je 0x609ade
// 00609abb  6a00                 push 0
// 00609abd  68089a9500           push 0x959a08
// 00609ac2  687c909200           push 0x92907c
// 00609ac7  6a00                 push 0
// 00609ac9  57                   push edi
// 00609aca  e8f77c0900           call 0x6a17c6
// 00609acf  83c414               add esp, 0x14
// 00609ad2  85c0                 test eax, eax
// 00609ad4  7408                 je 0x609ade
// 00609ad6  5f                   pop edi
// 00609ad7  b801000000           mov eax, 1
// 00609adc  5e                   pop esi
// 00609add  c3                   ret 
// 00609ade  5f                   pop edi
// 00609adf  33c0                 xor eax, eax
// 00609ae1  5e                   pop esi
// 00609ae2  c3                   ret 

extern char instanceType[];
extern char holeType[];
extern char motorFeatureType[];

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

int __cdecl matches(void* first, void* second)
{
    if ((__RTDynamicCast(first, 0, instanceType, holeType, 0) &&
         __RTDynamicCast(second, 0, instanceType, motorFeatureType, 0)) ||
        (__RTDynamicCast(second, 0, instanceType, holeType, 0) &&
         __RTDynamicCast(first, 0, instanceType, motorFeatureType, 0)))
        return 1;
    return 0;
}
