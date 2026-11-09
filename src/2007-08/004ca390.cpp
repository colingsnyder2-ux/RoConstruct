// from server: 85% by colin
// roc 2007-08 004ca390  unit: seg_004c0000  size: 246 bytes

extern "C" {
    extern int g_8bf9b8;
}

struct Node {
    int field0;
    int field4;
    int field8;
};

struct Helper {
    bool checkA(int);
    bool checkB(int);
    bool checkC(int);
};

struct S {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int* method(int* out, Helper* h);
};

int* S::method(int* out, Helper* h) {
    g_8bf9b8 = this->field4;
    *out = 0;
    this->field8 = 3;
    if (this->fieldC == 0) {
        this->field8 = 0;
        g_8bf9b8 = 0;
        return &g_8bf9b8;
    }
    if (h->checkA(((Node*)g_8bf9b8)->field0)) {
        this->field8 = 3;
        return &g_8bf9b8;
    }
    for (;;) {
        if (h->checkB(((Node*)g_8bf9b8)->field0)) {
            *out = g_8bf9b8;
            this->field8 = 1;
            g_8bf9b8 = ((Node*)g_8bf9b8)->field4;
        } else if (h->checkC(((Node*)g_8bf9b8)->field0)) {
            *out = g_8bf9b8;
            this->field8 = 2;
            g_8bf9b8 = ((Node*)g_8bf9b8)->field8;
        }
        if (g_8bf9b8 == 0) {
            this->field8 = 0;
            g_8bf9b8 = 0;
            return &g_8bf9b8;
        }
        if (!h->checkA(((Node*)g_8bf9b8)->field0)) {
            continue;
        }
        return &g_8bf9b8;
    }
}
