// from server: 68% by Intel
struct Node {
    Node* next;
    Node* prev;
    Node* data;
};

struct Filter {
    Node* head;
    Node* tail;
    int count;
    int field_0C;
    Node* freeList;
    int field_14;
    int field_18;
    int field_1C;
    int Function(Node* inputHead);
};

extern "C" void* __cdecl malloc(int size);

int Filter::Function(Node* inputHead) {
    Node* current = inputHead;
    if (!current)
        return 1;

    do {
        Node* data = current->data;
        Node* next = current->next;

        Node* newNode = this->freeList;
        if (newNode) {
            this->freeList = newNode->next;
            --this->field_14;
        } else {
            newNode = (Node*)malloc(12);
            if (!newNode)
                return 0;
        }

        newNode->data = data;
        newNode->prev = 0;
        newNode->next = this->tail;

        if (this->tail)
            this->tail->prev = newNode;
        else
            this->head = newNode;

        ++this->count;
        this->tail = newNode;
        current = next;
    } while (current);

    return 1;
}
