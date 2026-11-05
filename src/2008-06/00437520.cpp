// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_outputqueuenativelock7ef21b1281c34c21.cpp

// Candidate translation unit (score above; library headers required).
// roc-flags: /O2 /GS- /EHsc /MD
#include <deque>
#include <time.h>

template <class T> class bstr {
public:
    __declspec(noinline) bstr() { _Mysize = 0; }
    __declspec(noinline) ~bstr() { _Mysize = 0; }
    __declspec(noinline) bstr& operator=(const bstr& r) { _Mysize = r._Mysize; return *this; }
    __declspec(noinline) const T* c_str() const { return _Buf; }
    void* _Myaux;
    T _Buf[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};
extern template class __declspec(dllimport) bstr<char>;
typedef bstr<char> string_;

#include <boost/thread/mutex.hpp>
typedef boost::mutex mutex;
typedef boost::mutex::scoped_lock scoped_lock;

struct OutputItem {
    int type;
    string_ message;
    __time64_t time;
};

class CStandardOutputView {
public:
    char pad0[0x124];
    std::deque<OutputItem> items;
    mutex itemsMutex;
    void appendText(int type, const char* text, __time64_t time);
    long OnAppendText(unsigned int wParam, long lParam);
};

long CStandardOutputView::OnAppendText(unsigned int, long)
{
    while (true) {
        string_ message;
        int type;
        __time64_t time;
        {
            scoped_lock lock(itemsMutex);
            if (items.empty())
                return 0;
            if (items.size() > 250) {
                items.pop_front();
                continue;
            }
            type = items.front().type;
            message = items.front().message;
            time = items.front().time;
            items.pop_front();
        }
        appendText(type, message.c_str(), time);
    }
    return 0;
}
