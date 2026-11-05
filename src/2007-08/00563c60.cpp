// from server: 100% by EspClaude
// roc 2007-08 00563c60  selection verb isEnabled: selection is non-empty
#include <vector>
struct Entry {
    void* value;
    void* owner;
};
typedef std::vector<Entry> Instances;

struct Selection {
    char padding[0x104];
    Instances* items;
};

struct SelectionClient {
    Selection* createService(bool) const;
};

struct SelectionVerb {
    char padding[0x14];
    SelectionClient selection;
    bool isEnabled() const;
};

bool SelectionVerb::isEnabled() const
{
    return 0U < selection.createService(true)->items->size();
}
