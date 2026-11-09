// from server: 100% by colin
struct RBX_ClumpStage {
    void sub_607190(int);
    void sub_607060(int);
};

struct RBX_ClumpStage_Helper {
    int sub_5B4DC0();
    int sub_5B4DE0(int);
};

extern "C" char __cdecl sub_60B480(int, int);

void RBX_ClumpStage::sub_607190(int arg)
{
    RBX_ClumpStage_Helper *helper = (RBX_ClumpStage_Helper *)arg;
    int node = helper->sub_5B4DC0();
    while (node != 0) {
        if (sub_60B480(arg, node)) {
            int val = *(int *)(node + 8);
            if (arg == val) {
                val = *(int *)(node + 0xc);
            }
            sub_607190(val);
        }
        node = helper->sub_5B4DE0(node);
    }
    sub_607060(arg);
}
