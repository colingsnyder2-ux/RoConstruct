// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is an MSVC 2008 std::_Sort introsort loop on 4-byte elements.
// The disassembly pushes 3 args and pops them with add esp,0xc, so it is plain cdecl.

struct SortPair {
    int* first;
    int* second;
};

// _Unguarded_partition(pair* out, first, last)
extern "C" int fn_006789e0(SortPair* out, int* first, int* last);
// _Insertion_sort-like helper (first, last, 0)
extern "C" int fn_00678950(int* first, int* last, int zero);
// make_heap-like helper (first, last, 0, 0)
extern "C" int fn_00678910(int* first, int* last, int a3, int a4);
// sort_heap-like helper (first, last)
extern "C" int fn_00678d70(int* first, int* last);

extern "C" void fn_006791e0(int* first, int* last, int ideal)
{
    while ((last - first) > 32)
    {
        if (ideal <= 0)
        {
            if ((last - first) > 1)
                fn_00678910(first, last, 0, 0);
            fn_00678d70(first, last);
            return;
        }

        SortPair mid;
        fn_006789e0(&mid, first, last);

        ideal /= 2;
        ideal += ideal / 2;

        if ((mid.first - first) < (last - mid.second))
        {
            fn_006791e0(first, mid.first, ideal);
            first = mid.second;
        }
        else
        {
            fn_006791e0(mid.second, last, ideal);
            last = mid.first;
        }
    }

    if ((last - first) > 1)
        fn_00678950(first, last, 0);
}
