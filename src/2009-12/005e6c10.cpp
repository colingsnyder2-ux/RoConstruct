// from server: 18% by atomic.potato
struct Node {
    char pad0[8];
    Node* left;
    Node* right;
    char pad1;
    char color;
    char pad2[0x63];
};

struct Tree {
    char pad0[8];
    Node* header;
    int size;
    int compare(int, int*);
    void insert(Node*, int);
    void insert2(Node*, int);
    int compare2(Node**, Tree*);
};

struct S {
    char pad0[8];
    Tree tree;
    int field18;
    int field1c;
    int method(int, Node*, int, int);
    int* method2(int, int*);
};

extern "C" void __stdcall _invalid_parameter_noinfo();

int S::method(int a, Node* b, int c, int d)
{
    if (field1c == 0) {
        return this->method(1, (Node*)field18, c, d);
    }

    Node* root = tree.header->left;
    int saved = field18;

    if (b != 0 && b != (Node*)this) {
        _invalid_parameter_noinfo();
    }

    if (b == root) {
        if (tree.compare(c, (int*)((char*)b + 0xc))) {
            return this->method(1, b, c, d);
        }
    } else {
        Node* hdr = tree.header;
        if (b != 0 && b != (Node*)this) {
            _invalid_parameter_noinfo();
        }
        if (b == hdr) {
            Node* n = tree.header->right;
            if (tree.compare(c, (int*)((char*)n + 0xc))) {
                return this->method(0, n, c, d);
            }
        } else {
            if (tree.compare(c, (int*)((char*)b + 0xc))) {
                Node* tmp = b;
                tree.insert(b, c);
                if (tree.compare(c, (int*)((char*)tmp + 0xc))) {
                    if (tmp->right->color == 0) {
                        return this->method(0, tmp, c, d);
                    } else {
                        return this->method(1, tmp, c, d);
                    }
                }
            }
            if (tree.compare(c, (int*)((char*)b + 0xc))) {
                Node* tmp = b;
                tree.insert2(b, c);
                if (tree.compare2(&tmp, &tree)) {
                    if (tree.compare(c, (int*)((char*)tmp + 0xc))) {
                        if (tmp->right->color == 0) {
                            return this->method(0, tmp, c, d);
                        } else {
                            return this->method(1, tmp, c, d);
                        }
                    }
                }
            }
        }
    }

    int result[2];
    int* p = this->method2(c, result);
    *(int*)c = p[0];
    *(int*)(c + 4) = p[1];
    return c;
}
