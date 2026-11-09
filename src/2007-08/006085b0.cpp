// from server: 100% by colin
struct ClumpStage {
    void func_00608560();
    void func_006085b0(int);
};

struct Other {
    int func_005b4830();
    bool func_005b31d0();
    void func_005b3050(int);
    int func_005b2fc0();
};

struct Stage {
    int func_005a8fc0(int);
};

struct Target {
    void func_00604300(Other*);
};

void ClumpStage::func_006085b0(int a)
{
    func_00608560();
    Other* o = (Other*)a;
    int r = o->func_005b4830();
    Other* p = (Other*)r;
    bool b = p->func_005b31d0();
    p->func_005b3050(a);
    bool b2 = p->func_005b31d0();
    if (b != b2) {
        if (p->func_005b2fc0() != 0) {
            Stage* s = (Stage*)this;
            int x = s->func_005a8fc0(5);
            ((Target*)x)->func_00604300(p);
        }
    }
}
