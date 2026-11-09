// from server: 100% by king_originala
struct Ball {
    int func_005e7470();
};

struct Edge {
    char padding[0x0c];
    Ball* endpoints[2];
};

bool __cdecl compatible(Edge* edge, Edge* other);

struct TreeStage {
    char padding[0x14];
    bool changed;

    void reconcile(Ball* left, Ball* right, int leftDepth, int rightDepth,
                   void* context0, void* context1);
    void detach(Edge* other, Edge* edge, Ball* endpoint);
    void update(Edge* edge);
};

void TreeStage::update(Edge* edge)
{
    Ball* left = edge->endpoints[0];
    Ball* right = edge->endpoints[1];

    struct Context {
        Edge* other;
        int side;
    } context;

    context.side = 0;
    context.other = 0;

    int leftDepth = left ? left->func_005e7470() : 0;
    int rightDepth = right ? right->func_005e7470() : 0;

    reconcile(left, right, leftDepth, rightDepth,
              &context.other, &context.side);

    if (!context.other || compatible(edge, context.other)) {
        detach(context.other, edge,
               edge->endpoints[(context.side + 1) % 2]);
        changed = true;
    }
}
