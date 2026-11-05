// from server: 100% by colin
struct RunService {
    char pad[0x118];
    char field_118[0x18];
    char field_130[0x1c];
    int field_14c;
    void sub_52d490(int);
    void sub_52d3f0(int, int);
    void setState(int);
};

void RunService::setState(int v)
{
    if (v == 1) {
        if (field_14c != 0 && field_14c != 2)
            return;
    } else if (v == 2) {
        if (field_14c != 1)
            return;
    }

    int old = field_14c;
    if (old == v)
        return;

    field_14c = v;
    ((RunService*)((char*)this + 0x130))->sub_52d490(v);
    ((RunService*)((char*)this + 0x118))->sub_52d3f0(old, v);
}
