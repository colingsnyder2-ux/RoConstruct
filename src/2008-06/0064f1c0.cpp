// from server: 100% by king_originala
struct VerbWidget {
    unsigned long data[0x148 / 4];

    VerbWidget();
    ~VerbWidget();
    void setVerb(void *);
};

struct ImageState {
    ImageState(void *, void *);
    ~ImageState();
};

struct ImageButton : VerbWidget {
    ImageState image;

    ImageButton(void *, void *);
};

ImageButton::ImageButton(void *verb, void *context)
    : VerbWidget(),
      image((
          data[0x00 / 4] = 0x84b814,
          data[0x10 / 4] = 0x84b804,
          data[0x14 / 4] = 0x84b7fc,
          data[0x20 / 4] = 0x84b7f4,
          data[0x24 / 4] = 0x84b7e4,
          data[0x44 / 4] = 0x84b7d4,
          data[0x64 / 4] = 0x84b7c4,
          data[0x84 / 4] = 0x84b7b4,
          data[0xa4 / 4] = 0x84b7a4,
          data[0xc4 / 4] = 0x84b794,
          data[0x130 / 4] = 0x84b78c,
          verb), context)
{
    setVerb(context);
}
