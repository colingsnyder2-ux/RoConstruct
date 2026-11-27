// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct ConstraintSurfacePair;
struct W { void add(ConstraintSurfacePair*); };
struct V { char pad[0x1a8]; W* w; };
struct ConstraintSurfacePair {
    char padding[0x19];
    unsigned char field19;
    char padding2[2];
    V* field1C;
    void Update(V* value);
};
void ConstraintSurfacePair::Update(V* value)
{
    if (field1C == 0) {
        field1C = value;
        if (field19 == 0) {
            value->w->add(this);
            field19 = 1;
        }
    }
}
