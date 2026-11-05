// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
#include <math.h>
struct S { bool isZero(double x); };
bool S::isZero(double x)
{
    return fabs(x) < 1e-10;
}
