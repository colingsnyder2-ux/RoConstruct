// from server: 80% by atomic.potato
struct Value { int x; };

extern struct Desc0 { int pad[8]; } g_00a9db20;
extern int g_00a72858;
extern int g_00a9db20_flag;
extern int g_00cb40f0;

Value& sub_00592b40(void*);
Value& func_00482700();
void sub_00592ce0();
void sub_00401610(int, int);
void* sub_00401c90(void*);
void sub_0058d8f0(void*);

struct S {
    int f();
};

int S::f()
{
    *(int*)this = (int)&g_00a72858;
    if (g_00a9db20_flag == 0) {
        sub_00592ce0();
    } else {
        sub_00401610(0x482d50, 0xcb3f30);
        func_00482700();
    }
    void* p = sub_00401c90(&p);
    sub_0058d8f0(p);
    *(int*)p = (int)this;
    g_00cb40f0 = 0x29a;
    return (int)this;
}
