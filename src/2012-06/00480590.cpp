// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct String {
    unsigned char storage[28];
    __declspec(dllimport) String();
    __declspec(dllimport) ~String();
    __declspec(dllimport) const char* c_str() const;
};
struct P { String m_path; P(const String& s); void append(const char*); };
P::P(const String& s) { append(s.c_str()); }
