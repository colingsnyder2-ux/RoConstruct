// from server: 100% by colin
struct ClumpStage {
    bool f607bd0();
    bool f607f00();
    bool f608110();
    bool f606080();
    void f6071f0();
    void f606230();
    void f605180();
    void f606300();
    void run();
};

void ClumpStage::run()
{
    while (true) {
        f607bd0();
        if (!f607f00())
            continue;
        if (!f608110())
            continue;
        if (!f606080())
            continue;
        break;
    }
    f6071f0();
    f606230();
    f605180();
    f606300();
}
