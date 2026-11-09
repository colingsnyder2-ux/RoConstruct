// from server: 100% by tester
struct ChatWidget {
    char pad[0xa8];
    int state;
    void update();
};

extern "C" void __stdcall sub_555860(int);

void ChatWidget::update() {
    if (state == 1)
        sub_555860(3);
}
