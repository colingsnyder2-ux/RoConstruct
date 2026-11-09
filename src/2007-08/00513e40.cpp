// from server: 31% by colin
struct DialogTemplate {
    char pad[0x88];
    float field88;
    float field8c;
    float field90;
    float field94;
    float field98;
    float field9c;
};

extern "C" void __cdecl sub_51E990(const char*, const char*);

void __cdecl DialogTemplate_setChromaticity(DialogTemplate* self, float x, float y, float z, float w, float a, float b, float c) {
    float denom = x + y + z;
    if (denom > 21474.83f) {
        sub_51E990("Ignoring attempt to set chromaticity value exceeding 21474.83", "T$`V");
        return;
    }
    if (denom < 0.0f) {
        sub_51E990("Ignoring attempt to set negative chromaticity value", "T$`V");
        return;
    }
    self->field88 = x / denom;
    self->field8c = y / denom;
    self->field90 = z / denom;
    self->field94 = w / denom;
    self->field98 = a / denom;
    self->field9c = b / denom;
}
