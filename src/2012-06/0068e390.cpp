// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Vector3 { float x, y, z; Vector3 &operator=(const Vector3 &o) { x = o.x; y = o.y; z = o.z; return *this; } };
struct Matrix3 { float m[3][3]; };
struct CoordinateFrame { Matrix3 rotation; Vector3 translation; };
struct ICameraSubject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual CoordinateFrame getLocation();
    virtual void stepGoalAndFocus(CoordinateFrame &goal, CoordinateFrame &focus, bool a, int b);
};
void ICameraSubject::stepGoalAndFocus(CoordinateFrame &goal, CoordinateFrame &focus, bool a, int b)
{
    focus = getLocation();
}