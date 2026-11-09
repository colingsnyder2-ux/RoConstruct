// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_cc6a16e3b9ea348d.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/thread/mutex.hpp>

namespace RBX {

class Item;

struct BaseA { virtual ~BaseA(); };
struct BaseB { virtual void b(); };

class Node : public BaseA, public BaseB {
public:
    std::vector<Item*> items;
    char pad[0x84];
    std::vector<Node*> children;

    void visit(Node* node);
    void visitItem(Node* node, Item* item);
};

boost::mutex& getMutex();

void Node::visit(Node* node)
{
    boost::mutex::scoped_lock lock(getMutex());
    std::for_each(node->children.begin(), node->children.end(), boost::bind(&Node::visit, this, _1));
    std::for_each(node->items.begin(), node->items.end(), boost::bind(&Node::visitItem, this, node, _1));
}

}
