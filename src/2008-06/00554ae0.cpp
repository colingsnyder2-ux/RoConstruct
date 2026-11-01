// from server: 100% by Gemini
#include <vector>

struct S {
    struct Cursor {
        size_t index;
        size_t limit;
        Cursor* previous;
    };

    virtual ~S();
    mutable std::vector<void*> listeners;
    mutable Cursor* current;

    void invoke(int argument, void* element) const;
    void run(int argument) const throw();
};

void S::run(int argument) const throw()
{
    Cursor cursor = { 0, listeners.size(), current };
    current = &cursor;

    while (cursor.index < cursor.limit) {
        invoke(argument, listeners[cursor.index++]);
    }

    current = cursor.previous;
}
