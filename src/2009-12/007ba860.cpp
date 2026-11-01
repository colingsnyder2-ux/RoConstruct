// from server: 80% by atomic.potato
struct Stage;

struct TreeStage
{
    void f(Stage*);
    int field8;
};

extern "C" void __stdcall removeFromStage(Stage*, TreeStage*);

extern "C" void call007b2f40(TreeStage*, Stage*);

void TreeStage::f(Stage* stage)
{
    removeFromStage(stage, (TreeStage*)field8);
    call007b2f40(this, stage);
}
