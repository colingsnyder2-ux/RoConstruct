// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <exception>
#include <stdlib.h>

template<class E> struct ImpStr : std::basic_string<E> { __declspec(noinline) const E* c_str() const { return std::basic_string<E>::c_str(); } };
extern template struct __declspec(dllimport) ImpStr<char>;
static inline const char* cstr(const std::string& x) { return static_cast<const ImpStr<char>&>(x).c_str(); }

struct Parser
{
    std::string first;
    std::string second;
    Parser(const std::string& src) : first(src), second() {}
    void parse(std::string&);           // 0x569ae0
};

template <typename T>
const T& minimum(const T& a, const T& b)
{
    return b < a ? b : a;
}

struct Duration { __int64 v; Duration(__int64 x) : v(x) {} };
struct Time { __int64 v; __int64 w; Time& operator+=(const Duration& d) { v += d.v; return *this; } };
struct Out;
struct Tmp
{
    Out* px;
    void* pn;
    Out& operator*() const { return *px; }
    ~Tmp();                            // 0x600660
};

std::string __cdecl format(const char* fmt, ...);                           // 0x509b10
Tmp __cdecl tmp_lookup();                                                    // 0x569620
void __cdecl log_event(Out& v, int kind, const char* text);                   // 0x5693a0
void __cdecl query_counter(Time* out, int flag);                          // 0x5a6b40
void __cdecl submit_counter(Time* acc);                                   // 0x5a6870

int __cdecl function_00427480(std::string input)
{
    int result = 5;
    Time acc;
    try
    {
        std::string output;
        {
            Parser parser(input);
            parser.parse(output);
        }
        result = atoi(cstr(output));
    }
    catch (std::exception& e)
    {
        std::string msg = format("renewLogin %s failed: %s", static_cast<const ImpStr<char>&>(input).c_str(), e.what());
        log_event(*tmp_lookup(), 2, static_cast<const ImpStr<char>&>(msg).c_str());
    }
    result = result <= 0 ? 1 : minimum(result, 30);
    query_counter(&acc, 1);
    acc += Duration(result * 60);
    submit_counter(&acc);
    return 1;
}
