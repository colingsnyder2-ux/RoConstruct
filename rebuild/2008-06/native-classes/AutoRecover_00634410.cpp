// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
// INFERRED: boost::any::holder<function<void(shared_ptr<Instance>)>>::clone() is `new holder(held)`.
// fn_006a0920 is operator new(size); fn_006343a0 is the holder copy constructor (held = this+8).
extern "C" void* __cdecl fn_006a0920(unsigned int size);
extern "C" void* __fastcall fn_006343a0(void* self, int unusedEdx, void* heldSrc);

extern "C" void* __fastcall fn_00634410(char* self, int unusedEdx)
{
    void* mem = fn_006a0920(0x28);
    if (!mem)
        return 0;
    return fn_006343a0(mem, 0, self + 8);
}
