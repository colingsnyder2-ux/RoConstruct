// from server: 100% by tajop
inline void* operator new(unsigned int, void* p) { return p; }

struct Head {
    int d[7];
};

struct Vec2 {
    float x;
    float y;
    Vec2(const Vec2& o) : x(o.x), y(o.y) {}
};

struct Vertex {
    Head head;
    Vec2 uv;
};

void __cdecl uninitFillN(Vertex* first, unsigned int count, const Vertex& val) {
    for (; 0 < count; --count, ++first) {
        new ((void*)first) Vertex(val);
    }
}
