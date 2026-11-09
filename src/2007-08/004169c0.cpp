// from server: 100% by colin
// roc 2007-08 004169c0  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004169c0

extern "C" void __cdecl sub_415E10(void*);
extern "C" void __cdecl sub_4165F0(void*);

void __cdecl sub_4169C0(void* p)
{
    if (p == 0)
    {
        sub_415E10(p);
    }
    else
    {
        sub_4165F0(p);
    }
}
