// from server: 100% by king_originala
struct Vector3
{
    bool isFinite() const;
    const float& operator[](int index) const;
};

extern double __cdecl absoluteValue(double value);
extern const double limit;

#pragma optimize("", off)

bool __cdecl checkVector(const Vector3& value)
{
    if (!value.isFinite())
        return false;

    for (int i = 0; i < 3; ++i)
    {
        if (absoluteValue(value[i]) > limit)
            return false;
    }

    return true;
}
