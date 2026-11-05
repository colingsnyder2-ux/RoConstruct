// from server: 100% by colin
extern "C" int __stdcall SomeFunction(int, int, int);

struct CInstanceRecord {
    struct CNameItem {
        int f(int a, int b);
    };
};

int CInstanceRecord::CNameItem::f(int a, int b) {
    return SomeFunction(a, 0, 0);
}
