// from server: 100% by colin
struct ChatWidget {
    char pad[0xfc];
    int state;
    void update();
};

extern "C" void __stdcall sub_555860(int);

void ChatWidget::update() {
    if (state == 1)
        sub_555860(3);
}
