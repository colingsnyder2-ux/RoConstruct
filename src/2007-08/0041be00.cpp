// from server: 100% by colin
// roc 2007-08 0041be00  unit: VDHTMLWindow::?$SignalDesc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041be00
//
// 0041be00  837c240804           cmp dword ptr [esp + 8], 4
// 0041be05  7506                 jne 0x41be0d
// 0041be07  b805400080           mov eax, 0x80004005
// 0041be0c  c3                   ret
// 0041be0d  8b442404             mov eax, dword ptr [esp + 4]
// 0041be11  50                   push eax
// 0041be12  e869ffffff           call 0x41bd80
// 0041be17  83c404               add esp, 4
// 0041be1a  c3                   ret

extern "C" int __cdecl sub_41bd80(int arg);

int __cdecl sub_41be00(int a, int b)
{
    if (b == 4)
        return (int)0x80004005;
    return sub_41bd80(a);
}
