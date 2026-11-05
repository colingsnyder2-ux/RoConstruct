// from server: 23% by colin
extern "C" int __cdecl memmove_s(void* dest, unsigned int destSize, const void* src, unsigned int count);
extern "C" void __cdecl operator_delete(void* p);

struct ParserArenaDeletable {
    virtual void destroy();
};

struct ParserArenaData : ParserArenaDeletable {
    void* data;
};

struct ParserArena {
    ParserArenaData* m_data;
    ParserArenaData** m_begin;
    ParserArenaData** m_end;
    ParserArenaData** m_capacity;
};

struct LDrawParser {
    int m_unknown0;
    int m_unknown1;
    int m_unknown2;
    int m_unknown3;
    int m_unknown4;
    int m_unknown5;
    int m_unknown6;
    int m_unknown7;
    int m_unknown8;
    ParserArena m_arena;
    int m_unknown9;

    void destroy();
};

void LDrawParser::destroy()
{
    m_unknown0 = 0x796370;

    ParserArenaData** begin = m_arena.m_begin;
    ParserArenaData** end = m_arena.m_end;
    int count = 0;
    if (begin == 0) {
        count = (int)(end - begin);
    }

    for (int i = 0; i < count; ++i) {
        ParserArenaData* item = m_arena.m_begin[i];
        if (item != 0) {
            item->destroy();
        }
    }

    ParserArenaData** oldBegin = m_arena.m_begin;
    ParserArenaData** oldEnd = m_arena.m_end;
    if (oldBegin != oldEnd) {
        int n = (int)(oldEnd - oldBegin);
        if (n > 0) {
            memmove_s(oldBegin, n * 4, oldEnd, n * 4);
        }
    }

    if (m_arena.m_begin != 0) {
        operator_delete(m_arena.m_begin);
    }
    m_arena.m_begin = 0;
    m_arena.m_end = 0;
    m_arena.m_capacity = 0;
}
