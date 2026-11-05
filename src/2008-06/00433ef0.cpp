// from server: 100% by king_originala
struct FontData {
    long height;
    long width;
    long escapement;
    long orientation;
    long weight;
    unsigned char italic;
    unsigned char underline;
    unsigned char strikeOut;
    unsigned char charSet;
    unsigned char outPrecision;
    unsigned char clipPrecision;
    unsigned char quality;
    unsigned char pitchAndFamily;
    char faceName[32];
    unsigned long extra;

    FontData();
};

struct Font {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual int setFont(void*, FontData*);

    void* handle;
};

struct Node {
    char padding[0x131];
    unsigned char strikeOut;
    unsigned char italic;
};

extern "C" {
    extern long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);
    extern int (__stdcall *GetObjectA)(void*, int, void*);
}

Font* __stdcall fontFromHandle(long);

struct S {
    char padding0[0x20];
    void* window;
    char padding1[0x3c];
    Font font;

    void updateFont(void*, Node*);
};

void S::updateFont(void* item, Node* node)
{
    if (!node)
        return;

    long (__stdcall *sendMessage)(void*, unsigned int, unsigned int, long) = SendMessageA;
    int (__stdcall *getObject)(void*, int, void*) = GetObjectA;

    if (node->strikeOut) {
        FontData data;
        Font* source = fontFromHandle(sendMessage(window, 0x31, 0, 0));
        if (getObject(source->handle, 60, &data)) {
            data.strikeOut = 1;
            font.setFont(item, &data);
        }
    }

    if (node->italic) {
        FontData data;
        Font* source = fontFromHandle(sendMessage(window, 0x31, 0, 0));
        if (getObject(source->handle, 60, &data)) {
            data.italic = 1;
            font.setFont(item, &data);
        }
    }
}
