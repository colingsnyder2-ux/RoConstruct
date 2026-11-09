// from server: 76% by Intel




struct Context;
extern "C" void __stdcall sub_55E290(Context*);

struct RunService;
struct ServiceProvider {
    RunService* find(int);
};

struct RunService {
    virtual void setRunState(int) = 0;
};

struct RunCommand {
    char pad[0xC];
    Context* context;
    ServiceProvider services;
    void doIt(int);
};

void RunCommand::doIt(int)
{
    sub_55E290(context);
    RunService* service = services.find(1);
    if (reinterpret_cast<char*>(service)[0x1AC] != 0) {
        return;
    }
    service->setRunState(1);
}
