// from server: 100% by king_originala
struct S;
struct Appearance {
    void update();
};

struct VTable {
    void* slots[16];
    void (__thiscall *apply)(S*, void*);
};

struct S {
    VTable* table;
    char padding[256];
    void* appearance;

    void base(S**);
    void changed(S**);
};

extern char clothingType;
extern char appearanceType;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);
extern int __cdecl sub_495e80(int, int);
extern void* __cdecl lookup(void*);

void S::changed(S** value)
{
    base(value);
    if (*value == this) {
        Appearance* p = (Appearance*)__RTDynamicCast(
            this, 0, &clothingType, &appearanceType, 0);
        if (p) {
            p->update();
            return;
        }
        if ((unsigned char)sub_495e80((int)this, 0)) {
            void* result = lookup(appearance);
            if (result)
                table->apply(this, result);
        }
    }
}
