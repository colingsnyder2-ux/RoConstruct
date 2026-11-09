// from server: 66% by atomic.potato
struct ContactStage;
struct Stage;
struct Assembly;

struct ContactStage {
    void f(Stage *stage);
};

struct Stage {
    int v;
};

struct Assembly {
    int pad;
    int stage;
};

void call761670(int value, Stage *stage);

int call750ac0(Assembly *assembly, Stage *stage);

void ContactStage::f(Stage *stage)
{
    int value = *(int *)((char *)this + 8);
    call761670(value, stage);
    call750ac0((Assembly *)this, stage);
}
