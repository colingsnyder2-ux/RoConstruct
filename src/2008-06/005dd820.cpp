// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern bool __cdecl invalidFloat(float value);
extern bool __cdecl invalidComponent(float value);

struct Vector3 {
    float x;
    float y;
    float z;
};

inline bool isDenormal(float value)
{
    unsigned int bits = *reinterpret_cast<unsigned int*>(&value);
    return (bits & 0x7f800000u) == 0 &&
           (bits & 0x007fffffu) != 0;
}

#pragma float_control(precise, off, push)

inline bool invalidPair(float value)
{
    return invalidFloat(value) || isDenormal(value);
}

int __cdecl invalidVector(const Vector3& value)
{
    if (invalidPair(value.x) ||
        invalidPair(value.y) ||
        invalidComponent(value.z))
        return 1;
    return 0;
}

#pragma float_control(pop)
