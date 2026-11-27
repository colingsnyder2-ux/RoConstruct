// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Vector3 { float x, y, z; };
struct Owner {
    char pad0[0x1b0];
    Vector3 value;
    Vector3 get() const;
};
Vector3 Owner::get() const
{
    return value;
}