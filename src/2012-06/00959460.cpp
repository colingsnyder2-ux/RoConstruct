// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Vector3 { float x, y, z; Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {} };
struct SnapInfo {
    int a; int b; int c;
    Vector3 v0; Vector3 v1;
    SnapInfo(const SnapInfo& o);
};
SnapInfo::SnapInfo(const SnapInfo& o) : a(o.a), b(o.b), c(o.c), v0(o.v0), v1(o.v1) {}
