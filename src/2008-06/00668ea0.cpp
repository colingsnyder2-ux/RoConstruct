// from server: 100% by king_originala
struct Edge;
struct Node {
    Edge* first();
    Edge* next(Edge*);
};

struct Stage;

struct Edge {
    char padding0[0x0c];
    Node* endpoint0;
    Node* endpoint1;
    char padding1[0x10];
    bool active;
};

Node* __cdecl selectNode(Edge*);
bool __cdecl preferEdge(Edge*, Edge*);

Node* __stdcall findEdge(Stage* stage, Node* node,
                         Edge** selectedEdge, Stage** selectedStage)
{
    Edge* edge = node->first();
    Node* other;

    while (edge) {
        if (edge->active) {
            other = node == edge->endpoint0
                ? edge->endpoint1 : edge->endpoint0;
            if (node == selectNode(edge))
                break;
        }
        edge = node->next(edge);
    }

    if (!edge)
        return 0;

    if (!*selectedEdge || preferEdge(*selectedEdge, edge)) {
        *selectedEdge = edge;
        *selectedStage = stage;
    }

    return other;
}
