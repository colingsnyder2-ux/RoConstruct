// from server: 84% by EspClaude
// roc 2007-08 004ca520 (see base for target disassembly)
// Target copies a 12-byte argument by value (sub esp,0xc; mov eax,esp; 3 dword stores),
// then calls vtable slot +0x18 (index 6) twice via ecx=this.

struct Arg12 {
    float a;
    float b;
    float c;
    Arg12(const Arg12& o) : a(o.a), b(o.b), c(o.c) {}
};

class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Object* v6();
};

Object* __stdcall sub_4CA490(Arg12 a);

Object* __stdcall sub_4CA520(Arg12 a)
{
    Object* obj = sub_4CA490(a);
    if (obj) {
        if (obj->v6())
            return obj->v6();
        return obj;
    }
    return 0;
}
