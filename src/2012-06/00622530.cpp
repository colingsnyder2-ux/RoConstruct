// from server: 36% by Intel
struct WedgeBuilder {
    void build(int, int, int, int);
    void sub_621FE0(int, int, int, int);
    void sub_622010(int, int, int, int);
    void sub_622040(int, int, int, int);
    void sub_622080(int, int, int, int);
    void sub_6220B0(int, int, int, int);
    void sub_622500(int, int, int, int);
    void sub_61F290(int, int, int, int);
};

extern float g_b5abb8;
extern float g_b4c440;

void WedgeBuilder::build(int a, int b, int c, int d)
{
    switch (a) {
    case 0: {
        float val = g_b5abb8;
        sub_621FE0(c, *(int*)&val, 1, 1);
        break;
    }
    case 1: {
        float val = *(float*)d;
        sub_622010(c, 1, *(int*)&val, 1);
        break;
    }
    case 2: {
        sub_61F290(c, 1, 1, 0);
        sub_622040(0, 0, 0, 0);
        break;
    }
    case 3: {
        float val = g_b4c440;
        sub_622080(c, *(int*)&val, 1, 1);
        break;
    }
    case 4: {
        sub_61F290(c, 1, 1, 0);
        sub_6220B0(0, 0, 0, 0);
        break;
    }
    case 5: {
        float val = *(float*)d;
        sub_622500(c, 1, *(int*)&val, 1);
        break;
    }
    }
}
