// from server: 100% by king_originala
struct Vector3i {
    int x, y, z;
};

struct Bounds {
    Vector3i first;
    Vector3i second;
};

Bounds __cdecl shiftBounds(int from, int to, const Bounds& source)
{
    int shift = to - from;

    Vector3i second;
    second.x = source.second.x >> shift;
    second.y = source.second.y >> shift;
    second.z = source.second.z >> shift;

    Vector3i first;
    first.x = source.first.x >> shift;
    first.y = source.first.y >> shift;
    first.z = source.first.z >> shift;

    Bounds result;
    result.first = first;
    result.second = second;
    return result;
}
