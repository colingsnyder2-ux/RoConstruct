// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Node_006d46e0 {
    int pad;
    Node_006d46e0* next;
    Node_006d46e0* last();
    Node_006d46e0* lastOther();
};
Node_006d46e0* Node_006d46e0::last()
{
    if (next)
        return next->lastOther();
    return this;
}
