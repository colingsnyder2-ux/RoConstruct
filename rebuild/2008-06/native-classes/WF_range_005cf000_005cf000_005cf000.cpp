// native-flags: /O2 /GS- /EHsc /MD /fp:fast
inline const float& minimum(const float& a, const float& b)
{
    return b < a ? b : a;
}

inline const float& maximum(const float& a, const float& b)
{
    return a < b ? b : a;
}

// Stand-in layout: x0 @ +0, y0 @ +4, x1 @ +8, y1 @ +12 (matches the asm offsets).
struct DxUserInput
{
    float x0;
    float y0;
    float x1;
    float y1;

    void sub_005cf000(const DxUserInput& other);
};

void DxUserInput::sub_005cf000(const DxUserInput& other)
{
    x0 = minimum(x0, other.x0);
    y0 = minimum(y0, other.y0);
    x1 = maximum(x1, other.x1);
    y1 = maximum(y1, other.y1);
}
