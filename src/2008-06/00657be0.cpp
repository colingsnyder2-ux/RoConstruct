// from server: 100% by tester
struct Sub {
    char pad[0x1b4];
    int state;
    Sub* get();
};

struct ArrowButton {
    char pad[0x188];
    Sub* sub;
    bool isPressed();
};

bool ArrowButton::isPressed()
{
    return sub->get()->state == 1;
}
