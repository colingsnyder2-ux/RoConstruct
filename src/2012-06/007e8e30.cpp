// from server: 100% by tajop

struct S_007e8e30 {
    S_007e8e30() : a(0), b(0) {}
    ~S_007e8e30();
    int a;
    int b;
};
extern int once_flag_007e8e30;
void init_007e8e00();
void call_once_004015a0(int& flag, void (*func)());
S_007e8e30* get_007e8e30()
{
    call_once_004015a0(once_flag_007e8e30, init_007e8e00);
    static S_007e8e30 instance;
    return &instance;
}
