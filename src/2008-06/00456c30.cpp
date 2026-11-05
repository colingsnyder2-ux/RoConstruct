// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdio.h>
#include <exception>

class CStr;
typedef void (__thiscall *StringDestroy)(CStr*);
extern StringDestroy destroyString;
extern const char* (__thiscall* stringText)(const CStr*);
class CStr {
public:
    __declspec(dllimport) CStr(const char* s);
    __declspec(dllimport) CStr(const CStr& s);
    ~CStr() throw() { destroyString(this); }
    __declspec(dllimport) operator const char*()const;
    char* m_pszData;
};
struct ImportedCStr {
    char* m_pszData;
    __declspec(dllimport) ~ImportedCStr()throw();
    operator const char*()const{return stringText(reinterpret_cast<const CStr*>(this));}
};
ImportedCStr operator+(const char* a,const CStr& b);
CStr operator+(const ImportedCStr& a,const char* b);
CStr getTimeString(bool full);
double now();

#include <intrin.h>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr():px(0),pn(){}
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){T* tmp=r.px;r.px=px;px=tmp;pn.swap(r.pn);}
    void reset(){shared_ptr().swap(*this);}
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}

struct StatsRoot;
struct StatsScope {
    StatsScope(boost::shared_ptr<StatsRoot> root);
    ~StatsScope();
    char pad[0xc];
};

struct ReportControl {
    virtual void rv0();
    virtual void rv1();
    virtual void rv2();
    virtual void rv3();
    virtual void rv4();
    virtual void rv5();
    virtual void rv6();
    virtual void rv7();
    virtual void rv8();
    virtual void rv9();
    virtual void rv10();
    virtual void rv11();
    virtual void rv12();
    virtual void rv13();
    virtual void rv14();
    virtual void rv15();
    virtual void rv16();
    virtual void rv17();
    virtual void rv18();
    virtual void rv19();
    virtual void rv20();
    virtual void rv21();
    virtual void rv22();
    virtual void rv23();
    virtual void rv24();
    virtual void rv25();
    virtual void rv26();
    virtual void rv27();
    virtual void rv28();
    virtual void rv29();
    virtual void rv30();
    virtual void rv31();
    virtual void rv32();
    virtual void rv33();
    virtual void rv34();
    virtual void rv35();
    virtual void rv36();
    virtual void rv37();
    virtual void rv38();
    virtual void rv39();
    virtual void rv40();
    virtual void rv41();
    virtual void rv42();
    virtual void rv43();
    virtual void rv44();
    virtual void rv45();
    virtual void rv46();
    virtual void rv47();
    virtual void rv48();
    virtual void rv49();
    virtual void rv50();
    virtual void rv51();
    virtual void rv52();
    virtual void rv53();
    virtual void rv54();
    virtual void rv55();
    virtual void rv56();
    virtual void rv57();
    virtual void rv58();
    virtual void rv59();
    virtual void rv60();
    virtual void rv61();
    virtual void rv62();
    virtual void rv63();
    virtual void rv64();
    virtual void rv65();
    virtual void rv66();
    virtual void rv67();
    virtual void rv68();
    virtual void rv69();
    virtual void rv70();
    virtual void rv71();
    virtual void rv72();
    virtual void rv73();
    virtual void rv74();
    virtual void rv75();
    virtual void rv76();
    virtual void rv77();
    virtual void rv78();
    virtual void rv79();
    virtual void rv80();
    virtual void rv81();
    virtual void rv82();
    virtual void rv83();
    virtual void rv84();
    virtual void rv85();
    virtual void rv86();
    virtual void rv87();
    virtual void Populate();
    char pad[0xe4];
    int m_e8;
    void RedrawControl();
};
extern bool g_benchmark;
extern double g_lastBenchmark;
extern float g_benchmarkInterval;
extern FILE* g_benchmarkFile;

class CRobloxReportView {
public:
    virtual void vv0();
    virtual void vv1();
    virtual void vv2();
    virtual void vv3();
    virtual void vv4();
    virtual void vv5();
    virtual void vv6();
    virtual void vv7();
    virtual void vv8();
    virtual void vv9();
    virtual void vv10();
    virtual void vv11();
    virtual void vv12();
    virtual void vv13();
    virtual void vv14();
    virtual void vv15();
    virtual void vv16();
    virtual void vv17();
    virtual void vv18();
    virtual void vv19();
    virtual void vv20();
    virtual void vv21();
    virtual void vv22();
    virtual void vv23();
    virtual void vv24();
    virtual void vv25();
    virtual void vv26();
    virtual void vv27();
    virtual void vv28();
    virtual void vv29();
    virtual void vv30();
    virtual void vv31();
    virtual void vv32();
    virtual void vv33();
    virtual void vv34();
    virtual void vv35();
    virtual void vv36();
    virtual void vv37();
    virtual void vv38();
    virtual void vv39();
    virtual void vv40();
    virtual void vv41();
    virtual void vv42();
    virtual void vv43();
    virtual void vv44();
    virtual void vv45();
    virtual void vv46();
    virtual void vv47();
    virtual void vv48();
    virtual void vv49();
    virtual void vv50();
    virtual void vv51();
    virtual void vv52();
    virtual void vv53();
    virtual void vv54();
    virtual void vv55();
    virtual void vv56();
    virtual void vv57();
    virtual void vv58();
    virtual void vv59();
    virtual void vv60();
    virtual void vv61();
    virtual void vv62();
    virtual void vv63();
    virtual void vv64();
    virtual void vv65();
    virtual void vv66();
    virtual void vv67();
    virtual void vv68();
    virtual void vv69();
    virtual void vv70();
    virtual void vv71();
    virtual void vv72();
    virtual void vv73();
    virtual void vv74();
    virtual void vv75();
    virtual void vv76();
    virtual void vv77();
    virtual void vv78();
    virtual void vv79();
    virtual void vv80();
    virtual void vv81();
    virtual void vv82();
    virtual void vv83();
    virtual void vv84();
    virtual void vv85();
    virtual void vv86();
    virtual void vv87();
    virtual void vv88();
    virtual void vv89();
    virtual void vv90();
    virtual void vv91();
    virtual void vv92();
    virtual void vv93();
    virtual void vv94();
    virtual void vv95();
    virtual void vv96();
    virtual void vv97();
    virtual void vv98();
    virtual void vv99();
    virtual void vv100();
    virtual ReportControl& GetReportCtrl();
    char pad[0x3c0];
    boost::shared_ptr<StatsRoot> m_stats;
    void writeBenchmark(int records, CStr extra);
    void refresh();
};

void CRobloxReportView::refresh()
{
    StatsScope scope(m_stats);
    GetReportCtrl().Populate();
    GetReportCtrl().RedrawControl();
    if (g_benchmark) {
        if (g_lastBenchmark < 0.0) {
            g_lastBenchmark = now();
        }
        else if (now() - g_lastBenchmark > g_benchmarkInterval * 1.01) {
            if (g_benchmarkFile == NULL) {
                CStr name = "c:\\roblox_bench_" + getTimeString(false) + ".txt";
                g_benchmarkFile = fopen(name, "wt");
                if (g_benchmarkFile == NULL)
                    throw std::exception("Cannot open benchmark file " + name);
            }
            int records = GetReportCtrl().m_e8;
            fprintf(g_benchmarkFile, "WallTime = %s\n", getTimeString(false));
            writeBenchmark(records, "");
            fflush(g_benchmarkFile);
        }
    }
}
