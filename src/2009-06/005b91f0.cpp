// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct Impl { Impl& put(int v); };
struct Stream {
    Impl* impl;
    Impl* get();
    Stream& operator<<(int v);
};
Stream& Stream::operator<<(int v)
{
    get()->put(v);
    return *this;
}
