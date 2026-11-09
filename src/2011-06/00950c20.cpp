// from server: 26% by atomic.potato
struct Vec3s {
    short x;
    short y;
    short z;
};

struct Buf {
    short* data;
    int count;
    int cap;
    void reserve(int n, int zero);
};

void Buf::reserve(int n, int zero) {
    // placeholder; real body not needed for this match
}

struct Builder {
    Buf buf;
    void addTri(const Vec3s* a, const Vec3s* b, const Vec3s* c);
};

void Builder::addTri(const Vec3s* a, const Vec3s* b, const Vec3s* c) {
    short* base = buf.data;
    if ((const short*)a >= base && (const short*)a < base + buf.count) {
        Vec3s tmp;
        tmp.x = a->x;
        tmp.y = b->x;
        tmp.z = c->x;
        addTri(&tmp, &tmp, &tmp);
        return;
    }
    if ((const short*)b >= base && (const short*)b < base + buf.count) {
        Vec3s tmp;
        tmp.x = a->x;
        tmp.y = b->x;
        tmp.z = c->x;
        addTri(&tmp, &tmp, &tmp);
        return;
    }
    if ((const short*)c >= base && (const short*)c < base + buf.count) {
        Vec3s tmp;
        tmp.x = a->x;
        tmp.y = b->x;
        tmp.z = c->x;
        addTri(&tmp, &tmp, &tmp);
        return;
    }
    if (buf.count + 2 < buf.cap) {
        short* p = buf.data + buf.count;
        if (p) {
            p[0] = a->x;
        }
        p = buf.data + buf.count + 1;
        if (p) {
            p[0] = b->x;
        }
        p = buf.data + buf.count + 2;
        if (p) {
            p[0] = c->x;
        }
        buf.count += 3;
        return;
    }
    buf.reserve(buf.count + 3, 0);
    buf.data[buf.count - 3] = a->x;
    buf.data[buf.count - 2] = b->x;
    buf.data[buf.count - 1] = c->x;
}
