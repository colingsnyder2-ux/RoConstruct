// from server: 100% by Intel
struct G3D {
    struct VVector3 {
        struct TypedPropertyDescriptor {
            int f() const;
        };
    };
};

int G3D::VVector3::TypedPropertyDescriptor::f() const {
    return (int)((char*)this - 0x3ec);
}
