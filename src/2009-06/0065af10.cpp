// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Frame {
    float data[12];
    bool changed() const;
};
struct Ray {
    char data[0x44];
    Frame difference(const Frame& other) const;
    void setFrame(const Frame& other);
};
extern const char property;
extern bool __cdecl validateFrame(const Frame& frame);
struct Camera {
    char prefix[0x98];
    Ray ray;
    Frame frame;
    void notify(const char* property);
    void update();
};
void Camera::update()
{
    if (ray.difference(frame).changed()) {
        if (validateFrame(frame))
            ray.setFrame(frame);
        notify(&property);
    }
}
