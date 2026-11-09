// from server: 73% by colin
struct Inner {
    char pad[0xac];
    int field_ac;
};

struct Outer {
    char pad0[0x28];
    Inner** items;
    int count;
    char pad1[0xc];
    Outer* child;
    int method(int);
};

extern "C" int __stdcall sub_63052c(int);
extern "C" int __stdcall sub_67c5b0(int, int, int, int);
extern "C" void __cdecl sub_62ff20();

int Outer::method(int arg) {
    int v = sub_63052c((*(int***)this)[0][0]);
    int i = 0;
    if (count > 0) {
        do {
            Inner* p;
            if (i >= 0 && i < count) {
                if (i >= count) {
                    sub_62ff20();
                }
                p = items[i];
            } else {
                p = 0;
            }
            if (p->field_ac == 0) {
                Inner* q;
                if (i >= 0 && i < count) {
                    if (i >= count) {
                        sub_62ff20();
                    }
                    q = items[i];
                } else {
                    q = 0;
                }
                sub_67c5b0(v, (int)q, -1, arg);
            }
            i++;
        } while (i < count);
    }
    if (child != 0) {
        *(int*)(v + 0x3c) = child->method(arg);
    }
    return v;
}
