// from server: 31% by atomic.potato
struct S_func_0065c610 {
    char pad0[280];
    int m_x;
    int f();
};

struct S_func_0067e3a0 {
    char pad0[0x118];
    int m_x;
    int f();
};

struct S_func_0065c250 {
    int f();
};

struct S_func_004e0bf0 {
    int f();
};

extern "C" int __stdcall sub_89e444(int, int);
extern "C" int __stdcall sub_89e4c4(int);

struct ServerReplicator {
    char pad0[0x2ef8];
    char field_2ef8[4];
    int method(int);
};

int ServerReplicator::method(int arg)
{
    int local0 = 0;
    char local1 = 0;
    int local2 = -1;
    int result = 0;
    bool same = false;
    int a = ((S_func_0067e3a0*)((char*)this + 0x118))->f();
    int b = ((S_func_0065c250*)a)->f();
    same = (b == arg);
    int c = ((S_func_004e0bf0*)((char*)this + 0x2ef8))->f();
    int d = ((S_func_0065c610*)b)->f();
    char e = (char)sub_89e444(d, c);
    local1 = e;
    local2 = -1;
    sub_89e4c4((int)&local0);
    if (same && local1 != 0)
        result = 1;
    return result;
}
