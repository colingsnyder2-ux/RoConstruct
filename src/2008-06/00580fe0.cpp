// from server: 100% by king_originala
struct Element {
    unsigned int data[2];
};

struct Selection {
    char padding[12];
    Element* first;
    Element* last;
};

struct Context {
    char padding[0x154];
    Selection* selection;
};

struct Owner {
    Context* getContext();
};

struct DuplicateSelectionVerb {
    char padding[0x20];
    Owner* owner;
    bool isEnabled();
};

bool DuplicateSelectionVerb::isEnabled()
{
    Context* context = owner ? owner->getContext() : 0;
    Selection* selection = context->selection;
    return static_cast<unsigned int>(selection->last - selection->first) > 0;
}
