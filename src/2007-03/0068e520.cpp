// from server: 100% by tester
struct CXTPRibbonTheme {
    char pad[0x2c];
    int* field_2c;
    int get(int);
};

int CXTPRibbonTheme::get(int)
{
    return *(int*)((char*)field_2c + 0x62c) + 1;
}