// from server: 100% by king_originala
struct Frame {
    char data[48];
    Frame();
};

extern float value8249f8;
extern float value82711c;

extern const float* __cdecl camera5149f0();
extern void __cdecl draw6773f0(
    void*, const Frame*, int, float, float, const float*);

struct Hole {
    bool check60a490(Frame*);
    void render(void*);
};

void Hole::render(void* context)
{
    Frame frame;
    Hole* base = reinterpret_cast<Hole*>(
        reinterpret_cast<char*>(this) - 0x130);

    if (base->check60a490(&frame))
        draw6773f0(context, &frame, 2,
                   value8249f8, value82711c, camera5149f0());
}
