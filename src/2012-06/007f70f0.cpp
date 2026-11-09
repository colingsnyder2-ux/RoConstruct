// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_abusequeue223a29824c868e18.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
#include <queue>
#include <boost/shared_ptr.hpp>
#include <string>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/thread/mutex.hpp>
struct ChatMessage{std::string first,second;void* owner;};
struct Report{int submitter,abuser;std::string comment;struct Message{int id;std::string first,second;};std::list<Message> messages;void add(const ChatMessage&);};
struct Object{std::queue<Report> queue;boost::mutex mutex;};
struct Completion{void finish();};
struct S{boost::shared_ptr<Object> object;Completion* completion;void f(Report&,const std::list<ChatMessage>&);};
void S::f(Report& value,const std::list<ChatMessage>& args){std::for_each(args.begin(),args.end(),boost::bind(&Report::add,boost::ref(value),_1));{boost::mutex::scoped_lock guard(object->mutex);object->queue.push(value);}completion->finish();}
