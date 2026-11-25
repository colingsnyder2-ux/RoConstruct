// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 0040e9e0  unit: boost::gregorian::Ubad_year::U?$error_info_injector::?$clone_impl  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040e9e0
//
// 0040e9e0  8b442404             mov eax, dword ptr [esp + 4]
// 0040e9e4  56                   push esi
// 0040e9e5  50                   push eax
// 0040e9e6  8bf1                 mov esi, ecx
// 0040e9e8  e813f2ffff           call 0x40dc00
// 0040e9ed  c7463c343cb400       mov dword ptr [esi + 0x3c], 0xb43c34
// 0040e9f4  c706b442b400         mov dword ptr [esi], 0xb442b4
// 0040e9fa  c74628ac42b400       mov dword ptr [esi + 0x28], 0xb442ac
// 0040ea01  c7463c9c42b400       mov dword ptr [esi + 0x3c], 0xb4429c
// 0040ea08  8bc6                 mov eax, esi
// 0040ea0a  5e                   pop esi
// 0040ea0b  c20400               ret 4

struct S
{
    int *clone(int *);
};

int *S::clone(int *p)
{
    clone(p);
    *(volatile int *)((char *)this + 0x68) = 0xb43c34;
    *(int *)this = 0xb442b4;
    *(int *)((char *)this + 0x54) = 0xb442ac;
    *(int *)((char *)this + 0x68) = 0xb4429c;
    return (int *)this;
}
