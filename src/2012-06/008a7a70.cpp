// from server: 100% by Xemicl
// from server: 100% by tajop

struct Workspace;

struct DataModel {
    char pad[0xac4];
    Workspace* workspace;
    Workspace* getWorkspace() const { return workspace; }
};

struct MouseCommandTool {
    char pad[0x3c];
    MouseCommandTool(Workspace* workspace);
};

struct TToolVerb {
    char pad[0xc];
    DataModel* dataModel;
    MouseCommandTool* newTool();
};

MouseCommandTool* TToolVerb::newTool() {
    return new MouseCommandTool(dataModel->getWorkspace());
}
