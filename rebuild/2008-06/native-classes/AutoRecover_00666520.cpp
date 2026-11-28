// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: scalar deleting destructor of a class derived from HUMAN::HumanoidState
// with two vtable pointers (offsets 0 and 4); operator delete is ??3@YAXPAX@Z.
// The base destructor takes only ecx (this), so it is declared with a single
// __fastcall parameter. This keeps the compiler from zeroing edx before the call.
extern "C" void __fastcall fn_006435c0(void* self);

// INFERRED: unknown vtable globals, referenced by address only
extern "C" char g_0084cc38[];
extern "C" char g_0084cc30[];

struct Obj666da0
{
    const void* table0;
    const void* table1;
};

extern "C" Obj666da0* __fastcall fn_00666520(Obj666da0* self, int unusedEdx, unsigned int flags)
{
    self->table0 = g_0084cc38;
    self->table1 = g_0084cc30;
    fn_006435c0(self);
    if (flags & 1)
        ::operator delete(self);
    return self;
}
