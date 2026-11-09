// from server: 5% by colin
struct RBX_ClumpStage {
    void sub_606700(int);
    void sub_6055C0(int);
    void sub_605670(int);
    void sub_605A10(int);
    void sub_605C80(int);
    int sub_60B230();
    int sub_60B200(int);
    int sub_60BF00(int);
    int sub_60C0D0();
    int sub_60C1C0(int, int);
};

struct RBX_ClumpStage_Helper {
    int sub_5B4DC0();
    int sub_5B4DE0(int);
};

extern "C" void __stdcall sub_77E6D8();
extern "C" void __cdecl sub_62FC62(int);
extern "C" int __cdecl sub_604800(int);
extern "C" int __cdecl sub_605240(int, int);
extern "C" int __cdecl sub_605420(int, int);
extern "C" int __cdecl sub_5A93B0(int);
extern "C" int __cdecl sub_5E29B0(int, int);
extern "C" int __cdecl sub_5B3A60(int, int, int, int, int);
extern "C" int __cdecl sub_570200(int, int);
extern "C" int __cdecl sub_627240(int);

void RBX_ClumpStage::sub_606700(int arg)
{
    RBX_ClumpStage_Helper *helper = (RBX_ClumpStage_Helper *)arg;
    int node = helper->sub_5B4DC0();
    while (node != 0) {
        if (sub_604800(node)) {
            int val = *(int *)(node + 8);
            if (arg == val) {
                val = *(int *)(node + 0xc);
            }
            sub_606700(val);
        }
        node = helper->sub_5B4DE0(node);
    }
    sub_6055C0(arg);
}
