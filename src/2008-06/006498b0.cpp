// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

bool __cdecl testPoints(const Vector3* a, const Vector3* b, float radius)
{
    double radiusSquared = (double)radius * radius;
    int i = 0;
    do {
        int j = 0;
        do {
            double x = (double)a[i].x - b[j].x;
            double y = (double)a[i].y - b[j].y;
            double z = (double)a[i].z - b[j].z;
            double xx = x * x;
            if (xx + z * z + y * y < radiusSquared)
                goto nextPoint;
            ++j;
        } while (j < 4);
        return false;
nextPoint:
        ++i;
    } while (i < 4);
    return true;
}
