// from server: 100% by colin
struct S {
    float position[3];
    unsigned int key;
    int value;
    bool less(const S* left, const S* right);
};
static __declspec(noinline) int __fastcall compare(const S* p, const S* q)
{
    if (p->position[0] < q->position[0]) return -1;
    if (p->position[0] > q->position[0]) return 1;
    if (p->position[1] < q->position[1]) return -1;
    if (p->position[1] > q->position[1]) return 1;
    if (p->position[2] < q->position[2]) return -1;
    if (p->position[2] > q->position[2]) return 1;
    return 0;
}
bool S::less(const S* left, const S* right)
{
    int result = compare(left, right);
    if (result < 0) return true;
    if (result > 0) return false;
    unsigned int a = left->key;
    unsigned int b = right->key;
    if (a < b) return true;
    if (a > b) return false;
    if (left->value < right->value) return true;
    return false;
}
