// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::make_heap loop over 8-byte elements; callee is the adjust-heap helper, cdecl with 5 stack args (add esp,0x14).
struct HeapElem { int a; int b; };

extern "C" void fn_0067c780(HeapElem* first, int hole, int len, int a, int b);

extern "C" void fn_0067cae0(HeapElem* first, HeapElem* last)
{
    int len = (int)(last - first);
    int parent = len / 2;
    if (parent > 0) {
        do {
            --parent;
            fn_0067c780(first, parent, len, first[parent].a, first[parent].b);
        } while (parent > 0);
    }
}
