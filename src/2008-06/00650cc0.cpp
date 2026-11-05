// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_chatdeque311480eb0dd59e60.cpp

// Candidate translation unit (score above; library headers required).
#include <deque>
#include <string>
typedef std::string String;
struct Player {
    char padding[0x1B1];
    bool disabled;
};

struct Message {
    String first;
    String text;
    Player* sender;
    unsigned int extra[3];

    Message(const Message&);
    ~Message();
};

struct Settings {
    char padding[0x134];
    unsigned int limit;
};

Settings* __cdecl getSettings();
extern float lifetime;

struct Owner {
    char padding[0x1A0];
    Player* player;
};

struct Filter {
    char storage[0x20];
    bool check(String);
};

struct Entry {
    char storage[0x48];
    bool flag;
    char padding[3];

    Entry(Player*, const String&, float);
};

struct Queue {
    char storage[0x1C];
    void append(Entry* const&);
};

struct Base {
    void removeOldest();
    bool command(Message);
};

struct S {
    char padding[0x0C];
    Owner* owner;
    Filter filter;
    std::deque<Entry*> queue;
    float time;

    void f(unsigned int, Message);
};

#pragma float_control(precise, off)

void S::f(unsigned int, Message message)
{
    unsigned int current = queue.size();
    while (current > getSettings()->limit) {
        reinterpret_cast<Base*>(reinterpret_cast<char*>(this) - 0x144)->removeOldest();
        current = queue.size();
    }

    if (message.text.size() > 0) {
        const char* text = message.text.c_str();
        if (text[0] == '/') {
            if (reinterpret_cast<Base*>(reinterpret_cast<char*>(this) - 0x144)->command(message) == true)
                return;
        }
    }

    Player* player=owner->player;
    if(!player || !player->disabled) {
        bool accepted=filter.check(message.text);
        if(!player || message.sender==player || !accepted) {
            Entry* entry=new Entry(message.sender,message.text,time+lifetime);
            entry->flag=false;
            queue.push_back(entry);
        }
    }
}
