// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace RBX {
class Math {
public:
    static inline double pi() { return 3.1415926535897932384626433832795; }
    static inline double twoPi() { return 6.283185307179586476925286766559; }
    static __forceinline float radWrap(float rad)
    {
        double r = rad;
        if (r >= -pi() && r < pi())
            return r;
        return r - floor((r + pi()) * (1 / twoPi())) * twoPi();
    }
    static unsigned char rotationToByte(float angle);
};
unsigned char rotationToByteBase(float angle);
unsigned char Math::rotationToByte(float angle)
{
    return rotationToByteBase(radWrap(angle));
}
}
