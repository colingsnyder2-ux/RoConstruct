// from server: 36% by colin
// roc 2007-08 00490a90  unit: RBX::Network::VPlayer::?$SignalDesc  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00490a90
//
// 00490a90  0000                 add byte ptr [eax], al
// 00490a92  0033                 add byte ptr [ebx], dh
// 00490a94  cc                   int3 
// 00490a95  e884ff1900           call 0x630a1e
// 00490a9a  81c4dc000000         add esp, 0xdc
// 00490aa0  c3                   ret 

extern "C" void __cdecl sub_00630a1e();

void sub_00490a90()
{
    sub_00630a1e();
}
