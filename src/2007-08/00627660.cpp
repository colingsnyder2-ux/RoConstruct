// from server: 100% by colin
struct SeparateStage;

struct Helper1 {
    void method(void* arg);
};

struct Helper2 {
    void method(void* arg);
};

struct SeparateStage {
    char pad[8];
    Helper1* field8;
    void process(void* arg);
};

void SeparateStage::process(void* arg) {
    field8->method(arg);
    ((Helper2*)arg)->method(this);
}
