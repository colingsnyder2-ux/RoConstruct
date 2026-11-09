// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <set>

struct Value {
    char padding[0x1c];
    bool marked;
};

struct TreeStage {
    char padding0[0x14];
    bool active;
    char padding1[0x23];
    std::set<Value*> pending;
    std::set<Value*> removing;

    void process(Value* value);
    void remove(Value* value);
    void flush();
};

void TreeStage::flush()
{
    if (active) {
        std::set<Value*>::iterator it;
        for (it = pending.begin(); it != pending.end(); ++it)
            process(*it);
        pending.clear();
        while (!removing.empty()) {
            it = removing.begin();
            remove(*it);
            (*it)->marked = false;
            removing.erase(it);
        }
        active = false;
    }
}
