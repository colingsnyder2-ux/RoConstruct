// from server: 100% by Intel
struct SomeObject {
    struct Node* __thiscall GetFirstNode();
    struct Node* __thiscall GetNextNode(struct Node* current);
};

struct Node {
    char pad[0xC];
    void* fieldC;
    void* field10;
};

struct GroundStage {
    void Traverse(SomeObject* obj);
    void ProcessNode(void* ptr);
};

void GroundStage::Traverse(SomeObject* obj) {
    Node* node = obj->GetFirstNode();
    while (node) {
        void* ptr = node->fieldC;
        if (obj == ptr) {
            ptr = node->field10;
        }
        this->ProcessNode(ptr);
        node = obj->GetNextNode(node);
    }
}
