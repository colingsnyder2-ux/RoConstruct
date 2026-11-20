// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 007f5c40 (5 bytes): `jmp fn_005c8b00`.
// Original assembly (roc native-asm 2008-06 007f5c40):
//     007f5c40  jmp 0x5c8b00  ; fn_005c8b00 [unit? RBX::LaserTool]
// The wrapper's destructor label (??1BallBallContact@RBX@@UAE@XZ) is an INFERRED
// name and is inconsistent with the real target: 005c8b00 is a 86-byte static
// singleton/critical-section getter (returns 0x9796d4 after InitializeCriticalSection),
// not a destructor.  INFERRED: the forwarder name sub_007f5c40 and the target
// prototype name sub_005c8b00 are placeholders; identity is carried by the jump
// relocation to the original target.  No class/struct/union/extern variable is
// defined here (owner rule).
void* sub_005c8b00();

void* sub_007f5c40()
{
    return sub_005c8b00();
}
