// from server: 100% by colin
extern "C" int __stdcall sub_0063042a(int, int, int);

struct CInsertObjectDialog {
    int func_0041d620(int param);
};

int CInsertObjectDialog::func_0041d620(int param) {
    return sub_0063042a(param, 0x3e8, (int)((char*)this + 0x74));
}
