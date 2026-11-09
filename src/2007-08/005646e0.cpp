// from server: 100% by EspClaude
// roc 2007-08 005646e0  RBX::TrackCameraCommand::isEnabled: non-empty selection and exactly one selected item
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
struct DataModel {
    Selection* getSelection();
};

class TrackCameraCommand {
    char padding[0x14];
    SelectionClient selection;
    char padding2[8];
    DataModel* dataModel;
public:
    bool isEnabled() const;
};

bool TrackCameraCommand::isEnabled() const
{
    if (selection.createService(true)->items->size() == 0)
        return false;
    Selection* s = dataModel ? dataModel->getSelection() : 0;
    return s->items->size() == 1;
}
