// from server: 85% by tajop
struct locale {
    int p;
    ~locale();
    static const locale& classic();
};
struct string {
    int d[7];
    ~string();
};
struct ios_base {
    char pad0[0x30];
};
struct ios : ios_base {
    char _Fill;
    char pad1[0x17];
    ~ios() {}
    locale imbue(const locale& l);
    char fill(char c) { char o = _Fill; _Fill = c; return o; }
};
struct ostream : virtual ios {
    ostream& operator<<(__int64 v);
};
struct ostringstream : ostream {
    char pad2[0x34];
    ostringstream(int mode);
    ~ostringstream();
    string str() const;
};
struct Smanip {
    void (__cdecl *fn)(ios_base&, int);
    int arg;
    Smanip(void (__cdecl *f)(ios_base&, int), int a);
};
struct Fillobj {
    char c;
    Fillobj(char v) : c(v) {}
};
Smanip setw(int w);
inline ostream& operator<<(ostream& o, const Smanip& m) {
    (*m.fn)(o, m.arg);
    return o;
}
inline ostream& operator<<(ostream& o, const Fillobj& f) {
    o.fill(f.c);
    return o;
}

string formatPadded(__int64 value, int width) {
    ostringstream ss(2);
    ss.imbue(locale::classic());
    ss << setw(width) << Fillobj('0') << value;
    return ss.str();
}
