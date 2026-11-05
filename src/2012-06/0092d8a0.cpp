// from server: 62% by colin
struct Contact;

struct BuoyancyContact {
    char pad[0x2c];
    int field2c;
    int method(int, int);
};

extern "C" int __stdcall sub_895270(int, int*);
extern "C" int __stdcall sub_966440(int);

struct Other {
    int method(BuoyancyContact*, int, int);
};

extern "C" int __stdcall sub_92c7f0(BuoyancyContact*, int, int);

int BuoyancyContact::method(int a, int b)
{
    int local;
    int r = sub_895270(field2c, &local);
    r = sub_966440(r);
    sub_92c7f0(this, a, r);
    return a;
}
