// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
namespace Wml {
template<class Real> class ConvexHull2 {
public:
    class SortedVertex {
    public:
        Real x, y;
        int index;
        char pad[0x48 - 12];
        bool operator<(const SortedVertex& o) const;
    };
};
}
namespace std {
template<class _RanIt> void _Med3(_RanIt _First, _RanIt _Mid, _RanIt _Last);
template<class _RanIt> inline void _Median(_RanIt _First, _RanIt _Mid, _RanIt _Last)
{
    if (40 < _Last - _First)
    {
        int _Step = (_Last - _First + 1) / 8;
        _Med3(_First, _First + _Step, _First + 2 * _Step);
        _Med3(_Mid - _Step, _Mid, _Mid + _Step);
        _Med3(_Last - 2 * _Step, _Last - _Step, _Last);
        _Med3(_First + _Step, _Mid, _Last - _Step);
    }
    else
        _Med3(_First, _Mid, _Last);
}
}
template void std::_Median<Wml::ConvexHull2<float>::SortedVertex*>(Wml::ConvexHull2<float>::SortedVertex*, Wml::ConvexHull2<float>::SortedVertex*, Wml::ConvexHull2<float>::SortedVertex*);
