// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD





#include <set>

struct Stage {
    virtual void v0();
    virtual int level();
};

struct State {
    int stage;
    int extra;
};

struct Thing13 {
    void method();
};
struct Holder10 {
    char pad[0x2c];
    Thing13 *thing;
};
struct Thing {
    Thing() throw();
};
struct HolderA0 {
    char pad[0x10];
    Holder10 *holder;
    void apply(const Thing &);
};
struct Holder1c {
    char pad[0xa0];
    HolderA0 *holder;
};
struct Holder24 {
    char pad[0x1c];
    Holder1c *holder;
};

struct SleepStageArg {
    char pad0[4];
    Stage *stage;
    char pad2[0x10];
    State *state;
    char pad3[8];
    Holder24 *holder;
};

typedef std::set<SleepStageArg *> ArgSet;

struct Manager {
    void wake(SleepStageArg *);
    void sleep(SleepStageArg *);
};

struct SleepStage : Stage {
    __forceinline bool downstream(Stage *s) { return s->level() > level(); }
    char pad[4];
    Manager *manager;
    ArgSet *getSet(int);
    void step(SleepStageArg *arg, int newStage);
};

void SleepStage::step(SleepStageArg *arg, int newStage)
{
    int oldStage;
    if (arg->stage && arg->stage->level() >= level())
        oldStage = arg->state->stage;
    else
        oldStage = 0;

    getSet(oldStage)->erase(arg);
    getSet(newStage)->insert(arg);

    if ((oldStage == 4 || oldStage == 5) && newStage != 4 && newStage != 5) {
        Thing13 *t = arg->holder->holder->holder->holder->thing;
        if (t)
            t->method();
    }

    if (newStage == 3) {
        if (arg->stage->level() <= level())
            manager->wake(arg);
    } else if (newStage == 4 || newStage == 5) {
        static Thing thing;
        arg->holder->holder->holder->apply(thing);
    }

    if (newStage == 4 || newStage == 5 || newStage == 6) {
        if (downstream(arg->stage))
            manager->sleep(arg);
    }

    arg->state->extra = 0;
    arg->state->stage = newStage;
}