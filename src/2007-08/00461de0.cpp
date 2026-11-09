// from server: 100% by colin
struct CSelectionCaption {
    char pad[0x190];
    int field190;
    int method(int);
};

extern "C" int __stdcall sub_63023e();
extern "C" void __fastcall sub_41dba0(int*);

int CSelectionCaption::method(int arg) {
    int result = sub_63023e();
    if (result == -1) {
        return result;
    }
    sub_41dba0(&field190);
    return 0;
}
