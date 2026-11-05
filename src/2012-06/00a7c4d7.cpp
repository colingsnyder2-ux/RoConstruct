// from server: 38% by colin
extern "C" void __cdecl helper_a814d5(int);

extern "C" void __cdecl target_impl();

void target_impl()
{
    helper_a814d5(1);
    ((void (__cdecl *)())0xe08570)();
}
