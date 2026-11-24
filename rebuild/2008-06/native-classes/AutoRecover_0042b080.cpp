// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stddef.h>
#include <new>

// INFERRED: the allocator is called with the size only (cdecl, one pushed arg).
extern "C" void* fn_006a0920(int size);
// INFERRED: fn_0042b010 is the holder copy-constructor (this = new object, a1 = &source.held).
// It returns "this" in eax, like any MSVC constructor.
extern "C" int __fastcall fn_0042b010(void* self, int unusedEdx, int a1);

// INFERRED: layout is vptr (4 bytes), padding to 8, then the boost::function 'held' member; 0x28 bytes total.
struct HolderClone
{
    char data[0x28];

    static void* operator new(size_t n)
    {
        return fn_006a0920((int)n);
    }
    static void operator delete(void* p)
    {
        ::operator delete(p);
    }

    // INFERRED: the constructor is not defined here. Its symbol is aliased to
    // fn_0042b010, so the compiler sees a real, non-inlined constructor call
    // whose return value (this) is used as the result of the new-expression.
    explicit HolderClone(const void* heldSrc);
};

// INFERRED: linker alias from the constructor's mangled name to the extern "C" fastcall helper.
#pragma comment(linker, "/alternatename:??0HolderClone@@QAE@PBX@Z=@fn_0042b010@12")

// boost::any::holder<boost::function<void(shared_ptr<Instance>)>>::clone() const
extern "C" void* __fastcall fn_0042b080(void* self, int unusedEdx)
{
    // return new holder(held);
    return new HolderClone((char*)self + 8);
}
