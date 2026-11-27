// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /arch:SSE /GS- /EHsc /MD
struct V3{float x,y,z;};
struct Sphere { virtual ~Sphere(); V3 c; float r; Sphere(const V3& cc, float rr); };
Sphere::Sphere(const V3& cc, float rr) : c(cc), r(rr) {}
