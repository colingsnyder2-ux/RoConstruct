// Link-closure stub, tracked: not recovered 2008 code.
// Verified objects compiled with BOOST_NO_EXCEPTIONS keep stripped (never called) bodies that still name the
// user-supplied boost::throw_exception; this definition only lets them link.
#include <exception>

namespace boost
{
	void throw_exception(std::exception const& e)
	{
		throw e;
	}
}
