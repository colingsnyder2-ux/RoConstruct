// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
template<class C> class BasicString {
public:
    __declspec(noinline) BasicString& operator+=(const C* s) { p = s; return *this; }
    __declspec(noinline) const C* c_str() const { return p; }
private:
    const C* p;
    char buf[0x18];
};
extern template class __declspec(dllimport) BasicString<char>;
typedef BasicString<char> String;

struct Parameter { String name; };

void __cdecl appendParameter(int* count, String* text, Parameter*& parameter)
{
    if (*count > 0)
        *text += ", ";
    *text += parameter->name.c_str();
    ++*count;
}
