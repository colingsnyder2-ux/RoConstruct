// from server: 72% by colin
// roc 2007-08 004c2330  unit: RakPeer  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004c2330
//
// 004c2330  e8e9e61600           call 0x630a1e
// 004c2335  81c400020000         add esp, 0x200
// 004c233b  c20800               ret 8

extern "C" void __cdecl sub_00630a1e();

void __stdcall sub_004c2330(int, int)
{
    sub_00630a1e();
}
