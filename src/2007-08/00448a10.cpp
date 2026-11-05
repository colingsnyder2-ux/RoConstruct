// from server: 50% by colin
struct CRbxDocTemplate {
    bool sub_4487B0(int*);
    bool func(int, int, int, int, int, int, int);
};

struct String {
    char data[28];
    String(const String&);
    ~String();
};

bool CRbxDocTemplate::func(int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
    String s = *(String*)&a1;
    bool result = sub_4487B0(&a1);
    return result;
}
