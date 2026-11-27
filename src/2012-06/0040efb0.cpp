// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct E0 { virtual ~E0(); char pad[8]; };
struct E1 { virtual ~E1(); char pad[0x10]; };
struct T : E0, E1 { T(const T&); virtual ~T(); };
struct CloneBase { virtual ~CloneBase(); virtual void clone() const = 0; };
struct C : T, CloneBase {
    C(const T& o);
    virtual ~C();
    virtual void clone() const;
};
C::C(const T& o) : T(o) {}