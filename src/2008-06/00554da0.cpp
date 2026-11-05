// from server: 100% by king_originala
struct StateSignal {
    char storage[0x20];
    void fire(int oldState, int newState);
};

struct ValueSignal {
    char storage[0x24];
    void fire(int newState);
};

struct RunService {
    char padding[0x170];
    StateSignal stateSignal;
    ValueSignal valueSignal;
    int state;
    double elapsed;

    void setState(int newState);
};

void RunService::setState(int newState)
{
    if (newState == 1) {
        if (state != 0 && state != 2)
            return;
    } else if (newState == 2) {
        if (state != 1)
            return;
    } else if (newState == 0) {
        elapsed = 0.0;
    }

    int oldState = state;
    if (oldState != newState) {
        state = newState;
        valueSignal.fire(newState);
        stateSignal.fire(oldState, newState);
    }
}
