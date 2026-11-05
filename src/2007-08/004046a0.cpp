// from server: 100% by colin
// roc 2007-08 004046a0  unit: seg_00400000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004046a0
//
// 004046a0  8b442404             mov eax, dword ptr [esp + 4]
// 004046a4  85c0                 test eax, eax
// 004046a6  7509                 jne 0x4046b1
// 004046a8  89442404             mov dword ptr [esp + 4], eax
// 004046ac  e9efe5ffff           jmp 0x402ca0
// 004046b1  89442404             mov dword ptr [esp + 4], eax
// 004046b5  e976f2ffff           jmp 0x403930

void __stdcall sub_402CA0(void* p);
void __stdcall sub_403930(void* p);

void __stdcall sub_4046A0(void* p)
{
    if (p == 0)
        sub_402CA0(p);
    else
        sub_403930(p);
}
