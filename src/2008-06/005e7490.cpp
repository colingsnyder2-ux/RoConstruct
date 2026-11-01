// from server: 100% by king_originala
struct Link {
    char pad[20];
    Link* next;
};

struct Node {
    char pad[160];
    Link* link;
};

struct Pair {
    char pad[12];
    Node* first;
    Node* second;
};

Node* __cdecl func_005e7490(Pair* p)
{
    Node* result = p->first;
    Node* other = p->second;
    if (other && result->link->next != other->link)
        result = other;
    return result;
}
