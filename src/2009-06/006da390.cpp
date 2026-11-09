// from server: 100% by atomic.potato
struct Inner {
    int getValue();
};

struct LoopArg {
    char _pad[0x10];
    Inner* inner;
};

struct SleepStage {
    void runLoop(LoopArg* arg);
    void apply(int value);
};

void SleepStage::runLoop(LoopArg* arg) {
    for (int i = 2; i != 0; --i) {
        this->apply(arg->inner->getValue());
    }
}
