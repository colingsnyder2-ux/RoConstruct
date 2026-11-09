// from server: 100% by colin
// roc 2007-08 00442a00  unit: ReflectionMetadata  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00442a00
//
// 00442a00  8b442404             mov eax, dword ptr [esp + 4]
// 00442a04  6a00                 push 0
// 00442a06  682c608800           push 0x88602c
// 00442a0b  684c1f8800           push 0x881f4c
// 00442a10  6a00                 push 0
// 00442a12  50                   push eax
// 00442a13  e81ee31e00           call 0x630d36
// 00442a18  83c414               add esp, 0x14
// 00442a1b  f7d8                 neg eax
// 00442a1d  1bc0                 sbb eax, eax
// 00442a1f  f7d8                 neg eax
// 00442a21  c20400               ret 4

extern "C" int __cdecl sub_630D36(int, int, const char*, const char*, int);

struct ReflectionMetadataReflection {
    int isA(int);
};

int ReflectionMetadataReflection::isA(int a) {
    int r = sub_630D36(a, 0, (const char*)0x881f4c, (const char*)0x88602c, 0);
    return r != 0;
}
