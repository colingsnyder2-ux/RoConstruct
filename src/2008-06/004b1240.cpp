// from server: 100% by EspClaude
// from server: 99% by Espeon
// roc 2008-06 004b1240  unit: RBX::Network::Server::ClientProxy  size: 625 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b1240
//
// 004b1240  64a100000000         mov eax, dword ptr fs:[0]
// 004b1246  6aff                 push -1
// 004b1248  68d0867c00           push 0x7c86d0
// 004b124d  50                   push eax
// 004b124e  64892500000000       mov dword ptr fs:[0], esp
// 004b1255  83ec50               sub esp, 0x50
// 004b1258  56                   push esi
// 004b1259  57                   push edi
// 004b125a  8b7c2468             mov edi, dword ptr [esp + 0x68]
// 004b125e  57                   push edi
// 004b125f  8bf1                 mov esi, ecx
// 004b1261  e88aab2500           call 0x70bdf0
// 004b1266  8b8690d5ffff         mov eax, dword ptr [esi - 0x2a70]
// 004b126c  85c0                 test eax, eax
// 004b126e  0f842a020000         je 0x4b149e
// 004b1274  8b86a8010000         mov eax, dword ptr [esi + 0x1a8]
// 004b127a  6a00                 push 0
// 004b127c  50                   push eax
// 004b127d  8d4c2448             lea ecx, [esp + 0x48]
// 004b1281  e8fa2c1100           call 0x5c3f80
// 004b1286  c744246000000000     mov dword ptr [esp + 0x60], 0
// 004b128e  e87d710500           call 0x508410
// 004b1293  dd5c2408             fstp qword ptr [esp + 8]
// 004b1297  e8f4d5feff           call 0x49e890
// 004b129c  d9e8                 fld1 
// 004b129e  d8b050010000         fdiv dword ptr [eax + 0x150]
// 004b12a4  dc4604               fadd qword ptr [esi + 4]
// 004b12a7  dc5c2408             fcomp qword ptr [esp + 8]
// 004b12ab  dfe0                 fnstsw ax
// 004b12ad  f6c405               test ah, 5
// 004b12b0  0f8ad7010000         jp 0x4b148d
// 004b12b6  53                   push ebx
// 004b12b7  8a9e5c010000         mov bl, byte ptr [esi + 0x15c]
// 004b12bd  885c246c             mov byte ptr [esp + 0x6c], bl
// 004b12c1  84db                 test bl, bl
// 004b12c3  7454                 je 0x4b1319
// 004b12c5  8b86bc010000         mov eax, dword ptr [esi + 0x1bc]
// 004b12cb  6a00                 push 0
// 004b12cd  50                   push eax
// 004b12ce  8d4c2434             lea ecx, [esp + 0x34]
// 004b12d2  e8a92c1100           call 0x5c3f80
// 004b12d7  8b86c0010000         mov eax, dword ptr [esi + 0x1c0]
// 004b12dd  6a00                 push 0
// 004b12df  50                   push eax
// 004b12e0  8d4c241c             lea ecx, [esp + 0x1c]
// 004b12e4  c644246c01           mov byte ptr [esp + 0x6c], 1
// 004b12e9  e8922c1100           call 0x5c3f80
// 004b12ee  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004b12f1  8b01                 mov eax, dword ptr [ecx]
// 004b12f3  8b5004               mov edx, dword ptr [eax + 4]
// 004b12f6  c644246402           mov byte ptr [esp + 0x64], 2
// 004b12fb  ffd2                 call edx
// 004b12fd  8d4c2414             lea ecx, [esp + 0x14]
// 004b1301  c644246401           mov byte ptr [esp + 0x64], 1
// 004b1306  e8c52f1100           call 0x5c42d0
// 004b130b  8d4c242c             lea ecx, [esp + 0x2c]
// 004b130f  c644246400           mov byte ptr [esp + 0x64], 0
// 004b1314  e8b72f1100           call 0x5c42d0
// 004b1319  8b8ee4010000         mov ecx, dword ptr [esi + 0x1e4]
// 004b131f  8b07                 mov eax, dword ptr [edi]
// 004b1321  8b96e0010000         mov edx, dword ptr [esi + 0x1e0]
// 004b1327  8b800c010000         mov eax, dword ptr [eax + 0x10c]
// 004b132d  51                   push ecx
// 004b132e  52                   push edx
// 004b132f  8bcf                 mov ecx, edi
// 004b1331  ffd0                 call eax
// 004b1333  8bf8                 mov edi, eax
// 004b1335  85ff                 test edi, edi
// 004b1337  0f8412010000         je 0x4b144f
// 004b133d  8b9794000000         mov edx, dword ptr [edi + 0x94]
// 004b1343  8b8ec8010000         mov ecx, dword ptr [esi + 0x1c8]
// 004b1349  55                   push ebp
// 004b134a  52                   push edx
// 004b134b  e8802c1100           call 0x5c3fd0
// 004b1350  8b4778               mov eax, dword ptr [edi + 0x78]
// 004b1353  8b8ecc010000         mov ecx, dword ptr [esi + 0x1cc]
// 004b1359  50                   push eax
// 004b135a  e8712c1100           call 0x5c3fd0
// 004b135f  8b5764               mov edx, dword ptr [edi + 0x64]
// 004b1362  8b8ed0010000         mov ecx, dword ptr [esi + 0x1d0]
// 004b1368  52                   push edx
// 004b1369  e8622c1100           call 0x5c3fd0
// 004b136e  8b4768               mov eax, dword ptr [edi + 0x68]
// 004b1371  8b8ed4010000         mov ecx, dword ptr [esi + 0x1d4]
// 004b1377  50                   push eax
// 004b1378  e8532c1100           call 0x5c3fd0
// 004b137d  e80ed5feff           call 0x49e890
// 004b1382  8b4f08               mov ecx, dword ptr [edi + 8]
// 004b1385  034f04               add ecx, dword ptr [edi + 4]
// 004b1388  8ba84c010000         mov ebp, dword ptr [eax + 0x14c]
// 004b138e  2be9                 sub ebp, ecx
// 004b1390  83fd01               cmp ebp, 1
// 004b1393  7c48                 jl 0x4b13dd
// 004b1395  80bfc400000000       cmp byte ptr [edi + 0xc4], 0
// 004b139c  753f                 jne 0x4b13dd
// 004b139e  84db                 test bl, bl
// 004b13a0  740f                 je 0x4b13b1
// 004b13a2  6a01                 push 1
// 004b13a4  8d8e8cd4ffff         lea ecx, [esi - 0x2b74]
// 004b13aa  e811a6ffff           call 0x4ab9c0
// 004b13af  2be8                 sub ebp, eax
// 004b13b1  8d9e8cd4ffff         lea ebx, [esi - 0x2b74]
// 004b13b7  8bcb                 mov ecx, ebx
// 004b13b9  e8b2fbffff           call 0x4b0f70
// 004b13be  84c0                 test al, al
// 004b13c0  7401                 je 0x4b13c3
// 004b13c2  4d                   dec ebp
// 004b13c3  807c247000           cmp byte ptr [esp + 0x70], 0
// 004b13c8  7408                 je 0x4b13d2
// 004b13ca  55                   push ebp
// 004b13cb  8bcb                 mov ecx, ebx
// 004b13cd  e8eea5ffff           call 0x4ab9c0
// 004b13d2  dd442410             fld qword ptr [esp + 0x10]
// 004b13d6  8a5c2470             mov bl, byte ptr [esp + 0x70]
// 004b13da  dd5e04               fstp qword ptr [esi + 4]
// 004b13dd  e8aed4feff           call 0x49e890
// 004b13e2  80b83301000000       cmp byte ptr [eax + 0x133], 0
// 004b13e9  5d                   pop ebp
// 004b13ea  7463                 je 0x4b144f
// 004b13ec  8b5704               mov edx, dword ptr [edi + 4]
// 004b13ef  8b4708               mov eax, dword ptr [edi + 8]
// 004b13f2  8d3c50               lea edi, [eax + edx*2]
// 004b13f5  e896d4feff           call 0x49e890
// 004b13fa  3bb84c010000         cmp edi, dword ptr [eax + 0x14c]
// 004b1400  7619                 jbe 0x4b141b
// 004b1402  8d4c240c             lea ecx, [esp + 0xc]
// 004b1406  51                   push ecx
// 004b1407  e814820b00           call 0x569620
// 004b140c  57                   push edi
// 004b140d  68684b8200           push 0x824b68
// 004b1412  c644247003           mov byte ptr [esp + 0x70], 3
// 004b1417  6a02                 push 2
// 004b1419  eb1b                 jmp 0x4b1436
// 004b141b  85ff                 test edi, edi
// 004b141d  7630                 jbe 0x4b144f
// 004b141f  8d54240c             lea edx, [esp + 0xc]
// 004b1423  52                   push edx
// 004b1424  e8f7810b00           call 0x569620
// 004b1429  57                   push edi
// 004b142a  68684b8200           push 0x824b68
// 004b142f  c644247004           mov byte ptr [esp + 0x70], 4
// 004b1434  6a01                 push 1
// 004b1436  8b00                 mov eax, dword ptr [eax]
// 004b1438  50                   push eax
// 004b1439  e8627f0b00           call 0x5693a0
// 004b143e  83c414               add esp, 0x14
// 004b1441  8d4c240c             lea ecx, [esp + 0xc]
// 004b1445  c644246400           mov byte ptr [esp + 0x64], 0
// 004b144a  e811f21400           call 0x600660
// 004b144f  84db                 test bl, bl
// 004b1451  5b                   pop ebx
// 004b1452  7539                 jne 0x4b148d
// 004b1454  8b86b8010000         mov eax, dword ptr [esi + 0x1b8]
// 004b145a  6a00                 push 0
// 004b145c  50                   push eax
// 004b145d  8d4c2430             lea ecx, [esp + 0x30]
// 004b1461  e81a2b1100           call 0x5c3f80
// 004b1466  8b7610               mov esi, dword ptr [esi + 0x10]
// 004b1469  8b3e                 mov edi, dword ptr [esi]
// 004b146b  c644246005           mov byte ptr [esp + 0x60], 5
// 004b1470  83c704               add edi, 4
// 004b1473  e898840100           call 0x4c9910
// 004b1478  50                   push eax
// 004b1479  8b07                 mov eax, dword ptr [edi]
// 004b147b  8bce                 mov ecx, esi
// 004b147d  ffd0                 call eax
// 004b147f  8d4c2428             lea ecx, [esp + 0x28]
// 004b1483  c644246000           mov byte ptr [esp + 0x60], 0
// 004b1488  e8432e1100           call 0x5c42d0
// 004b148d  8d4c2440             lea ecx, [esp + 0x40]
// 004b1491  c7442460ffffffff     mov dword ptr [esp + 0x60], 0xffffffff
// 004b1499  e8322e1100           call 0x5c42d0
// 004b149e  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 004b14a2  5f                   pop edi
// 004b14a3  5e                   pop esi
// 004b14a4  64890d00000000       mov dword ptr fs:[0], ecx
// 004b14ab  83c45c               add esp, 0x5c
// 004b14ae  c20400               ret 4

// from server: 97% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <intrin.h>
#include <utility>
namespace boost {
namespace detail {
struct sp_counted_base {
    sp_counted_base():use_count_(1),weak_count_(1){}
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
template<class Y>struct sp_counted_impl_p:sp_counted_base {Y*pointer;explicit sp_counted_impl_p(Y*p):pointer(p){}void dispose(){delete pointer;}};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    template<class Y> __declspec(noinline) explicit shared_count(Y*p):pi_(0){try{pi_=new sp_counted_impl_p<Y>(p);}catch(...){delete p;throw;}}
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
namespace detail {inline void sp_enable_shared_from_this(const shared_count&,...) {}}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr():px(0),pn(){}
    template<class Y> explicit shared_ptr(Y*p):px(p),pn(p){detail::sp_enable_shared_from_this(pn,p,p);}
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
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


struct CodeProfiler {void sample(unsigned);};
struct ProfileMark {CodeProfiler*section;void*previous;bool frameTick;double startTime;ProfileMark(CodeProfiler&,bool);~ProfileMark();};
template<class T>struct ScopedPtr {T*pointer;T&operator*()const{return *pointer;}T*operator->()const{return pointer;}};
struct StandardOut {void __cdecl print(int,const char*,...);static boost::shared_ptr<StandardOut> singleton();};
struct Settings {char prefix[0x133];bool printPacketBuffer;char gap[0x14c-0x134];int maxDataModelSendBuffer;float sendRate;};
Settings&settings();
double __cdecl localTime();
unsigned __cdecl networkTime();
struct SystemAddress {unsigned address;unsigned short port;};
struct NetworkStatistics {unsigned messageSendBuffer[4];char prefix[0x64-16];unsigned field64,field68;char to78[0x78-0x6c];unsigned field78;char to94[0x94-0x7c];unsigned field94;char toc4[0xc4-0x98];bool bandwidthExceeded;};
struct Peer {void**vtable;NetworkStatistics*GetStatistics(SystemAddress a){typedef NetworkStatistics*(__thiscall*Fn)(Peer*,SystemAddress);return reinterpret_cast<Fn>(vtable[0x10c/4])(this,a);}};
struct Sender {void**vtable;void step(){typedef void(__thiscall*Fn)(Sender*);reinterpret_cast<Fn>(vtable[1])(this);}};
struct Receiver {typedef void(__thiscall*Step)(Receiver*,unsigned); Step* vtable;};
struct Primary {virtual ~Primary();char toParent[0x104-4];void*parent;void*getParent()const{return parent;}char rest[0x2b74-0x108];};
struct Plugin {virtual ~Plugin();virtual void OnAttach(Peer*);virtual void OnDetach(Peer*);virtual void OnStartup(Peer*);virtual void Update(Peer*);};
struct Replicator:Primary,Plugin {
 double lastSendTime;Sender*sender;Receiver*receiver;
 char toEnabled[0x15c-0x14];bool sendPhysicsEnabled;
 char toProfile[0x1a8-0x15d];ScopedPtr<CodeProfiler>profileReplication;
 char toBusy[0x1b8-0x1ac];ScopedPtr<CodeProfiler>profileReceive,profileSend,profilePhysics;
 char toCounters[4];ScopedPtr<CodeProfiler>counter94,counter78,counter64,counter68;
 char toAddress[8];SystemAddress remotePlayerId;
 int sendItems(int);bool sendPhysicsPacket();
 virtual void Update(Peer*);
};
void Replicator::Update(Peer*peer){
 Plugin::Update(peer);
 if(getParent()){
  ProfileMark mark(*profileReplication,false);
  double t=localTime();
  if(1.0f/settings().sendRate+lastSendTime<t){
   bool enabled=sendPhysicsEnabled;
   if(enabled){ProfileMark m1(*profileSend,false);ProfileMark m2(*profilePhysics,false);sender->step();}
   NetworkStatistics*statistics=peer->GetStatistics(remotePlayerId);
   if(statistics){
    counter94->sample(statistics->field94);counter78->sample(statistics->field78);counter64->sample(statistics->field64);counter68->sample(statistics->field68);
    int available=settings().maxDataModelSendBuffer;available-=statistics->messageSendBuffer[2]+statistics->messageSendBuffer[1];
    if(available>=1&&!statistics->bandwidthExceeded){
     if(enabled)available-=sendItems(1);
     if(sendPhysicsPacket())--available;
     if(enabled)sendItems(available);
     lastSendTime=t;
    }
    if(settings().printPacketBuffer){
     unsigned buffer=statistics->messageSendBuffer[2]+statistics->messageSendBuffer[1]*2;
     if(buffer>static_cast<unsigned>(settings().maxDataModelSendBuffer))StandardOut::singleton()->print(2,"SendBuffer = %d",buffer);
     else if(buffer>0)StandardOut::singleton()->print(1,"SendBuffer = %d",buffer);
    }
   }
   if(!enabled){ProfileMark receive(*profileReceive,false);Receiver*target=receiver; Receiver::Step* slot=&target->vtable[1]; unsigned time=networkTime(); (*slot)(target,time);}
  }
 }
}
