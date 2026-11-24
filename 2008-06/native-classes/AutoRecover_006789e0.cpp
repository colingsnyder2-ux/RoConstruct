// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the original unit was built with fast floating-point semantics
// (fcomp against memory, swaps without a stack temporary). These pragmas
// give /fp:fast behaviour for this file.
#pragma float_control(except, off)
#pragma float_control(precise, off)
#include <algorithm>
#include <utility>

// INFERRED: func_00678880 is std::_Median(first, mid, last) on float*; the
// 7-arg signature in the prompt is replaced by the 3 args the call site pushes.
extern "C" int fn_00678880(float* a, float* b, float* c);

// INFERRED: this is VS2008 std::_Unguarded_partition<float*>. The pair is
// returned through a hidden first pointer argument (out), then _First, _Last.
extern "C" void fn_006789e0(std::pair<float*, float*>* out, float* _First, float* _Last)
{
    float* _Mid = _First + (_Last - _First) / 2;
    fn_00678880(_First, _Mid, _Last - 1);
    float* _Pfirst = _Mid;
    float* _Plast = _Pfirst + 1;

    while (_First < _Pfirst
        && !(*(_Pfirst - 1) < *_Pfirst)
        && !(*_Pfirst < *(_Pfirst - 1)))
        --_Pfirst;
    while (_Plast < _Last
        && !(*_Plast < *_Pfirst)
        && !(*_Pfirst < *_Plast))
        ++_Plast;

    float* _Gfirst = _Plast;
    float* _Glast = _Pfirst;

    for (;;)
    {
        for (; _Gfirst < _Last; ++_Gfirst)
        {
            if (*_Pfirst < *_Gfirst)
                ;
            else if (*_Gfirst < *_Pfirst)
                break;
            else
                std::iter_swap(_Plast++, _Gfirst);
        }
        for (; _First < _Glast; --_Glast)
        {
            if (*(_Glast - 1) < *_Pfirst)
                ;
            else if (*_Pfirst < *(_Glast - 1))
                break;
            else
                std::iter_swap(--_Pfirst, _Glast - 1);
        }
        if (_Glast == _First && _Gfirst == _Last)
        {
            out->first = _Pfirst;
            out->second = _Plast;
            return;
        }

        if (_Glast == _First)
        {
            if (_Plast != _Gfirst)
                std::iter_swap(_Pfirst, _Plast);
            ++_Plast;
            std::iter_swap(_Pfirst++, _Gfirst++);
        }
        else if (_Gfirst == _Last)
        {
            if (--_Glast != --_Pfirst)
                std::iter_swap(_Glast, _Pfirst);
            std::iter_swap(_Pfirst, --_Plast);
        }
        else
            std::iter_swap(_Gfirst++, --_Glast);
    }
}
