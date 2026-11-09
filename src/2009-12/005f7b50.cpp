// from server: 24% by atomic.potato
struct Vec3 {
    float x, y, z;
};

struct LineSeg {
    Vec3 p0;
    Vec3 p1;
    int closestPoint(const LineSeg* other, Vec3* result);
};

extern "C" {
    float __stdcall sqrtf_(float);
}

float g_9a6a88;
float g_9aea18;

Vec3* __stdcall helper_5f4d70();
void __stdcall helper_5f4ec0(float* out, float t, LineSeg* seg);

double g_b7cc08;
int g_b7cc10;
double* g_98b5b0;

int LineSeg::closestPoint(const LineSeg* other, Vec3* result) {
    float dx = p0.x - other->p0.x;
    float dy = p0.y - other->p0.y;
    float dz = p0.z - other->p0.z;
    float len = sqrtf_(dx*dy + dx*dy + dz*dz);
    float t;
    helper_5f4ec0(&t, len, this);
    float ox = other->p0.x;
    float oy = other->p0.y;
    float oz = other->p0.z;
    float ex = other->p1.x - ox;
    float ey = other->p1.y - oy;
    float ez = other->p1.z - oz;
    float a = ex*ex + ey*ey + ez*ez;
    float b = 2.0f * (ex*(p0.x - ox) + ey*(p0.y - oy) + ez*(p0.z - oz));
    float c = (p0.x - ox)*(p0.x - ox) + (p0.y - oy)*(p0.y - oy) + (p0.z - oz)*(p0.z - oz) - other->p1.x*other->p1.x;
    float disc = b*b - 4.0f*a*c;
    if (disc < 0.0f) {
        Vec3* v = helper_5f4d70();
        result->x = v->x;
        result->y = v->y;
        result->z = v->z;
        if (!(g_b7cc10 & 1)) {
            g_b7cc10 |= 1;
            g_b7cc08 = *g_98b5b0;
        }
        return 1;
    }
    float sq = sqrtf_(disc);
    float t1 = (-b + sq) / (2.0f * a);
    float t2 = (-b - sq) / (2.0f * a);
    float tt;
    if (t1 < 0.0f) {
        tt = 0.0f;
    } else if (t1 > 1.0f) {
        tt = 1.0f;
    } else {
        tt = t1;
    }
    result->x = ox + ex * tt;
    result->y = oy + ey * tt;
    result->z = oz + ez * tt;
    float rx = result->x - p0.x;
    float ry = result->y - p0.y;
    float rz = result->z - p0.z;
    float rl = sqrtf_(rx*rx + ry*ry + rz*rz);
    float inv = 1.0f / rl;
    result->x = rx * inv;
    result->y = ry * inv;
    result->z = rz * inv;
    return 0;
}
