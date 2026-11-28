// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
// INFERRED: boost::any::holder<boost::function<void(shared_ptr<Instance>)>>::clone();
// operator new = fn_006a0920 (cdecl, only the size is passed); copy ctor body = fn_00633ba0.
extern "C" int fn_006a0920(int a1);
extern "C" int __fastcall fn_00633ba0(void* self, int unusedEdx, int a1);

struct Local_00633c10
{
    int vtbl;
    int held[9];

    // INFERRED: the original new-expression has an EH frame, so operator new/delete are class-scope.
    static void* operator new(unsigned int size) { return (void*)fn_006a0920((int)size); }
    static void operator delete(void*) {}

    Local_00633c10(char* src) { fn_00633ba0(this, 0, (int)src); }
};

extern "C" Local_00633c10* __fastcall fn_00633c10(char* self, int unusedEdx)
{
    return new Local_00633c10(self + 8);
}
