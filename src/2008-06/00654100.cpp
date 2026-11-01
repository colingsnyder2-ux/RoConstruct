// from server: 100% by king_originala
void __cdecl operator delete(void *) throw();

struct Base {
    unsigned char data[24];
    ~Base();
};

struct TreeStorage {
    void *head;
    unsigned char data[16];
    __forceinline ~TreeStorage();
};

struct Tree : TreeStorage {
    void clear();
    __forceinline ~Tree();
};

struct S : Base {
    Tree tree;
    ~S();
};

__forceinline TreeStorage::~TreeStorage()
{
    delete head;
}

__forceinline Tree::~Tree()
{
    clear();
}

S::~S()
{
}
