// from server: 100% by EspClaude
// roc 2007-08 005647b0  RBX::ControllerCommand::isEnabled: non-empty selection and the workspace has a matching instance
#include <vector>
struct Entry {
    void* value;
    void* owner;
};
typedef std::vector<Entry> Instances;

struct Instance;
struct Selection {
    char padding[0x104];
    Instances* items;
};
struct SelectionClient {
    Selection* createService(bool) const;
};
struct Workspace {
    Instance* findFirst(bool (*predicate)(Instance*));
};
struct DataModel {
    Workspace* getWorkspace();
};
bool isControllable(Instance*);

class ControllerCommand {
    char padding[0x14];
    SelectionClient selection;
    char padding2[8];
    DataModel* dataModel;
public:
    bool isEnabled() const;
};

bool ControllerCommand::isEnabled() const
{
    if (selection.createService(true)->items->size() == 0)
        return false;
    Workspace* workspace = dataModel ? dataModel->getWorkspace() : 0;
    return workspace->findFirst(isControllable) != 0;
}
