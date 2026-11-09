// from server: 100% by Viper
struct HeartbeatTask
{
    char pad[0x1e0];
    double field;
    int method(int a, int b);
};

extern "C" int __stdcall sub_79bdd0(int, int, double);

int HeartbeatTask::method(int a, int b)
{
    sub_79bdd0(a, b, field);
    return a;
}
