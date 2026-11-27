// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Geometry;
struct Owner { void changed(Geometry* g); };
struct Geometry {
    char pad[0xe4];
    Owner* owner;
    char pad2[0x116-0xe8];
    bool flag;
    void setFlag(bool v);
};
void Geometry::setFlag(bool v) {
    if (v != flag) {
        flag = v;
        if (owner) owner->changed(this);
    }
}