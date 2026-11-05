// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_marshaledpayloadargsd7986ef2083f67ca.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
// from server: 72% by king_originala
void* __cdecl operator new(unsigned int);

struct Pair {unsigned first,second;__forceinline void assign(unsigned a,unsigned b){first=a;second=b;} __forceinline Pair(const Pair& other){assign(other.first,other.second);}};

struct S;

struct Node
{
    unsigned char data[24];

    Node(S*, int, Pair) throw();
};

struct Container
{
    unsigned char data[28];

    void insert(Node* const&);
};

struct Dispatcher
{
    void method(int);
};

struct S
{
    void* field0;
    std::vector<Node*> container;
    unsigned padding;
    Dispatcher* dispatcher;

    void f(int, Pair);
};

void S::f(int arg, Pair value)
{
    Node* node = new Node(this, arg, value);
    container.push_back(node);
    dispatcher->method(reinterpret_cast<int>(node));
}
