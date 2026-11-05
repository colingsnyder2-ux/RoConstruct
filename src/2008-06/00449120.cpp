// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <algorithm>

extern int G_942df8;
extern char G_96d4b8;

struct CRenderSettings {
    void notifyChange(const void*);
    void setValue(int);
};
void CRenderSettings::setValue(int a)
{
    int lo = 1;
    int hi = 1000;
    int val = std::min(hi, std::max(lo, a));
    if (val != G_942df8) {
        G_942df8 = val;
        notifyChange(&G_96d4b8);
    }
}
