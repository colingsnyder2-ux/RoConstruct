// from server: 100% by colin
// roc 2007-08 00726da0  unit: boost::thread_resource_error  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00726da0

extern "C" void __cdecl sub_725520(void *, void *);
extern "C" void __fastcall sub_725750(void *);
extern "C" void __fastcall sub_725770(void *);

extern void *dword_8C98F8;
extern char byte_726C80;
extern char byte_8C98FC;

struct boost_thread_resource_error {
    void __fastcall init();
};

void __fastcall boost_thread_resource_error::init()
{
    sub_725520(&byte_8C98FC, &byte_726C80);
    void *p = dword_8C98F8;
    sub_725750(p);
    sub_725770(p);
}
