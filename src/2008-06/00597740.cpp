// from server: 100% by colin
struct TypeInfo {
    void *table;
    void *cache;
    const char *name;
};

typedef bool (__thiscall *TypeEqual)(const TypeInfo *, const TypeInfo *);
extern TypeEqual equalType;
extern const TypeInfo emptyType;
extern const TypeInfo soundType;
extern const TypeInfo stringType;

struct String;
extern void (__thiscall *destroyString)(String *);

struct String {
    void *proxy;
    union {
        char buffer[16];
        char *pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    ~String();
};

inline String::~String()
{
    destroyString(this);
}

struct SoundId : String {
    unsigned int extra;

    SoundId();
};

struct NamedType {
    void *table;
    String name;
};

struct Descriptor {
    void *field0;
    void *field4;
    const TypeInfo *type;
    NamedType *name;
};

struct Holder {
    virtual ~Holder();
    virtual const TypeInfo &type() const;
};

struct Value {
    Holder *content;
    void assign(const SoundId &);
};

struct CastError {
    void *table;
    const char *description;
    int ownsDescription;
    String message;

    CastError(const String &);
    CastError(const CastError &);
    ~CastError();
};

extern Descriptor *getSoundDescriptor();
extern String *getString(Value *);
extern bool convertSound(const String &, SoundId &);
extern void *getSound(Value *);
extern String formatMessage(const char *, ...);

struct Product {
    Descriptor *descriptor;
    Value value;

    void *castSound();
};

void *Product::castSound()
{
    TypeEqual compare = equalType;
    Value *source = &value;
    if (source) {
        const TypeInfo &type = source->content
            ? source->content->type()
            : emptyType;
        if (compare(&type, &soundType)) {
            void *result = reinterpret_cast<char *>(source->content) + 4;
            if (result)
                return result;
        }
    }

    const TypeInfo *sourceType = descriptor->type;
    if (compare(&stringType, sourceType)) {
        SoundId converted;
        if (convertSound(*getString(source), converted)) {
            source->assign(converted);
            descriptor = getSoundDescriptor();
            return getSound(source);
        }
    }

    String *targetName = &getSoundDescriptor()->name->name;
    const char *target = targetName->capacity >= 16
        ? targetName->storage.pointer
        : targetName->storage.buffer;

    String *sourceName = &descriptor->name->name;
    const char *origin = sourceName->capacity >= 16
        ? sourceName->storage.pointer
        : sourceName->storage.buffer;

    throw CastError(formatMessage("Unable to cast %s to %s", origin, target));
}
