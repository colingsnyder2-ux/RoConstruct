// from server: 100% by king_originala
struct CMainFrame;
struct CommandBars;

struct Source {
    CommandBars* Get();
};

struct CommandBars {
    void SetFrame(CMainFrame* frame);
    void Initialize();
};

struct CMainFrame {
    char padding[0xec];
    CommandBars* bars;
    int Setup(Source* source);
};

int CMainFrame::Setup(Source* source)
{
    bars = source->Get();
    if (!bars)
        return 0;

    bars->SetFrame(this);
    bars->Initialize();
    return 1;
}
