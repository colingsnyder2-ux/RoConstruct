// from server: 100% by EspClaude
// from server: 81% by EspClaude
// roc 2009-06 00668680  unit: RBX::Humanoid  size: 225 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00668680
//

// from server: 100% by king_originala
// roc 2008-06 005d9c30  unit: RBX::Humanoid  size: 222 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d9c30
//

struct Vector {
    float x, y, z;
};

struct Body {
    char padding[0x16c];
    float value;
};

struct Base {
    bool query(Vector*);
    Body* getBody();
};

struct Model {
    Base* getBase();
};

struct Receiver {
    void setCallback(void (__cdecl*)());
};

struct Delegate {
    void update(void*);
};

struct S {
    char padding0[0xbc];
    int state;
    char padding1[0x3c];
    Delegate* delegate;

    void update(void*);
};

extern char instanceType;
extern char modelType;
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern void* __cdecl getInstance(Base*);
extern int __cdecl checkBase(Base*);
extern void __cdecl applyVector(void*, Vector*);
extern void* __cdecl getReceiver(Base*);
extern void __cdecl callback();

void S::update(void* argument)
{
    if (state == 3) {
        Base* base = reinterpret_cast<Base*>(
            reinterpret_cast<char*>(this) - 0x12c);
        void* instance = getInstance(base);
        Base* owner;

        if (instance) {
            Model* model = static_cast<Model*>(
                __RTDynamicCast(instance, 0, &instanceType, &modelType, 0));
            if (model)
                owner = model->getBase();
            else
                owner = 0;
        } else {
            owner = 0;
        }

        if (reinterpret_cast<Base*>(
                reinterpret_cast<char*>(this) - 0x12c) == owner &&
            checkBase(base)) {
            Vector vector;
            vector.x = 0.0f;
            vector.y = 0.0f;
            vector.z = 0.0f;

            if (base->query(&vector)) {
                Body* body = base->getBody();
                if (body && body->value != 0.0f)
                    applyVector(argument, &vector);
            }

            Receiver* receiver = static_cast<Receiver*>(getReceiver(base));
            if (receiver)
                receiver->setCallback(callback);
        }
    }

    if (delegate)
        delegate->update(argument);
}
