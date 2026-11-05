// from server: 100% by colin
struct Sub {
    char pad[0x14c];
    int state;
    Sub* get();
};

struct ArrowButton {
    char pad[0x140];
    Sub* sub;
    bool isPressed();
};

bool ArrowButton::isPressed()
{
    return sub->get()->state == 1;
}
