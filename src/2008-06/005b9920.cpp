// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Frame {
    unsigned char padding[0x24];
    Vector3 position;
};

struct Body {
    unsigned char padding[0xc4];
    Vector3 value;
    void updatePV();
};

struct PartInstance {
    unsigned char padding[0x2c8];
    Body *body;

    const Frame &getFrame();
    const Vector3 &getValue();
};

bool __cdecl convertVector(const Vector3 &, Vector3 *);
extern "C" int __stdcall setAttributes(int, const Vector3 *, const Vector3 *);
void __cdecl checkResult(int);

struct SoundChannel {
    unsigned char padding[0x165];
    unsigned char flags;
    unsigned char reserved[6];
    PartInstance *part;

    void update(int channel);
};

void SoundChannel::update(int channel)
{
    Vector3 position;
    Vector3 velocity;

    if ((flags & 1) && part) {
        if (convertVector(part->getFrame().position, &position)) {
            if (convertVector(part->getValue(), &velocity)) {
                checkResult(setAttributes(channel, &position, &velocity));
            }
        }
    }
}
