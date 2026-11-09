// roc 2008-06 0068a030  unit: seg_00680000  size: 5516 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068a030
//
// 0068a030  0000                 add byte ptr [eax], al
// 0068a032  00d9                 add cl, bl
// 0068a034  9c                   pushfd 
// 0068a035  24d0                 and al, 0xd0
// 0068a037  0000                 add byte ptr [eax], al
// 0068a039  00e9                 add cl, ch
// 0068a03b  e80500008d           call 0x8d68a045
// 0068a040  58                   pop eax

void func_0068a030()
{
}
