// from server: 100% by king_originala
struct Node {
    int field0;
    int index;
    int* f();
};

struct Object {
    virtual ~Object();
};

struct ContactConnector {
    Node* resolve(Object*);
    void release(Object**);
};

void ContactConnector::release(Object** object)
{
    resolve(*object)->f();
    if (*object)
        delete *object;
    *object = 0;
}
