// from server: 100% by Espeon
// from server: 89% by colin
// from server: 83% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Key
{
    float x, y, z;
    unsigned int u;
    int i;
    __forceinline bool operator<(const Key& k) const { if(x<k.x)return true;if(x>k.x)return false;if(y<k.y)return true;if(y>k.y)return false;if(z<k.z)return true;if(z>k.z)return false;if(u<k.u)return true;if(u>k.u)return false;if(i<k.i)return true;return false;}
};

struct Node
{
    Node* left;
    Node* parent;
    Node* right;
    Key key;
    char padding[21];
    unsigned char nil;
};

struct S
{
    char padding[24];
    Node* head;
    Node* f(const Key& key);
};

Node* S::f(const Key& key)
{
    Node* node = head->parent;
    Node* result = head;

    while (!node->nil)
    {
        if (node->key < key)
        {
            node = node->right;
        }
        else
        {
            result = node;
            node = node->left;
        }
    }

    return result;
}
