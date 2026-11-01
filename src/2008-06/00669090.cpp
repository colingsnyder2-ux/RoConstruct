// from server: 100% by king_originala
struct Edge;

struct Stage {
    Edge* ascend(bool side, Edge* edge, void* context0, void* context1);
    void reconcile(Edge* left, Edge* right, int leftDepth, int rightDepth,
                   void* context0, void* context1);
};

void Stage::reconcile(Edge* left, Edge* right, int leftDepth, int rightDepth,
                      void* context0, void* context1)
{
    for (;;) {
        if (leftDepth != rightDepth) {
            if (leftDepth > rightDepth) {
                --leftDepth;
                left = ascend(false, left, context0, context1);
            } else {
                --rightDepth;
                right = ascend(true, right, context0, context1);
            }
        } else {
            if (left == right)
                return;

            left = left ? ascend(false, left, context0, context1) : 0;
            Edge* nextRight = right ? ascend(true, right, context0, context1) : 0;
            --rightDepth;
            --leftDepth;
            right = nextRight;
        }
    }
}
