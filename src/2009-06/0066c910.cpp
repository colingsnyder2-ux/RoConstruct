// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace G3D {
inline double pi() { return 3.1415926535897932384626433832795; }
inline double twoPi() { return 6.283185307179586476925286766559; }
}
namespace RBX {
class Math {
public:
    static inline double pi() { return G3D::pi(); }
    static inline double twoPi() { return G3D::twoPi(); }
    static double radWrap(double rad)
    {
        if (rad >= -pi() && rad < pi())
            return rad;
        double rot = 1 / twoPi();
        double f = floor((rad + pi()) * rot);
        return rad - f * twoPi();
    }
    static float angleDiff(float a, float b);
    static float angleAverage(float a, float b);
};
float Math::angleDiff(float a, float b)
{
    return (float)radWrap(a - b);
}
}
