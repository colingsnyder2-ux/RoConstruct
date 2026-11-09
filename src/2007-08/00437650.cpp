// from server: 53% by colin
struct StandardOutMessage {
    int type;
    char pad[0x28];
};

struct StandardOut {
    char pad0[0x18];
    void* sync;
    void print(int type, const StandardOutMessage& msg);
};

extern "C" {
    void __stdcall LeaveCriticalSection(void*);
    void __stdcall sub_77E69C(void*, const void*);
    void __stdcall sub_77E6AC(void*);
    void __stdcall sub_77D2F8(void*);
}

void __stdcall sub_41D870(void*, const void*);

void StandardOut::print(int type, const StandardOutMessage& msg)
{
    char buf[0x0c];
    *(void**)(buf) = (char*)this->sync + 0x2c;
    buf[4] = 0;
    sub_41D870(buf, &msg);

    char local[0x28];
    *(int*)(local) = type;
    sub_77E69C(local + 4, &msg);
    *(int*)(local + 0x20) = *(int*)((char*)&msg + 0x20);
    *(int*)(local + 0x24) = *(int*)((char*)&msg + 0x24);

    void (StandardOut::*fn)(int, const StandardOutMessage&) = *(void (StandardOut::**)(int, const StandardOutMessage&))((char*)this + 0x0c);
    (this->*fn)(type, msg);

    if (buf[4]) {
        LeaveCriticalSection(*(void**)buf);
    }
    sub_77E6AC(buf + 0x18);
}
