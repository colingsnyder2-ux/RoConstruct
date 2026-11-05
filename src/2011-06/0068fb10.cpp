// from server: 50% by atomic.potato
struct String
{
    char pad[4];
    String(const String&);
};

struct GuiTextButton
{
    char pad[4];
    String text;
    GuiTextButton* f(String* value);
};

extern "C" void construct_string(String*, const String*);

GuiTextButton* GuiTextButton::f(String* value)
{
    String* target = &text;
    construct_string(target, value);
    value->pad[0] = target->pad[0];
    value->pad[1] = target->pad[1];
    value->pad[2] = target->pad[2];
    value->pad[3] = target->pad[3];
    return this;
}
