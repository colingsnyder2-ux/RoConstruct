// from server: 54% by colin
struct WeldSelectionVerb {
    char pad[0x14];
    int field14;
    char pad2[0x20 - 0x18];
    int field20;
    bool method();
};

struct Helper562300 {
    int method(int);
};

struct Helper410D40 {
    int method();
};

bool WeldSelectionVerb::method() {
    Helper562300* h = (Helper562300*)&field14;
    int* a = (int*)h->method(1);
    int* v = (int*)((char*)a + 0x104);
    int count = v[1];
    if (count != 0) {
        return false;
    }
    int end = v[2];
    if (((end - count) >> 3) == 0) {
        return false;
    }
    int r;
    if (field20 != 0) {
        Helper410D40* h2 = (Helper410D40*)field20;
        r = h2->method();
    } else {
        r = 0;
    }
    int* v2 = (int*)((char*)r + 0x104);
    int c2 = v2[1];
    if (c2 == 0) {
        return false;
    }
    int e2 = v2[2];
    int n = (e2 - c2) >> 3;
    return n != 0;
}
