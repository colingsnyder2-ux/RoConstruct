// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <string>
namespace G3D {
class Vector2 { public: float x, y; Vector2() {} Vector2(float _x, float _y) : x(_x), y(_y) {} };
class GFont {
public:
    enum Spacing { PROPORTIONAL_SPACING, FIXED_SPACING };
    void* vptr_;
    int refCount;
    void* texture;
    int subWidth[128];
    int charWidth;
    int charHeight;
    Vector2 computePackedArray(const std::string& s, double x, double y, double w, double h, Spacing spacing, Vector2* array, int maxChars) const;
};

Vector2 GFont::computePackedArray(
    const std::string&  s,
    double              x,
    double              y,
    double              w,
    double              h,
    Spacing             spacing,
    Vector2*            array,
    int                 maxChars) const {

    const double propW = w / charWidth;
    const int n = s.length();

    float sy = h / charHeight;

    const float mwidth = subWidth[(int)'M'] * 0.85f * propW;

    int count = -1;
    for (int i = 0; i < n; ++i) {
        if (maxChars == 0) break;
        char c = s[i] & 127;

        if (c != ' ') {
            --maxChars;
            int row   = c >> 4;
            int col   = c & 15;

            float sx = (spacing == PROPORTIONAL_SPACING) ?
                (charWidth - subWidth[(int)c]) * propW * 0.5f : 0.0f;

            float xx = x - sx;
            ++count;
            array[count].x = col * charWidth;
            array[count].y = row * charHeight + 1;

            ++count;
            array[count].x = xx;
            array[count].y = y + sy;

            ++count;
            array[count].x = col * charWidth;
            array[count].y = (row + 1) * charHeight - 2;

            ++count;
            array[count].x = xx;
            array[count].y = y + h - sy;

            xx += w;
            ++count;
            array[count].x = (col + 1) * charWidth - 1;
            array[count].y = (row + 1) * charHeight - 2;

            ++count;
            array[count].x = xx;
            array[count].y = y + h - sy;

            ++count;
            array[count].x = (col + 1) * charWidth - 1;
            array[count].y = row * charHeight + 1;

            ++count;
            array[count].x = xx;
            array[count].y = y + sy;
        }

        x += (spacing == PROPORTIONAL_SPACING) ?
            propW * subWidth[(int)c] : mwidth;
    }

    return Vector2(x, h);
}
}
