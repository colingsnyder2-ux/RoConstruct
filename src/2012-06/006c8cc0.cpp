// from server: 100% by tajop
struct Storage {
    void* first;
    Storage() : first(0) {}
};

struct PODptr {
    char* ptr;
    unsigned sz;
    PODptr(char* nptr, unsigned nsize) : ptr(nptr), sz(nsize) {}
};

struct Pool : Storage {
    PODptr list;
    unsigned requested_size;
    unsigned next_size;
    unsigned start_size;
    explicit Pool(unsigned nrequested_size, unsigned nnext_size = 32)
        : list(0, 0), requested_size(nrequested_size),
          next_size(nnext_size), start_size(nnext_size) {}
    ~Pool();
};

struct Node;

struct Trie {
    Pool node_pool;
    Pool data_pool;
    Node* root;
    Trie();
    Node* create_node(const int& depth);
};

Trie::Trie()
    : node_pool(0x188), data_pool(4), root(create_node(1))
{
}
