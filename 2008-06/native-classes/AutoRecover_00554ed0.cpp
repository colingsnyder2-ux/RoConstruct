// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers were provided, so the boost/RBX types are declared locally.
// They are minimal and only match the mangled names and offsets seen in the disassembly.
namespace RBX {
    double getRealTime();
}

namespace boost {
    struct xtime {
        long long sec;
        int nsec;
    };
    int xtime_get(xtime* t, int base);

    namespace detail { namespace thread {
        template <class M> class scoped_lock;
    } }

    class mutex {
    public:
        char data[12];
    private:
        template <class M> friend class detail::thread::scoped_lock;
        void do_lock();
        void do_unlock();
    };

    namespace detail { namespace thread {
        template <class M>
        class scoped_lock {
        public:
            explicit scoped_lock(M& m) : m_mutex(m), m_locked(false) {
                m_mutex.do_lock();
                m_locked = true;
            }
            ~scoped_lock() {
                if (m_locked)
                    m_mutex.do_unlock();
            }
        private:
            M& m_mutex;
            bool m_locked;
        };
    } }

    class condition {
    public:
        template <class L>
        bool timed_wait(L& lock, const xtime& xt);
        char data[92];
    };
}

// INFERRED: layout reconstructed from offsets only; the real class is unknown.
struct WaitOwner {
    char pad0[0x1d0];
    double lastWaitTime;                 // +0x1d0
    char pad1[0x240 - 0x1d8];
    boost::mutex mtx;                    // +0x240
    boost::condition cond;               // +0x24c
    int pendingFlag;                     // +0x2a8
};

extern "C" bool __fastcall fn_00554ed0(WaitOwner* self, int unusedEdx)
{
    double start = RBX::getRealTime();

    boost::xtime xt;
    boost::xtime_get(&xt, 1);
    xt.sec += 1;

    bool result = false;
    {
        boost::detail::thread::scoped_lock<boost::mutex> lock(self->mtx);

        if (self->pendingFlag == 0) {
            result = true;
        } else {
            if (self->cond.timed_wait(lock, xt))
                result = true;
        }

        self->lastWaitTime = RBX::getRealTime() - start;
    }
    return result;
}
