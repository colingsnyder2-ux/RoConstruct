"""Native RTTI demangling and conservative client-specific instantiations."""
import ctypes
import re

from roc import match


def demangle_rtti(raw):
    """Decode the complete MSVC type; never split mangled namespace backreferences."""
    fn = ctypes.WinDLL("dbghelp").UnDecorateSymbolName
    fn.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_uint, ctypes.c_uint]
    fn.restype = ctypes.c_uint
    output = ctypes.create_string_buffer(16384)
    fn(raw[1:], output, len(output), 0x2000)  # UNDNAME_TYPE_ONLY, remove RTTI dot
    result = output.value.decode("ascii")
    if not result or result.startswith("?"):
        raise ValueError("Unsupported RTTI encoding")
    return result


def inventory(client):
    _, image = match._image(client)
    rows = []
    for raw in sorted(set(re.findall(rb"\.\?A[UV][^\x00\r\n]{1,2048}", bytes(image)))):
        if b"?$" not in raw:
            continue
        try:
            decoded = demangle_rtti(raw)
            rows.append({"raw": raw.decode("ascii"), "decoded": decoded})
        except (ValueError, UnicodeError) as error:
            rows.append({"raw": raw.decode("ascii", "replace"), "error": str(error)})
    return rows


def instantiation(decoded):
    """Generate only declared, supported types; unknown value layouts are rejected."""
    expression = re.sub(r"\b(?:class|struct)\s+", "", decoded).strip()
    if "<" not in expression or any(mark in expression for mark in ("`", "__", "(", ")")):
        raise ValueError("Unsupported function/member type")
    outer = expression.split("<", 1)[0]
    headers = {
        "boost::any::holder": "boost/any.hpp",
        "boost::enable_shared_from_this": "boost/enable_shared_from_this.hpp",
        "boost::detail::sp_counted_impl_p": "boost/shared_ptr.hpp",
        "std::basic_string": "string", "std::vector": "vector", "std::list": "list",
        "std::map": "map", "std::set": "set", "std::deque": "deque",
    }
    if outer not in headers:
        raise ValueError("Template needs recovered declarations: " + outer)
    forwards = []
    for kind, name in re.findall(r"\b(class|struct)\s+([A-Za-z_]\w*(?:::[A-Za-z_]\w*)*)", decoded):
        if name.startswith(("boost::", "std::")):
            continue
        if outer != "boost::enable_shared_from_this" and not re.search(re.escape(name) + r"\s*\*", expression):
            raise ValueError("Unknown value layout: " + name)
        parts = name.split("::")
        if len(parts) > 1 and parts[0] not in ("RBX", "Network", "G3D"):
            raise ValueError("Unknown nested declaration: " + name)
        declaration = "%s %s;" % (kind, parts[-1])
        for namespace in reversed(parts[:-1]):
            declaration = "namespace %s { %s }" % (namespace, declaration)
        if declaration not in forwards:
            forwards.append(declaration)
    extra = ""
    if "boost::signals" in expression or "boost::last_value" in expression:
        extra += "#include <boost/signal.hpp>\n"
    if "boost::iostreams" in expression:
        extra += "#include <boost/iostreams/filtering_stream.hpp>\n#include <boost/iostreams/filter/zlib.hpp>\n"
    if "boost::mutex" in expression:
        extra += "#include <boost/thread/mutex.hpp>\n"
    return ("#include <%s>\n#include <string>\n#include <vector>\n#include <memory>\n" % headers[outer]
            + extra
            + "\n".join(forwards) + "\n" + "template class %s;\n" % expression)
