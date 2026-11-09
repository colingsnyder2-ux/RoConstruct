// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" double __cdecl floor(double);
namespace RBX {
class Math {
public:
    static double pi() { return 3.1415926535897932384626433832795; }
    static double twoPi() { return 6.283185307179586476925286766559; }
    static double radWrap(double rad);
};
double Math::radWrap(double rad)
{
    if (rad >= -pi() && rad < pi())
        return rad;
    double f = floor((rad + pi()) * (1 / twoPi()));
    return rad - f * twoPi();
}
}
