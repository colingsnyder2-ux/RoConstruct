// from server: 43% by colin
struct Vector3 {
    float x, y, z;
};

struct Rect {
    float minx, miny, maxx, maxy;
};

struct GuiObject {
    char pad[0x94];
};

struct TextBox {
    char pad0[0x1d8];
    bool shouldCaptureFocus;
    bool focused;
    char pad1[2];
    void* something;
    char pad2[0x94];
    GuiObject gui;
    void method(Vector3* v, Rect* out);
};

extern "C" void __stdcall sub_6f9aa0(Rect* out, Vector3* in);
extern "C" void __stdcall sub_9ea40c(void* dst, void* src);

void sub_6e6cf0(TextBox* self, Rect* out);
void sub_6e1670(TextBox* self, Vector3* v);
void sub_6e1d60(TextBox* self);

void TextBox::method(Vector3* v, Rect* out) {
    Rect r;
    sub_6f9aa0(&r, v);
    sub_6e6cf0(this, &r);

    unsigned int ix = *(int*)((char*)v + 8);
    short iy = (short)(ix >> 16);
    int iz = (int)iy;
    float fx = (float)ix;
    float fz = (float)iz;

    bool inside = false;
    if (fx >= r.minx && r.maxx >= fx && fz >= r.miny && r.maxy >= fz)
        inside = true;

    if (*(int*)v == 3) {
        if (inside) {
            sub_6e1670(this, v);
        } else {
            char buf[0x1c];
            sub_9ea40c(buf, (char*)this + 0x1dc);
            sub_6e1d60(this);
            this->shouldCaptureFocus = false;
            this->focused = false;
        }
    }

    if (this->shouldCaptureFocus) {
        *(int*)out = 1;
        *(int*)((char*)out + 4) = 0;
        *(int*)((char*)out + 8) = 0;
        *(void**)((char*)out + 0xc) = (char*)this + 0x94;
    } else {
        *(float*)out = r.minx;
        *(float*)((char*)out + 4) = r.miny;
        *(float*)((char*)out + 8) = r.maxx;
        *(float*)((char*)out + 0xc) = r.maxy;
    }
}
