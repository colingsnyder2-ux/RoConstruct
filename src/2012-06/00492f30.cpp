// from server: 52% by atomic.potato
struct HelpCommand {
    char pad[0x1dc];
    void* field_1dc;
    void method();
};

extern "C" void __stdcall SendMessageA(void*, unsigned int, unsigned int, unsigned int);

void sub_492DF0(void*);

void HelpCommand::method() {
    void* p = this->field_1dc;
    if (p != 0) {
        char buf[8];
        sub_492DF0(buf);
        typedef void (__thiscall *Fn)(void*, void*);
        Fn fn = (Fn)0x418070;
        fn(p, buf);
        void* hwnd = *(void**)((char*)p + 0x20);
        SendMessageA(hwnd, 0x364, 0, 0);
    }
}
