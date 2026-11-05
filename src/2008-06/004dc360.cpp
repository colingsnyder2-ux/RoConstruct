// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct ViewG3D { float x, y, z; };
int __fastcall compare(const ViewG3D& a, const ViewG3D& b) {
    if (b.x < a.x) return -1;
    if (b.x > a.x) return 1;
    if (b.y < a.y) return -1;
    if (b.y > a.y) return 1;
    if (b.z < a.z) return -1;
    if (b.z > a.z) return 1;
    return 0;
}
