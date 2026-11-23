// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <algorithm>

// INFERRED: 8-byte element ordered by the float at +4 (fld dword [e+4]); the
// callee name says double*, but the compares are 32-bit float loads.
struct Elem {
    int a;
    float key;
};

struct ElemPair {
    Elem* first;
    Elem* second;
};

static inline bool lessE(const Elem& x, const Elem& y) { return x.key < y.key; }

extern "C" void fn_0067ca50(Elem* a, Elem* b, Elem* c); // ?$_Median@PAN@std@@YAXPAN00@Z

// std::_Unguarded_partition(first, last) with hidden pair return (cdecl).
extern "C" ElemPair fn_0067cc00(Elem* first, Elem* last)
{
    Elem* mid = first + (last - first) / 2;
    fn_0067ca50(first, mid, last - 1);

    Elem* pfirst = mid;
    Elem* plast = pfirst + 1;

    while (first < pfirst && !lessE(*(pfirst - 1), *mid) && !lessE(*mid, *(pfirst - 1)))
        --pfirst;
    while (plast < last && !lessE(*plast, *mid) && !lessE(*mid, *plast))
        ++plast;

    Elem* gfirst = plast;
    Elem* glast = pfirst;

    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (lessE(*mid, *gfirst))
                continue;
            if (lessE(*gfirst, *mid))
                break;
            std::iter_swap(plast, gfirst);
            ++plast;
        }
        for (; first < glast; --glast) {
            if (lessE(*(glast - 1), *mid))
                continue;
            if (lessE(*mid, *(glast - 1)))
                break;
            --pfirst;
            std::iter_swap(pfirst, glast - 1);
        }
        if (glast == first && gfirst == last) {
            ElemPair r = { pfirst, plast };
            return r;
        }
        if (glast == first) {
            if (plast != gfirst)
                std::iter_swap(pfirst, plast);
            ++plast;
            std::iter_swap(pfirst, gfirst);
            ++pfirst;
            ++gfirst;
        } else if (gfirst == last) {
            --glast;
            --pfirst;
            std::iter_swap(glast, pfirst);
            std::iter_swap(pfirst, --plast);
        } else {
            std::iter_swap(gfirst, --glast);
            ++gfirst;
        }
    }
}
