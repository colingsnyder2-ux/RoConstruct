#include <afxwin.h>
#include <boost/scoped_ptr.hpp>
#include <memory>
class ScopedWindow { boost::scoped_ptr<CWnd> value; public: __declspec(noinline) void reset(CWnd*); };
void ScopedWindow::reset(CWnd* p) { value.reset(p); }
class AutoWindow { std::auto_ptr<CWnd> value; public: __declspec(noinline) void reset(CWnd*); };
void AutoWindow::reset(CWnd* p) { value.reset(p); }
