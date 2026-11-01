// from server: 100% by tester
extern "C" int (__stdcall *PostMessageA)(void* hWnd, unsigned int Msg, unsigned int wParam, int lParam);

struct HelpCommand {
    char pad[12];
    void* field_c;
    void method(int arg);
};

void HelpCommand::method(int arg) {
    void* p = field_c;
    void* h = *(void**)((char*)p + 0x20);
    PostMessageA(h, 0x111, 0x80fd, 0);
}
