// from server: 75% by why2
// roc 2009-06 0074a330  unit: CXTPReportControl  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0074a330
//
// 0074a330  e84502fdff           call 0x71a57a
// 0074a335  83c470               add esp, 0x70
// 0074a338  c3                   ret 
// 0074a339  e8a6e9fcff           call 0x718ce4

extern "C" void __cdecl sub_71A57A();
extern "C" void __cdecl sub_718CE4();

void sub_74A330()
{
    sub_71A57A();
    sub_718CE4();
}
