// from server: 100% by EspClaude
// roc 2008-06 00549050  unit: seg_00540000  size: 900 bytes
// roc-flags: /Od /GS /EHsc /MD

struct Vector3 {
    float x, y, z;
    Vector3();
};
struct Plane {
    double distance(const struct Point2& p) const;
};
struct Point2 {
    float a, b, c;
    Point2();
};
struct Frame {
    Point2 project(int b) const;
    Vector3 toWorld(const Vector3& v) const;
};
struct Tri { int a, b, c; };
struct Edge { int a, b, c, d; };

template <class T> struct Array {
    T* data; int num; int cap;
    int size() const;
    T& operator[](int i);
    void append(const T& a, const T& b);
    void append(const T& a, const T& b, const T& c);
};
struct BoolArray {
    BoolArray();
    ~BoolArray();
    void resize(int n, bool v);
    int size() const;
    bool& operator[](int i);
};

class Mesh {
public:
    char pad[0x18];
    Array<Edge> edges;
    Array<Plane> planes;
    Array<Tri> tris;
    Array<Vector3> verts;
    void build(const Frame& frame, int b, Array<unsigned int>& indices, Array<Vector3>& outVerts, bool caps);
};

void Mesh::build(const Frame& frame, int b, Array<unsigned int>& indices, Array<Vector3>& outVerts, bool caps)
{
    Point2 p = frame.project(b);
    static BoolArray front;
    front.resize(planes.size(), false);
    for (int i = 0; i < planes.size(); i++) {
        front[i] = planes[i].distance(p) < 0.0;
    }
    if (caps) {
        for (int j = 0; j < front.size(); j++) {
            if (!front[j]) {
                int n = outVerts.size();
                indices.append(n, n + 1, n + 2);
                const Vector3* v0;
                const Tri* t;
                const Vector3* v1;
                const Vector3* v2;
                t = &tris[j];
                v0 = &verts[t->a];
                v1 = &verts[t->b];
                v2 = &verts[t->c];
                outVerts.append(frame.toWorld(*v0), frame.toWorld(*v1), frame.toWorld(*v2));
            }
        }
    }
    for (int k = 0; k < edges.size(); k++) {
        bool f0;
        bool f1;
        const Edge* e;
        e = &edges[k];
        do {} while (0);
        do {} while (0);
        f0 = front[e->c];
        f1 = front[e->d];
        if (f0 != f1) {
            const Vector3& w = verts[e->a];
            const Vector3& q = verts[e->b];
            Vector3 u = frame.toWorld(w);
            Vector3 v = frame.toWorld(q);
            int y = outVerts.size();
            outVerts.append(u, v);
            unsigned int f, n;
            if (f0) {
                f = y;
                n = y + 1;
            } else {
                f = y + 1;
                n = y;
            }
            indices.append(f, n, 0);
        }
    }
}
