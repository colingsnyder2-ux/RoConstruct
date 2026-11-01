// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Payload {
    char data[0x2c];
    Payload(const Payload&);
    ~Payload();
};
struct Task {
    Payload payload;
    bool flag;
};
struct Job {
    int id;
    Task task;
};
class Runner {
    void* state;
public:
    Runner(Job job, int extra);
    void start(Job job);
};
Runner::Runner(Job job, int extra) : state(0)
{
    start(job);
}
