// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct Inner { bool operator==(const Inner& o) const; };
struct Outer {
    int a, b;
    Inner m;
    bool operator==(const Outer& o) const;
};
bool Outer::operator==(const Outer& o) const { return m == o.m; }
