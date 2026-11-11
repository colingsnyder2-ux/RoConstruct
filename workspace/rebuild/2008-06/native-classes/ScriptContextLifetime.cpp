// >>> native-status (generated) -- do not edit >>>
// ScriptContextLifetime | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 6eb54c57 | roc native-status --write
#include "script/ScriptContext.h"
#include <boost/date_time/posix_time/posix_time.hpp>
RBX::ScriptContext::ScriptContext()
    : globalState(NULL), scripts(std::less<Script*>()),
      nextPendingScripts(boost::posix_time::second_clock::local_time()),
      scriptsDisabled(false), exeTime0(0), exeTime1(0), exeState(0)
{
    setName("Script Context");
}
RBX::ScriptContext::~ScriptContext() {}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>;
template class boost::scoped_ptr<RBX::Lua::YieldingThreads>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Lua::YieldingThreads::WaitingThread> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Script *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<boost::shared_ptr<RBX::Script> > >;
template class std::_Tree<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >;
template class std::_Vector_val<RBX::Lua::YieldingThreads::WaitingThread,std::allocator<RBX::Lua::YieldingThreads::WaitingThread> >;
template class std::allocator<RBX::Script *>;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node *>;
