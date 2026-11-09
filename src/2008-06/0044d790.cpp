// from server: 100% by king_originala
struct ThreadState {
    void* get();
    void set(void*);
    void cleanup(void*);
};

ThreadState* threadState();

struct Guard {
    void* previous;
    Guard(int);
    ~Guard();
};

inline Guard::~Guard()
{
    ThreadState* state = threadState();
    void* current = state->get();
    if (current != previous) {
        state->set(previous);
        if (current)
            state->cleanup(current);
    }
}

struct CRobloxApp {
    int operation();
    int f();
};

int CRobloxApp::f()
{
    Guard guard(1);
    return operation();
}
