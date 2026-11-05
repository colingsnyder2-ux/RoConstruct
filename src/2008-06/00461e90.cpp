// from server: 100% by tester
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);
struct Wnd { char pad[0x20]; void* hwnd; };
struct Dlg {
    char pad[0x19c];
    void* field_19c;
    void* method();
    Wnd* GetDlgItem(unsigned int id);
};
void* __stdcall getResult();
void* Dlg::method() {
    void* r = getResult();
    Wnd* w = GetDlgItem(0x412);
    SendMessageA(w->hwnd, 0xf1, (unsigned int)field_19c, 0);
    return r;
}
