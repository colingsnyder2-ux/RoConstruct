// from server: 100% by why2
struct ChatWidget {
    char pad[0xa0];
    int field_a0;
    void sub_607770(int);
    void f();
};

void ChatWidget::f() {
    if (field_a0 == 1) {
        sub_607770(3);
    }
}
