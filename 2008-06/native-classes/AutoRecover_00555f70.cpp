// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: operator new is really a 1-arg cdecl (only 0x28 is pushed).
extern "C" void* fn_006a0920(unsigned size);
extern "C" int __fastcall fn_00555f00(void* self, int unusedEdx, int a1);

// INFERRED: the real copy-constructor (fn_00555f00) is a true __thiscall member
// returning 'this'. It is declared here as a member so the compiler emits a
// plain thiscall (no edx setup) and reuses the returned eax as the result of
// the new-expression. The linker alias below ties it to the fn_ symbol.
#pragma comment(linker, "/alternatename:??0HolderClone@@QAE@PBX@Z=@fn_00555f00@12")

// INFERRED: layout of holder<boost::function<void(shared_ptr<Instance>)>>:
// vptr at 0, 'held' at +8, total size 0x28.
struct HolderClone
{
    char data[0x28];

    static void* operator new(unsigned size)
    {
        return fn_006a0920(size);
    }
    static void operator delete(void*) {}

    HolderClone(const void* heldSrc);   // defined elsewhere (fn_00555f00)
};

// holder::clone() const  ->  return new holder(held);
extern "C" HolderClone* __fastcall fn_00555f70(HolderClone* self, int unusedEdx)
{
    return new HolderClone((const char*)self + 8);
}
