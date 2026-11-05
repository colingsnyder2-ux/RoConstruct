// from server: 56% by atomic.potato
struct Node {
    char pad0[0xc];
    int key_lo;
    int key_hi;
};

struct Container {
    char pad0[4];
    Node* end;
};

struct Result {
    Node* ptr;
};

struct VFriendService {
    Result* lower_bound(int* key, Result* out);
};

extern "C" Node* __stdcall find_node(Container* self, int* key);

Result* VFriendService::lower_bound(int* key, Result* out) {
    Node* it = find_node((Container*)this, key);
    Node* end = ((Container*)this)->end;
    if (it != end) {
        if (it->key_lo > key[0]) {
            goto done;
        }
        if (it->key_lo == key[0]) {
            if (key[1] < it->key_hi) {
                goto done;
            }
        }
        out->ptr = it;
        return out;
    }
done:
    out->ptr = end;
    return out;
}
