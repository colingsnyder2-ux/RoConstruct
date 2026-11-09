// from server: 42% by atomic.potato
struct Stage
{
    int value;
};

struct EdgeStage
{
    int unused;
    int pipeline;
    void f(Stage *stage);
};

extern "C" void __stdcall func_00791e00(int, Stage *);

void EdgeStage::f(Stage *stage)
{
    func_00791e00(pipeline, stage);
    stage->value = stage->value;
}
