// from server: 47% by Intel
struct String {
    char _buf[28];
    String(const String&);
    ~String();
    void func(const String&);
};

struct Slot {
    char _pad[16];
    String str;
    Slot();
    ~Slot();
    void func(const String&);
};

extern "C" void __stdcall SEH_Prolog(int, int);
extern "C" void __stdcall SEH_Epilog(int);

void Slot::func(const String& arg) {
    SEH_Prolog(-1, 0xACA089);
    int sehFrame;
    String temp(arg);
    this->str.func(temp);
    SEH_Epilog(sehFrame);
}
