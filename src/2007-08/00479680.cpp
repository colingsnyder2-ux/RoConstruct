// from server: 72% by colin
// roc 2007-08 00479680  unit: seg_00470000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00479680
//
// 00479680  e899731b00           call 0x630a1e
// 00479685  81c438010000         add esp, 0x138
// 0047968b  c20800               ret 8

extern "C" void __cdecl sub_00630a1e();

void __stdcall sub_00479680(int, int)
{
    sub_00630a1e();
}
