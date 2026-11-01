// from server: 100% by king_originala
struct Frame {
    char data[48];
};

struct Subject;

struct SubjectTable {
    void* unused[4];
    bool (__thiscall *update)(Subject*, float, Frame*, Frame*);
};

struct Subject {
    SubjectTable* table;
};

extern char instanceType;
extern char cameraSubjectType;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

struct Camera {
    char padding[0x174];
    Frame first;
    Frame second;
    int mode;
    int reserved;
    void* subject;

    bool update(float);
    bool follow(float);
    bool fallback(float);
};

bool Camera::update(float dt)
{
    if (mode == 5) {
        if (subject) {
            Subject* target = static_cast<Subject*>(
                __RTDynamicCast(subject, 0,
                                &instanceType, &cameraSubjectType, 0));
            if (target)
                return target->table->update(target, dt, &first, &second);
        }
        return false;
    }

    if (subject && (mode == 4 || mode == 1 || mode == 3))
        return follow(dt);

    return fallback(dt);
}
