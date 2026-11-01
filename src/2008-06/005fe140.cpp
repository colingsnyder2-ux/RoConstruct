// from server: 100% by king_originala
struct State {
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6();
    virtual void v7(), v8(), v9(), v10(), v11(), v12(), v13();
    virtual void v14(), v15(), v16(), v17(), v18(), v19(), v20();
    virtual void v21(), v22(), v23(), v24(), v25(), v26(), v27();
    virtual void v28(), v29(), v30(), v31(), v32(), v33(), v34();
    virtual bool check();
};

struct Node {
    State* getState();
};

struct Object {
    char padding[0x170];
    Node* node;
    void* getParent();
};

struct Tool {
    char padding[0x104];
    void* parent;
    void update();
    void setParent(void*);
};

extern "C" void* findObject(void*);
extern "C" int validNode(Node*);
extern "C" void processObject(Object*);

void Tool::update()
{
    Object* object = (Object*)findObject(this);
    if (object) {
        Node* node = object->node;
        if (node && validNode(node)) {
            State* state = node->getState();
            if (state && !state->check())
                return;
        }

        void* oldParent = parent;
        if (oldParent == object->getParent()) {
            processObject(object);
            setParent(object->node);
        } else {
            setParent(object->getParent());
        }
    }
}
