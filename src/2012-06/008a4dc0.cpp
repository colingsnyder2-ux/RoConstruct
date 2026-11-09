// from server: 100% by tajop
struct Workspace;

struct DataModel {
    char pad[0xac4];
    Workspace* workspace;
};

struct MouseCommand {
    virtual void f();
};

struct MouseCommandSecondary {
    virtual void g();
};

struct AxisToolBase : MouseCommand, MouseCommandSecondary {
    AxisToolBase(Workspace* workspace);
    char pad[0x84];
};

struct AxisRotateTool : AxisToolBase {
    AxisRotateTool(Workspace* workspace) : AxisToolBase(workspace) {}
    virtual void f();
    virtual void g();
};

struct TToolVerb {
    char pad[0xc];
    DataModel* dataModel;
    MouseCommand* createCommand();
};

MouseCommand* TToolVerb::createCommand() {
    return new AxisRotateTool(dataModel->workspace);
}
