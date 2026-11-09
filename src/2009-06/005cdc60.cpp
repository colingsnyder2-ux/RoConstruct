// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str { char b[0x1c]; Str(const Str&); ~Str(); };
struct DescribedBase;
struct Inner { Str get(const DescribedBase* d) const; };
struct Outer {
    char pad[0xc];
    Inner inner;
    Str getStringValue(const DescribedBase* d) const;
};
Str Outer::getStringValue(const DescribedBase* d) const
{
    return inner.get(d);
}
