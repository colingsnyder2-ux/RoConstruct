// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::for_each over vector<EdgePlus> (0x28-byte elements), checked iterators (8 bytes), 8-byte functor returned by value
struct EdgeIter { void* proxy; char* ptr; };
struct EdgeFunc { int a; int b; };

extern "C" char* fn_005534c0(EdgeIter* it);
extern "C" int __fastcall fn_005534e0(void* self, int unusedEdx, int a1);

extern "C" EdgeFunc fn_00553380(EdgeIter first, EdgeIter last, EdgeFunc func)
{
    char* p = fn_005534c0(&first);
    char* e = fn_005534c0(&last);
    for (; p != e; p += 0x28)
        fn_005534e0(&func, 0, (int)p);
    return func;
}
