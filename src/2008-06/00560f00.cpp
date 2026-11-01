// from server: 100% by king_originala
extern void *__cdecl operator new(unsigned int);
extern void __cdecl operator delete(void *);

struct TypeInfo;
extern TypeInfo targetType;
extern bool (__thiscall *typeEqual)(const void *, const TypeInfo *);

typedef void (__cdecl *Manager)(void *, void *, int);

struct Block {
    char reserved[8];
    Manager *manager;
    char padding[4];
    char payload[24];
};

extern void __cdecl copyBlock(Block *, const void *);

void __cdecl manage(const void *const *source, void **destination, int operation)
{
    if (operation == 0) {
        const void *value = *source;
        Block *block = static_cast<Block *>(operator new(40));
        copyBlock(block, value);
        *destination = block;
    } else if (operation == 1) {
        Block *block = static_cast<Block *>(*destination);
        if (block->manager) {
            Manager callback = *block->manager;
            void *payload = block->payload;
            if (callback)
                callback(payload, payload, 1);
            block->manager = 0;
        }
        operator delete(block);
        *destination = 0;
    } else {
        if (typeEqual(*destination, &targetType))
            *destination = const_cast<void *>(*source);
        else
            *destination = 0;
    }
}
