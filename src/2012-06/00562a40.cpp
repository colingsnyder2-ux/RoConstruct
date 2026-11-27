// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A { char pad[0x2c]; };
struct B { int x; };
struct D : A, B { };
void G1_func_005622C0(B**);
struct Server { D* field_0; };
void func_00562A40(Server* s) {
    B* ptr = s->field_0;
    G1_func_005622C0(&ptr);
    s->field_0 = static_cast<D*>(ptr);
}
