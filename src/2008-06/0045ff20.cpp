// from server: 100% by colin
struct Text;
struct S;

extern int (__cdecl *atoiCall)(const char *);

struct Text {
    char *data;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
    __declspec(dllimport) int compare(const char *) const;
    __declspec(dllimport) const char *c_str() const;
};









struct VTable {
    void *slots[88];
    void (__thiscall *accept)(S *);
    void (__thiscall *reject)(S *);
};

struct S {
    VTable *vtable;
    void getProperty(const char *, long, Text *, int);
    void f(void *, short *);
};

void S::f(void *, short *cancel) {
    *cancel = -1;
    Text result;
    getProperty("DialogResult", (long)0x800113ed, &result, 1);
    if (result.compare("") != 0 && atoiCall(result.c_str()) == 1)
        vtable->accept(this);
    else
        vtable->reject(this);
}
