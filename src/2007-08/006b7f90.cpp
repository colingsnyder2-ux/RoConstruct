// from server: 100% by colin
struct CXTPDefaultTheme {
    int sub_63CD70(int);
    int method(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

int CXTPDefaultTheme::method(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int result;
    if (a6 == 2) {
        if (a3 == 0) {
            result = 0x11;
        } else {
            result = 0xe;
            if (a1 == 0) {
                result = *(int*)((char*)this + 0x43c);
            }
        }
    } else {
        if (a7 == 5) {
            result = *(int*)((char*)this + 0x43c);
        } else {
            result = 0x12;
        }
        if (a3 == 0) {
            result = 0x11;
        }
    }
    return sub_63CD70(result);
}
