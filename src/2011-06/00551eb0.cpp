// from server: 35% by atomic.potato
struct Vec3 {
    float x, y, z;
};

struct Sphere {
    float cx, cy, cz;
    float ex, ey, ez;
    float pad18;
    float pad1c;
    float pad20;
    int type;
    float m28, m2c, m30, m34, m38, m3c, m40, m44, m48, m4c, m50, m54;
    int classify(Vec3* center, Vec3* extent);
};

extern "C" float* __cdecl G3D_getUnitVector();

int Sphere::classify(Vec3* center, Vec3* extent) {
    cx = center->x;
    cy = center->y;
    cz = center->z;
    ex = extent->x;
    ey = extent->y;
    ez = extent->z;

    float* u = G3D_getUnitVector();
    float ux = u[0] / extent->x;
    float uy = u[1] / extent->y;
    float uz = u[2] / extent->z;

    pad20 = uz;
    pad18 = ux;
    pad1c = uy;

    float a = ey * ux;
    float b = ez * uy;
    float c = ez * ux;
    float d = ez * uy;
    float e = ex * uz;
    float f = ey * uz;
    float g = ex * uy;
    float h = ex * ux;

    m38 = ez * ex;
    m2c = ey * ux;
    m3c = ey * uz;
    m40 = cy - cx * m2c;
    m28 = ex * uy;
    m44 = cz - cx * m3c;
    m48 = cx - cy * m28;
    m30 = ey * uy;
    m4c = cz - cy * m30;
    m34 = ez * ey;
    m50 = cx - cz * m38;
    m54 = cy - cz * m34;

    float zero = 0.0f;
    float vx = ex;
    float vy = ey;
    float vz = ez;

    if (zero > vx) {
        if (zero > vy) {
            if (zero > vz) {
                type = 0;
                return type;
            }
            if (vz > zero) {
                type = 1;
                return type;
            }
            type = 0x16;
            return type;
        }
        if (zero > vz) {
            if (vy == zero) {
                type = 0x12;
                return type;
            }
            type = 2;
            return type;
        }
        if (vy == zero && vz == zero) {
            type = 9;
            return type;
        }
        if (vz == zero) {
            type = 0x17;
            return type;
        }
        if (vy == zero) {
            type = 0x13;
            return type;
        }
        type = 3;
        return type;
    }

    if (zero > vy) {
        if (zero > vz) {
            if (vx == zero) {
                type = 0xe;
                return type;
            }
            type = 4;
            return type;
        }
        if (vx == zero && vz == zero) {
            type = 0xb;
            return type;
        }
        if (vz == zero) {
            type = 0x18;
            return type;
        }
        if (vx == zero) {
            type = 0xf;
            return type;
        }
        type = 5;
        return type;
    }

    if (zero > vz) {
        if (vx == zero && vy == zero) {
            type = 0xd;
            return type;
        }
        if (vx == zero) {
            type = 0x10;
            return type;
        }
        if (vy == zero) {
            type = 0x14;
            return type;
        }
        type = 6;
        return type;
    }

    if (vx == zero) {
        if (vy == zero) {
            type = 0xc;
            return type;
        }
        if (vz == zero) {
            type = 0xa;
            return type;
        }
        type = 0x11;
        return type;
    }

    if (vy == zero) {
        if (vz == zero) {
            type = 8;
            return type;
        }
        type = 0x15;
        return type;
    }

    if (vz == zero) {
        type = 0x19;
        return type;
    }

    type = 7;
    return type;
}
