// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <new>
namespace G3D {
const bool DONT_SHRINK_UNDERLYING_ARRAY = false;
template<class T>
class Array {
private:
    T*              data;
    int             num;
    int             numAllocated;
    bool inArray(const T* address) {
        return (address >= data) && (address < data + num);
    }
public:
    void resize(int n, bool shrinkIfNecessary);
    inline void append(const T& value) {
        if (num < numAllocated) {
            new (data + num) T(value);
            ++num;
        } else if (inArray(&value)) {
            T tmp = value;
            append(tmp);
        } else {
            resize(num + 1, DONT_SHRINK_UNDERLYING_ARRAY);
            data[num - 1] = value;
        }
    }
    inline void push(const T& value) {
        append(value);
    }
};
class TextOutput {
public:
    class Options {
    public:
        enum WordWrapMode {WRAP_NONE, WRAP_WITHOUT_BREAKING, WRAP_ALWAYS};
        WordWrapMode        wordWrap;
        bool                allowWordWrapInsideDoubleQuotes;
        int                 numColumns;
        int                 spacesPerIndent;
        enum NewlineStyle {NEWLINE_WINDOWS, NEWLINE_UNIX};
        NewlineStyle        newlineStyle;
        bool                convertNewlines;
        std::string         trueSymbol;
        std::string         falseSymbol;
        int                 extra;
    };
private:
    bool                    startingNewLine;
    int                     currentColumn;
    bool                    inDQuote;
    std::string             filename;
    Array<char>             data;
    Options                 option;
    int                     indentLevel;
    int                     indentSpaces;
    std::string             newline;
    void indentAppend(char c);
};
void TextOutput::indentAppend(char c) {
    if (startingNewLine) {
        for (int j = 0; j < indentSpaces; ++j) {
            data.push(' ');
        }
        startingNewLine = false;
        currentColumn = indentSpaces;
    }
    data.push(c);
    if (c != '\r') {
        ++currentColumn;
    }
    if (c == '\"') {
        inDQuote = ! inDQuote;
    }
    startingNewLine = (c == '\n');
    if (startingNewLine) {
        currentColumn = 0;
    }
}
}
