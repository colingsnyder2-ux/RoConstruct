// from server: 100% by king_originala
extern "C" unsigned int (__stdcall *RegisterClipboardFormatA)(const char *);
extern "C" int (__stdcall *IsClipboardFormatAvailable)(unsigned int);
extern const char clipboardName[];

struct Element {
    void *object;
    void *control;
};

struct Collection {
    char padding[12];
    Element *first;
    Element *last;
};

struct Data {
    char padding[0x154];
    Collection *collection;
};

struct Owner {
    Data *get();
};

struct PasteVerb {
    char padding[12];
    Owner *owner;
    bool restricted;

    bool enabled();
};

bool PasteVerb::enabled()
{
    static unsigned int format;
    static unsigned int initialized;

    if (!(initialized & 1)) {
        initialized |= 1;
        format = RegisterClipboardFormatA(clipboardName);
    }

    if (IsClipboardFormatAvailable(format) != 1)
        return false;

    if (!restricted)
        return true;

    Data *data = owner ? owner->get() : 0;
    Collection *collection = data->collection;
    return collection->last - collection->first == 1;
}
