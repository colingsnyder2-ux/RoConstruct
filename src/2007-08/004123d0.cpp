// from server: 100% by colin
// roc 2007-08 004123d0  unit: seg_00410000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004123d0
//
// 004123d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004123d4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004123d8  8b542404             mov edx, dword ptr [esp + 4]
// 004123dc  50                   push eax
// 004123dd  51                   push ecx
// 004123de  68c46e7800           push 0x786ec4
// 004123e3  52                   push edx
// 004123e4  e8b7fefeff           call 0x4022a0
// 004123e9  c20c00               ret 0xc

extern "C" int __stdcall sub_4022a0(int, const char*, int, int);

struct VCContent_CComObject
{
    int method(int a, int b, int c);
};

int VCContent_CComObject::method(int a, int b, int c)
{
    return sub_4022a0(a, (const char*)0x786ec4, b, c);
}
