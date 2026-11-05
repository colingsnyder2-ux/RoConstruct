// from server: 100% by king_originala
struct VerbWidget {
    unsigned long data[0x148 / 4];
    VerbWidget();
    ~VerbWidget();
    void setVerb(void *);
};

struct ImageButton : VerbWidget {
    void *owner;
    unsigned char active;
    ImageButton(void *, void *);
    ~ImageButton();
};

struct ImageState {
    unsigned long data;
    ImageState(void *, void *);
};

struct Button : ImageButton {
    ImageState state;
    Button(void *, void *, void *);
};

Button::Button(void *image, void *verb, void *context)
    : ImageButton(verb, context),
      state(
          (data[0x00 / 4] = 0x84ba24,
           data[0x10 / 4] = 0x84ba14,
           data[0x14 / 4] = 0x84ba0c,
           data[0x20 / 4] = 0x84ba04,
           data[0x24 / 4] = 0x84b9f4,
           data[0x44 / 4] = 0x84b9e4,
           data[0x64 / 4] = 0x84b9d4,
           data[0x84 / 4] = 0x84b9c4,
           data[0xa4 / 4] = 0x84b9b4,
           data[0xc4 / 4] = 0x84b9a4,
           data[0x130 / 4] = 0x84b99c,
           image),
          verb)
{
}
