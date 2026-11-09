// from server: 100% by EspClaude
// from server: 86% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Vec3i { int x, y, z; };
namespace RBX {
    class MotorJoint {
        char pad[0xa8];
        bool a, b, c;
    public:
        bool isActive() const;
    };
}
extern int levelCount;
extern int baseSize;
extern int sizeLimit;
extern void __cdecl calculateBounds(int, const void *, Vec3i *, Vec3i *);
#define VOL ((maximum->x - minimum->x + 1) * (maximum->y - minimum->y + 1) * (maximum->z - minimum->z + 1))
void __cdecl selectLevel(int *level, const RBX::MotorJoint *joint, const void *input, Vec3i *minimum, Vec3i *maximum)
{
    for (*level = 0; calculateBounds(*level, input, minimum, maximum), VOL > 100; ) {
        int current = *level;
        if (current >= levelCount - 1) break;
        if (joint->isActive() && (double)(baseSize << current) == (double)sizeLimit) break;
        *level = current + 1;
    }
}
