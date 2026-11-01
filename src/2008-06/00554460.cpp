// from server: 100% by tester
struct Workspace { void stop(); };

struct RunService {
    char pad[0x27c];
    Workspace* workspace;
    void stop();
};

void RunService::stop()
{
    if (workspace)
        workspace->stop();
}
