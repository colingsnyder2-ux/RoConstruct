// from server: 45% by tester
struct Node {
    char pad0[8];
    unsigned int m_key;
    char pad1[0x2d - 0xc - 4];
    char m_isNil;
    char pad2[3];
    Node* m_left;
    Node* m_right;
    Node* m_parent;
};

struct Tree {
    char pad0[4];
    Node* m_head;
};

struct SceneUpdater {
    char pad0[4];
    Tree* m_tree;
    void find(Node** result, int* key);
};

void SceneUpdater::find(Node** result, int* key)
{
    Node* head = m_tree->m_head;
    Node* node = head->m_parent;
    Node* candidate = head;
    if (node->m_isNil == 0) {
        int k = *key;
        do {
            if (node->m_key < k) {
                node = node->m_right;
            } else {
                candidate = node;
                node = node->m_left;
            }
        } while (node->m_isNil == 0);
    }
    Node* end = m_tree->m_head;
    if (candidate != end && *key >= candidate->m_key) {
        *result = candidate;
        return;
    }
    *result = end;
}
