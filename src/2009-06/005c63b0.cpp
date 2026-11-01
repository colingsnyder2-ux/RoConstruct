// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
typedef unsigned int size_t;
struct Key;
struct Traits { size_t operator()(const Key& k) const; };
struct Hash {
    int pad0;
    Traits comp;
    char pad8[0x3c - 8];
    size_t _Mask;
    size_t _Maxidx;
    size_t _Hashval(const Key& _Keyval) const;
};
size_t Hash::_Hashval(const Key& _Keyval) const
{
    size_t _Num = comp(_Keyval) & _Mask;
    if (_Maxidx <= _Num)
        _Num -= (_Mask >> 1) + 1;
    return _Num;
}
