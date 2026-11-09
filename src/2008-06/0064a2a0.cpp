// from server: 43% by king_originala
extern "C" double __cdecl fabs(double);

struct Vector3
{
    float x, y, z;
};

struct Plane
{
    Vector3 normal;
    float offset;
    float limit;
};

bool __cdecl testPlanes(const Plane* planes, const Vector3* points)
{
    for (int i = 0; i < 2; ++i)
    {
        const double x = planes[i].normal.x;
        const double y = planes[i].normal.y;
        const double z = planes[i].normal.z;
        const double offset = planes[i].offset;
        const double limit = planes[i].limit;

        for (int j = 0; j < 4; ++j)
        {
            if (fabs(points[j].z * z +
                     points[j].y * y +
                     points[j].x * x + offset) > limit)
                return false;
        }
    }
    return true;
}
