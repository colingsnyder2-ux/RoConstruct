// from server: 1% by colin
struct XmlElement;
struct XmlParser {
    void* buffer;
    XmlParser(void* b) : buffer(b) {}
};

struct TextXmlParser : XmlParser {
    char pad0[4];
    char mapdata[0x14];
    int count;
    void* top;
    TextXmlParser(void* b);
    XmlElement* parse();
    void skipWhitespace();
    void* readTag();
    void* readFirstTag();
    void* readText(bool decode);
    void* removeTag(void* contents, int* index);
    void* findNextToken(void* contents, int* index);
    void* findText(void* attribute);
    XmlElement* parseAttributes(void* currentTag);
};

extern "C" {
    int __stdcall sub_77e4bc(void*);
    void __stdcall sub_77e698(void*, const char*);
    void __stdcall sub_77e6a4(void*);
    void __stdcall sub_77e690(void*, void*);
    void __stdcall sub_77e6ac(void*);
    void __stdcall sub_77e638(void*, int, int, void*);
    int __stdcall sub_77e5f8(const char*, const char*);
    void __stdcall sub_77e61c(const char*, const char*);
    void __stdcall sub_77e4b4(void*, void*, int);
    void __stdcall sub_77e4b8(void*);
    void __stdcall sub_77e674(void*, int, int);
    void __stdcall sub_77e5fc(void*);
    void __stdcall sub_77e678(void*);
    void __stdcall sub_77e670(void*, void*);
    void __stdcall sub_77e69c(void*, void*);
    void __stdcall sub_77e6a4(void*);
}

void sub_412dc0(void*, void*);
void sub_630b9e(void*, void*);
void sub_564ef0(void);
void sub_5650b0(void);
void sub_5669f0(void);
void sub_564d90(void);
void sub_564e20(void);
void sub_5663f0(void);
void sub_60bf60(void);
void sub_56d990(void);
void sub_55d3b0(void);
void sub_55d6b0(void);
void sub_55d460(void);
void sub_52cb30(void);
void sub_5653f0(void);
void sub_565b10(void);
void sub_408740(void);
void sub_547ca0(void);
void sub_565810(void);
void sub_43d780(void);
void sub_491500(void);
void sub_5017c0(void);

TextXmlParser::TextXmlParser(void* b) : XmlParser(b) {
    count = 0;
    top = 0;
}

XmlElement* TextXmlParser::parse() {
    return 0;
}
