// from server: 81% by king_originala
struct Vector3 {
    float x, y, z;
};

extern float source;
extern float middle;
extern volatile Vector3 result;

Vector3* getVector(Vector3* out)
{
    double value = source;
    result.x = (float)value;
    result.y = middle;
    result.z = (float)value;
    out->x = result.x;
    out->y = result.y;
    out->z = result.z;
    return out;
}
