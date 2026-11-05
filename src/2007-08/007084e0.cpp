// from server: 100% by colin
struct CHexHelper {
    int __thiscall invoke(int a, int b);
};

struct CXTColorHex {
    char pad[0x120];
    CHexHelper* helper;
    int method(int a, int b);
};

int CXTColorHex::method(int a, int b) {
    helper->invoke(a, 0);
    return 0;
}
