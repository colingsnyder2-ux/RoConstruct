// from server: 100% by why2
// roc 2009-06 005122c0  unit: CSHA1  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005122c0
//
// 005122c0  8b442404             mov eax, dword ptr [esp + 4]
// 005122c4  8b08                 mov ecx, dword ptr [eax]
// 005122c6  8bc1                 mov eax, ecx
// 005122c8  c1e803               shr eax, 3
// 005122cb  03c1                 add eax, ecx
// 005122cd  c3                   ret

int __cdecl sub_5122C0(unsigned int* p)
{
    unsigned int v = *p;
    return (v >> 3) + v;
}
