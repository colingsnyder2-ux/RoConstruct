// from server: 88% by atomic.potato
struct CList {
    char pad0[0x74];
    int field_74;
    void RemoveAt(int index);
};

struct Helper {
    int GetAt(int index);
};

struct Inner {
    int a;
    int b;
};

struct Outer {
    char pad0[0x14];
    Inner* inner;
};

extern "C" void sub_8dabe0(void* self, int a, int b);

void CList::RemoveAt(int index) {
    if (index == -1)
        return;
    Helper* h = (Helper*)&field_74;
    int* p = (int*)h->GetAt(index);
    int v = p[2];
    if (v == 0)
        return;
    Outer* o = (Outer*)v;
    Inner* in = o->inner;
    sub_8dabe0(this, in->a, in->b);
}
