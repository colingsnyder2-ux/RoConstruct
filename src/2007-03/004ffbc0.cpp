// from server: 100% by auto
// roc 2007-03 004ffbc0  unit: seg_004f0000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004ffbc0
//
// 004ffbc0  b801000000           mov eax, 1
// 004ffbc5  8405acae8b00         test byte ptr [0x8baeac], al
// 004ffbcb  7538                 jne 0x4ffc05
// 004ffbcd  d9ee                 fldz 
// 004ffbcf  0905acae8b00         or dword ptr [0x8baeac], eax
// 004ffbd5  83ec24               sub esp, 0x24
// 004ffbd8  d9542420             fst dword ptr [esp + 0x20]
// 004ffbdc  d954241c             fst dword ptr [esp + 0x1c]
// 004ffbe0  b988ae8b00           mov ecx, 0x8bae88
// 004ffbe5  d9542418             fst dword ptr [esp + 0x18]
// 004ffbe9  d9542414             fst dword ptr [esp + 0x14]
// 004ffbed  d9542410             fst dword ptr [esp + 0x10]
// 004ffbf1  d954240c             fst dword ptr [esp + 0xc]
// 004ffbf5  d9542408             fst dword ptr [esp + 8]
// 004ffbf9  d9542404             fst dword ptr [esp + 4]
// 004ffbfd  d91c24               fstp dword ptr [esp]
// 004ffc00  e8abfaffff           call 0x4ff6b0
// 004ffc05  b888ae8b00           mov eax, 0x8bae88
// 004ffc0a  c3                   ret 
// library rbx2016-g3d/Quat.cpp (function ?zero@Matrix3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Quat.cpp
