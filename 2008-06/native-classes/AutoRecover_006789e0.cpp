// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <utility>
#include <algorithm>

extern "C" void fn_00678880(float* a, float* b, float* c);

// INFERRED: MSVC 2008 std::_Partition<float*, std::less<float>> (introsort partition), median helper is fn_00678880
std::pair<float*, float*> fn_006789e0(float* first, float* last)
{
    float* mid = first + (last - first) / 2;
    fn_00678880(first, mid, last - 1);
    float* pfirst = mid;
    float* plast = pfirst + 1;
    while (first < pfirst && !(*pfirst < *(pfirst - 1)) && !(*(pfirst - 1) < *pfirst))
        --pfirst;
    while (plast < last && !(*pfirst < *plast) && !(*plast < *pfirst))
        ++plast;

    float* gfirst = plast;
    float* glast = pfirst;
    for (;;)
    {
        for (; gfirst < last; ++gfirst)
        {
            if (*pfirst < *gfirst)
                continue;
            if (*gfirst < *pfirst)
                break;
            if (plast != gfirst)
                std::iter_swap(plast, gfirst);
            ++plast;
        }
        for (; first < glast; --glast)
        {
            if (*(glast - 1) < *pfirst)
                continue;
            if (*pfirst < *(glast - 1))
                break;
            --pfirst;
            if (glast - 1 != pfirst)
                std::iter_swap(glast - 1, pfirst);
        }
        if (glast == first && gfirst == last)
            return std::pair<float*, float*>(pfirst, plast);
        if (glast == first)
        {
            if (plast != gfirst)
                std::iter_swap(pfirst, plast);
            ++plast;
            std::iter_swap(pfirst, gfirst);
            ++pfirst;
            ++gfirst;
        }
        else if (gfirst == last)
        {
            --glast;
            --pfirst;
            if (glast != pfirst)
                std::iter_swap(glast, pfirst);
            --plast;
            std::iter_swap(pfirst, plast);
        }
        else
        {
            --glast;
            std::iter_swap(gfirst, glast);
            ++gfirst;
        }
    }
}
