// from server: 100% by king_originala
struct Entry {
    int key;
    int unused[2];
};

struct Table {
    unsigned char unused[24];
    Entry* entries;
};

struct Link {
    Link* next;
    int unused;
    unsigned char index;
    unsigned char marked;
};

struct Node {
    Table* table;
    int unused04;
    Node* parent;
    int unused0C[2];
    Link* links;
    unsigned char unused18[26];
    unsigned char count;
    unsigned char unused33[121];
    unsigned short indices[1];
};

struct Result {
    int type;
    int unused04;
    int index;
    int unused0C;
    int first;
    int second;
};

extern int __cdecl resolve(int key, Result* result);

int __cdecl search(Node* node, int key, Result* result, int flag)
{
    if (!node) {
        result->first = -1;
        result->second = -1;
        result->type = 8;
        result->index = 255;
        return 8;
    }

    int i;
    for (i = node->count - 1; i >= 0; --i) {
        if (key == node->table->entries[node->indices[i]].key)
            break;
    }

    if (i >= 0) {
        result->first = -1;
        result->second = -1;
        result->type = 6;
        result->index = i;

        if (!flag) {
            Link* link = node->links;
            while (link) {
                if (link->index <= i) {
                    link->marked = 1;
                    break;
                }
                link = link->next;
            }
        }
        return 6;
    } else {
        int type = search(node->parent, key, result, 0);
        if (type == 8)
            return type;
    }

    result->index = resolve(key, result);
    result->type = 7;
    return 7;
}
