// from server: 100% by tester
struct TextXmlParser {
    char pad[0x134];
    float field260;
    float field264;
    float field268;
    void setVector(const float* v);
};

extern "C" float* __cdecl sub_5e1060(float* out, const float* in);

void TextXmlParser::setVector(const float* v) {
    float tmp[3];
    float* r = sub_5e1060(tmp, v);
    field260 = r[0];
    field264 = r[1];
    field268 = r[2];
}
