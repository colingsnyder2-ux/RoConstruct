// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_erroruploaderportable40d9986de6c9f20c.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias(<boost/function.hpp>, <roc_espeon_boost135functionheader672dcef995494068.cpp>)
#pragma include_alias(<boost/function/function0.hpp>, <roc_espeon_boost135functionheader57405a50c9beea11.cpp>)
#pragma include_alias(<boost/function/function1.hpp>, <roc_espeon_boost135functionheader54de262102ae7bc4.cpp>)
#pragma include_alias(<boost/function/function10.hpp>, <roc_espeon_boost135functionheader25854fd9e87eca57.cpp>)
#pragma include_alias(<boost/function/function2.hpp>, <roc_espeon_boost135functionheaderab3c4a9a8a29aee5.cpp>)
#pragma include_alias(<boost/function/function3.hpp>, <roc_espeon_boost135functionheader1d11d6b5b76997d8.cpp>)
#pragma include_alias(<boost/function/function4.hpp>, <roc_espeon_boost135functionheaderb9d89fa9f73a18fe.cpp>)
#pragma include_alias(<boost/function/function5.hpp>, <roc_espeon_boost135functionheaderc126e05698a03109.cpp>)
#pragma include_alias(<boost/function/function6.hpp>, <roc_espeon_boost135functionheader051609ba2d0c0985.cpp>)
#pragma include_alias(<boost/function/function7.hpp>, <roc_espeon_boost135functionheadere4e8b3783b4f4a3b.cpp>)
#pragma include_alias(<boost/function/function8.hpp>, <roc_espeon_boost135functionheader69f3516c99152e9d.cpp>)
#pragma include_alias(<boost/function/function9.hpp>, <roc_espeon_boost135functionheader91b96edc0e30e1e0.cpp>)
#pragma include_alias(<boost/function/function_base.hpp>, <roc_espeon_boost135functionheadera464fc73794f4fe5.cpp>)
#pragma include_alias(<boost/function/function_template.hpp>, <roc_espeon_boost135functionheader95fb4a51a884f45f.cpp>)
#pragma include_alias(<boost/function/detail/function_iterate.hpp>, <roc_espeon_boost135functionheader40cdef22debfc2b9.cpp>)
#pragma include_alias(<boost/function/detail/maybe_include.hpp>, <roc_espeon_boost135functionheaderb080037d4ec60e6a.cpp>)
#pragma include_alias(<boost/function/detail/prologue.hpp>, <roc_espeon_boost135functionheader1f7a0a92d6d4d42d.cpp>)
#pragma include_alias(<boost/thread/recursive_mutex.hpp>, <roc_espeon_legacythreadrecursive_mutexee363449122c8f21.cpp>)
#pragma include_alias(<boost/thread/mutex.hpp>, <roc_espeon_legacythreadmutexbefa909d30d0d106.cpp>)
#pragma include_alias(<boost/thread/condition.hpp>, <roc_espeon_legacythreadcondition843444ebbcef2410.cpp>)
#pragma include_alias(<boost/thread/thread.hpp>, <roc_espeon_legacythreadthread06cd492e21b7fb9f.cpp>)
#pragma include_alias(<boost/thread/detail/lock.hpp>, <roc_espeon_legacythreaddetaillockddfa4221864cb677.cpp>)
#pragma include_alias(<boost/thread/exceptions.hpp>, <roc_espeon_legacythreadexceptions4927ee42153425fc.cpp>)
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <queue>
#include <string>
#include <util/boost.hpp>
class ErrorUploader {
 struct data {
  std::queue<std::string> files;
  boost::recursive_mutex sync;
  std::string url;
  data();
 };
 boost::shared_ptr<data> state;
 RBX::worker_thread thread;
 static RBX::worker_thread::work_result process(boost::shared_ptr<data>);
 public: ErrorUploader();
};
ErrorUploader::ErrorUploader(): state(new data),thread(boost::bind(&process,state),"rbx_erroruploader") {}
