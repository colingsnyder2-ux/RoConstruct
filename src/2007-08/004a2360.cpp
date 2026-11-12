// from server: 73% by EspClaude
// roc 2007-08 004a2360  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 471 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a2360
// 004a2360: std::vector<Elem>::_Insert_n (VS2005), Elem is 12 bytes (/12 magic 0x2aaaaaab),
// copied as {word0, px, pn} with an interlocked increment of pn+4 (boost shared_count use_count).
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#include <typeinfo>
#include <vector>

namespace boost {
    namespace detail {
        class sp_counted_base {
        public:
            virtual ~sp_counted_base() {}
            virtual void dispose() = 0;
            virtual void destroy() { delete this; }
            virtual void* get_deleter(const std::type_info& ti) = 0;
            void add_ref_copy() { _InterlockedIncrement(&use_count_); }
            void release()
            {
                if (_InterlockedDecrement(&use_count_) == 0) {
                    dispose();
                    weak_release();
                }
            }
            void weak_release()
            {
                if (_InterlockedDecrement(&weak_count_) == 0)
                    destroy();
            }
        private:
            long use_count_;
            long weak_count_;
        };
        class shared_count {
        public:
            shared_count() : pi_(0) {}
            shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
            ~shared_count() { if (pi_ != 0) pi_->release(); }
            shared_count& operator=(const shared_count& r)
            {
                sp_counted_base* tmp = r.pi_;
                if (tmp != pi_) {
                    if (tmp != 0) tmp->add_ref_copy();
                    if (pi_ != 0) pi_->release();
                    pi_ = tmp;
                }
                return *this;
            }
        private:
            sp_counted_base* pi_;
        };
    }
    template<class T> class shared_ptr {
    public:
        T* px;
        detail::shared_count pn;
    };
}

namespace RBX { class Instance; }

struct Elem {
    int key;
    boost::shared_ptr<RBX::Instance> value;
};

template class std::vector<Elem>;
