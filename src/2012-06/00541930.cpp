// from server: 64% by Intel
struct Node
{
    Node* left;
    Node* right;
    Node* parent;
    char field_29;
};

struct Iterator
{
    Node* node;
    void increment();
};

void Iterator::increment()
{
    Node* current = this->node;
    if (current->field_29)
    {
        this->node = current->right;
        return;
    }

    Node* left = current->left;
    if (!left->field_29)
    {
        Node* leftRight = left->right;
        if (!leftRight->field_29)
        {
            do
            {
                left = leftRight;
                leftRight = left->right;
            } while (!leftRight->field_29);
        }
        this->node = left;
        return;
    }

    Node* parent = current->parent;
    if (!parent->field_29)
    {
        Node* currentNode = current;
        do
        {
            if (currentNode != parent->left)
                break;
            this->node = parent;
            parent = parent->parent;
            currentNode = this->node;
        } while (!parent->field_29);
    }

    Node* currentCheck = this->node;
    if (!currentCheck->field_29)
        this->node = parent;
}
