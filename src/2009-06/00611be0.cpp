// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CF { float m[12]; };
struct VB { virtual CF getCoord() const = 0; };
struct Mid : virtual VB { virtual void m0(); int x[6]; };
struct Pad { virtual void p0(); int a[6]; };
struct I { virtual CF getLocation() const = 0; };
struct M : Pad, Mid, I {
    virtual CF getLocation() const;
};
CF M::getLocation() const { return getCoord(); }
