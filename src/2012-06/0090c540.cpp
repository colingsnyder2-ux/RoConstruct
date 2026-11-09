// from server: 27% by tajop
struct Vector3
{
    float x, y, z;
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    static const Vector3& unitX();
    static const Vector3& unitY();
};

struct Matrix3
{
    float elt[3][3];
    Vector3 operator*(const Vector3& v) const
    {
        Vector3 r;
        r.x = elt[0][0] * v.x + elt[0][1] * v.y + elt[0][2] * v.z;
        r.y = elt[1][0] * v.x + elt[1][1] * v.y + elt[1][2] * v.z;
        r.z = elt[2][0] * v.x + elt[2][1] * v.y + elt[2][2] * v.z;
        return r;
    }
};

struct CoordinateFrame
{
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame();
};

struct Face;

struct VertexData
{
    int pad;
    Vector3 pos;
};

struct Vertex
{
    const VertexData* getData(const Face* f, int i);
};

struct Edge
{
    Vertex* v0;
    Vertex* v1;
};

struct Face
{
    char pad0[8];
    Edge* edge;
    char pad1[12];
    Vector3 normal;
    char pad2[4];
    void getExtents(const Vector3& xAxis, const Vector3& yAxis, Vector3& hi, Vector3& lo, Vector3& center);
};

struct Mesh
{
    char pad[0x24];
    Face* facesBegin;
    Face* facesEnd;
};

Matrix3 getWellFormedRotForZVector(Vector3 v);
bool isZero(const float& f);

struct PyramidPoly
{
    char pad[0x14];
    Mesh* mesh;
    CoordinateFrame getSurfaceCoordInBody(unsigned int surfaceId) const;
};

CoordinateFrame PyramidPoly::getSurfaceCoordInBody(unsigned int surfaceId) const
{
    CoordinateFrame result;
    result.rotation = getWellFormedRotForZVector(mesh->facesBegin[surfaceId].normal);
    Vector3 hi;
    Vector3 lo;
    Vector3 center;
    Vector3 xAxis = result.rotation * Vector3::unitX();
    Vector3 yAxis = result.rotation * Vector3::unitY();
    float xs;
    float ys = 0.0f;
    if (surfaceId == (unsigned int)(mesh->facesEnd - mesh->facesBegin) - 1)
    {
        mesh->facesBegin[surfaceId].getExtents(xAxis, yAxis, hi, lo, center);
        result.translation = center;
        xs = xAxis.y * (hi.y - lo.y) + xAxis.z * (hi.z - lo.z) + xAxis.x * (hi.x - lo.x);
        xs = isZero(xs) ? 0.0f : 0.5f;
        ys = yAxis.y * (hi.y - lo.y) + yAxis.z * (hi.z - lo.z) + yAxis.x * (hi.x - lo.x);
        ys = isZero(ys) ? 0.0f : 0.5f;
    }
    else
    {
        mesh->facesBegin[(mesh->facesEnd - mesh->facesBegin) - 1].getExtents(xAxis, yAxis, hi, lo, center);
        const VertexData* a = mesh->facesBegin[surfaceId].edge->v1->getData(&mesh->facesBegin[surfaceId], 0);
        const VertexData* b = mesh->facesBegin[surfaceId].edge->v0->getData(&mesh->facesBegin[surfaceId], 0);
        result.translation.y = (a->pos.y + b->pos.y) * 0.5f;
        result.translation.x = (a->pos.x + b->pos.x) * 0.5f;
        result.translation.z = (a->pos.z + b->pos.z) * 0.5f;
        xs = xAxis.y * (hi.y - lo.y) + xAxis.z * (hi.z - lo.z) + xAxis.x * (hi.x - lo.x);
        xs = isZero(xs) ? 0.0f : 0.5f;
    }
    result.translation.x = xAxis.x * xs + yAxis.x * ys + result.translation.x;
    result.translation.y = xAxis.y * xs + yAxis.y * ys + result.translation.y;
    result.translation.z = xAxis.z * xs + yAxis.z * ys + result.translation.z;
    return result;
}
