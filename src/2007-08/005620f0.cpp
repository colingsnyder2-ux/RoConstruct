// from server: 100% by EspClaude
// roc 2007-08 005620f0  RBX::DuplicateSelectionVerb::isEnabled: selection is non-empty
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

struct DataModel {
    Selection* getSelection();
};

class DuplicateSelectionVerb {
    char padding[0x20];
    DataModel* dataModel;
public:
    bool isEnabled() const;
};

bool DuplicateSelectionVerb::isEnabled() const
{
    Selection* selection = dataModel ? dataModel->getSelection() : 0;
    return 0U < selection->items->size();
}
