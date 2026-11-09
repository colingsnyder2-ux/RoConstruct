// from server: 20% by atomic.potato
struct Node {
    char pad0[4];
    Node* parent;
    Node* left;
    Node* right;
    char pad1;
    char color;
    char pad2[0x23];
};

struct PrismPoly {
    char pad0[4];
    Node* header;
    int size;
    void* insert_unique(void*, void*, int, void*);
    void* find(void*, void*);
    void* lower_bound(void*, void*);
    void* erase_node(void*, void*);
    void* erase(void*, void*);
};

extern "C" int __cdecl compare(void*, void*);
extern "C" void __cdecl construct_node(void*);
extern "C" void __cdecl erase_node(void*);

void* PrismPoly::insert_unique(void* a, void* b, int c, void* d) {
    return 0;
}

void* PrismPoly::find(void* a, void* b) {
    return 0;
}

void* PrismPoly::lower_bound(void* a, void* b) {
    return 0;
}

void* PrismPoly::erase_node(void* a, void* b) {
    return 0;
}

void* PrismPoly::erase(void* a, void* b) {
    return 0;
}

void* PrismPoly_erase(PrismPoly* self, void* a, void* b, void* c) {
    Node* node;
    Node* tmp;
    void* result;
    char buf[8];
    
    if (self->size == 0) {
        self->insert_unique(a, self->header, 1, c);
        return a;
    }
    
    node = (Node*)b;
    if (node == self->header) {
        if (compare(a, (char*)node + 0xc)) {
            self->insert_unique(a, node, 1, c);
            return a;
        }
    } else if (node == self->header->parent) {
        tmp = node->right;
        if (compare((char*)tmp + 0xc, a)) {
            self->insert_unique(a, tmp, 0, c);
            return a;
        }
    } else {
        if (compare((char*)node + 0xc, a)) {
            *(Node**)buf = node;
            construct_node(buf);
            tmp = *(Node**)buf;
            if (compare((char*)tmp + 0xc, a)) {
                if (tmp->right->color == 0) {
                    self->insert_unique(a, tmp, 0, c);
                    return a;
                }
                self->insert_unique(a, node, 1, c);
                return a;
            }
        }
        if (compare(a, (char*)node + 0xc)) {
            *(Node**)buf = node;
            erase_node(buf);
            tmp = *(Node**)buf;
            if (tmp != self->header) {
                if (!compare((char*)tmp + 0xc, a)) {
                    goto insert;
                }
            }
            if (node->right->color == 0) {
                self->insert_unique(a, node, 0, c);
                return a;
            }
            self->insert_unique(a, tmp, 1, c);
            return a;
        }
    }
    
insert:
    result = self->lower_bound(a, buf);
    *(void**)c = *(void**)result;
    return c;
}
