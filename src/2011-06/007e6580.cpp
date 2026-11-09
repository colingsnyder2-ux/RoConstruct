// from server: 18% by atomic.potato
struct AdvRotateTool {
    char pad0[4];
    float* p4;
    float* p8;
    bool f(float* pt);
};

bool AdvRotateTool::f(float* pt) {
    float* a = p4;
    float* b = p8;
    float ax = a[3];
    float bx = b[3];
    float ay = a[1];
    float px = pt[0];
    float by = b[1];
    float az = a[2];
    float py = pt[1];
    float bz = b[2];
    float dx = bx - ax;
    float dy = by - ay;
    float dz = bz - az;
    float ex = px - ay;
    float ey = py - az;
    float ez = pt[2] - ax;
    float t = ex * dy + ey * dz + ez * dx;
    if (t < 0.0f) return false;
    float u = (px - a[1]) * dy + (py - a[2]) * dz + (pt[2] - a[3]) * dx;
    if (u > 0.0f) return false;
    return true;
}
