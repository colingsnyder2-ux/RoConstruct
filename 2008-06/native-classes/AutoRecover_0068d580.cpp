// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace Ogre { class Light; }

namespace std {
// INFERRED: VS2008 <algorithm> random-access _Rotate, defined here so the symbol is emitted
template<class _RanIt, class _Diff, class _Ty>
void _Rotate(_RanIt _First, _RanIt _Mid, _RanIt _Last, _Diff *, _Ty *)
{
    _Diff _Shift = _Mid - _First;
    _Diff _Count = _Last - _First;
    for (_Diff _Factor = _Shift; _Factor != 0; )
    {
        _Diff _Tmp = _Count % _Factor;
        _Count = _Factor;
        _Factor = _Tmp;
    }

    if (_Count < _Last - _First)
        for (; 0 < _Count; --_Count)
        {
            _RanIt _Hole = _First + _Count;
            _RanIt _Next = _Hole;
            _Ty _Holeval = *_Hole;
            _RanIt _Next1 = _Next + _Shift == _Last ? _First : _Next + _Shift;
            while (_Next1 != _Hole)
            {
                *_Next = *_Next1;
                _Next = _Next1;
                _Diff _Left = _Last - _Next1;
                _Next1 = _Shift < _Left ? _Next1 + _Shift : _First + (_Shift - _Left);
            }
            *_Next = _Holeval;
        }
}

template void _Rotate<Ogre::Light **, int, Ogre::Light *>(Ogre::Light **, Ogre::Light **, Ogre::Light **, int *, Ogre::Light **);
}
