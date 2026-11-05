// from server: 100% by king_originala
struct Node {
    bool compare(Node* other);
};

struct S {
    char padding[12];
    Node* first;
    Node* second;

    bool update(float value);
    int f(float value);
};

int S::f(float value)
{
    if (((Node*)((char*)first + 128))->compare(
            (Node*)((char*)second + 128)) && update(value))
        return 1;
    return 0;
}
