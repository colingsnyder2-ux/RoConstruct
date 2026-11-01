// from server: 46% by atomic.potato
struct Sub {
    char pad0[0x44];
    Sub* field44;
    int method();
};

struct Obj {
    char pad0[0x44];
    Sub* field44;
    int f();
};

extern "C" int __cdecl sub_630760();
extern "C" int __cdecl sub_640b40(Obj*);
extern "C" Sub* __cdecl sub_67fd30(Sub*);
extern "C" int __cdecl sub_48d4d0(Sub*);
extern "C" int __cdecl sub_80b2ea(int, int, int, int, int);
extern "C" int __cdecl sub_6496a0(Obj*, int, int);

int Obj::f()
{
    int edi;
    if (sub_630760() == 0) {
        edi = 0;
    } else if (sub_640b40(this) == 0) {
        edi = 1;
    } else {
        Sub* p = sub_67fd30(field44);
        if (p == 0) {
            edi = 2;
        } else {
            int r = p->method();
            edi = (r == 0) ? 4 : 0;
        }
    }

    int eax;
    if (this != 0) {
        Sub* p = field44;
        if (p != 0) {
            Sub* q = p->field44;
            if (q != 0) {
                sub_48d4d0(q);
                eax = (int)q;
            } else {
                eax = (int)p;
            }
        } else {
            eax = (int)this;
        }
    } else {
        eax = 0;
    }

    if (eax != 0) {
        if (sub_80b2ea(eax, 0, 0xc071f8, 0xc0c3e0, 0) != 0) {
            return sub_6496a0(this, edi, eax);
        }
    }
    return sub_6496a0(this, edi, 0);
}
