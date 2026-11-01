// from server: 41% by atomic.potato
struct String {
    void* pad[4];
    String(const char*);
    String(const String&);
    ~String();
    String& operator=(const String&);
};

struct Visitor {
    char pad0[4];
    void* end;
    char pad8[0x28];
    int field30;
    int field34;
};

struct Helper {
    char pad0[4];
    Visitor* end;
    void sub_929e90(int);
    void sub_929fa0(void*, int);
    void sub_92a9b0(int);
    void sub_92ab30(int);
    void sub_92ad30();
    void sub_9298b0();
    void sub_929700(void*);
    void sub_929660();
    bool sub_92b040(int, int);
};

extern "C" {
    void* __stdcall sub_a404c4(void*, const char*);
    void* __stdcall sub_a418e0(void*, int, void*);
    void* __stdcall sub_a418e4(void*);
    void* __stdcall sub_a404d0(void*);
    void* __stdcall sub_a404a8(void*, void*);
}

bool Helper::sub_92b040(int a, int b)
{
    int ebp = 0;
    int ebx = 0;
    Visitor* it;
    char buf[0x30];
    char buf2[0x30];
    bool flag;

    sub_929e90(a);
    ebp = (int)this;
    sub_929fa0(&it, a);
    ebx = b;

    if (it == end) {
        sub_92a9b0(a);
        *(int*)this = ebp;
        *(int*)((char*)this + 4) = ebx;
        return false;
    }

    if (it->field34 > ebx) {
        return false;
    }
    if (it->field34 == ebx && (unsigned)it->field30 >= (unsigned)ebp) {
        return false;
    }

    it->field30 = ebp;
    it->field34 = ebx;

    String tmp("time has evoluated ! reload the resourcegroup!");
    sub_a418e0(&tmp, 2, 0);
    sub_a418e4(0);
    sub_a404d0(&tmp);

    flag = *(bool*)((char*)this + 0x30);
    ebx = 2;

    if (flag) {
        sub_9298b0();
        sub_92ab30(a);
        sub_929700(buf2);
        sub_a404a8(buf, buf2);
        sub_a404d0(buf);
        sub_929660();
        sub_92ad30();
        return true;
    } else {
        sub_92ab30(a);
        sub_92ad30();
        return true;
    }
}
