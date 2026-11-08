"""Read original embedded COM type metadata without registration or execution."""
import ctypes as C
from ctypes import wintypes as W
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import uuid

ROOT = Path(__file__).resolve().parents[4]
EXE = ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'
HRESULT = C.c_long


class GUID(C.Structure):
    _fields_ = [('bytes', C.c_ubyte * 16)]


class TYPEDESC(C.Structure):
    pass


class TYPEVALUE(C.Union):
    _fields_ = [('pointer', C.POINTER(TYPEDESC)), ('reference', W.DWORD)]


TYPEDESC._fields_ = [('value', TYPEVALUE), ('vt', W.WORD)]


class IDLDESC(C.Structure):
    _fields_ = [('reserved', C.c_size_t), ('flags', W.WORD)]


class ELEMDESC(C.Structure):
    _fields_ = [('type', TYPEDESC), ('idl', IDLDESC)]


class TYPEATTR(C.Structure):
    _fields_ = [('guid', GUID), ('lcid', W.DWORD), ('reserved', W.DWORD),
                ('constructor', W.LONG), ('destructor', W.LONG), ('schema', C.c_void_p),
                ('size', W.DWORD), ('kind', C.c_int), ('functions', W.WORD),
                ('variables', W.WORD), ('implementations', W.WORD), ('vtable_size', W.WORD),
                ('alignment', W.WORD), ('flags', W.WORD), ('major', W.WORD), ('minor', W.WORD),
                ('alias', TYPEDESC), ('idl', IDLDESC)]


class FUNCDESC(C.Structure):
    _fields_ = [('id', W.LONG), ('scodes', C.c_void_p), ('parameters', C.POINTER(ELEMDESC)),
                ('kind', C.c_int), ('invoke', C.c_int), ('convention', C.c_int),
                ('count', C.c_short), ('optional', C.c_short), ('vtable_offset', C.c_short),
                ('scode_count', C.c_short), ('result', ELEMDESC), ('flags', W.WORD)]


ole = C.OleDLL('oleaut32')
ole.LoadTypeLibEx.argtypes = [W.LPCWSTR, C.c_int, C.POINTER(C.c_void_p)]
ole.LoadTypeLibEx.restype = HRESULT
ole.SysFreeString.argtypes = [C.c_void_p]
ole.SysFreeString.restype = None


def call(obj, slot, result, args, *values):
    table = C.cast(obj, C.POINTER(C.POINTER(C.c_void_p))).contents
    return C.WINFUNCTYPE(result, C.c_void_p, *args)(table[slot])(obj, *values)


def checked(value):
    assert value >= 0, hex(value & 0xffffffff)


def name_of(info):
    value = C.c_void_p()
    checked(call(info, 12, HRESULT, [W.LONG, C.POINTER(C.c_void_p), C.c_void_p, C.c_void_p, C.c_void_p],
                 -1, C.byref(value), None, None, None))
    result = C.wstring_at(value)
    ole.SysFreeString(value)
    return result


def describe(info, descriptor):
    kind = descriptor.vt
    if kind in (26, 27):
        return dict(vt=kind, element=describe(info, descriptor.value.pointer.contents))
    if kind == 29:
        referenced = C.c_void_p()
        checked(call(info, 14, HRESULT, [W.DWORD, C.POINTER(C.c_void_p)],
                     descriptor.value.reference, C.byref(referenced)))
        try:
            return dict(vt=kind, name=name_of(referenced))
        finally:
            call(referenced, 2, W.ULONG, [])
    return dict(vt=kind)


library = C.c_void_p()
checked(ole.LoadTypeLibEx(str(EXE), 2, C.byref(library)))  # REGKIND_NONE
types = {}
try:
    count = call(library, 3, W.UINT, [])
    for index in range(count):
        info = C.c_void_p()
        checked(call(library, 4, HRESULT, [W.UINT, C.POINTER(C.c_void_p)], index, C.byref(info)))
        try:
            name = name_of(info)
            if name not in ('IWorkspace', 'IContent'):
                continue
            # The dispatch view transforms HRESULT/retval parameters. Read the
            # associated dual vtable interface to preserve the actual COM ABI.
            reference = W.DWORD()
            checked(call(info, 8, HRESULT, [W.UINT, C.POINTER(W.DWORD)], 0xffffffff, C.byref(reference)))
            dual = C.c_void_p()
            checked(call(info, 14, HRESULT, [W.DWORD, C.POINTER(C.c_void_p)], reference, C.byref(dual)))
            call(info, 2, W.ULONG, [])
            info = dual
            attributes = C.POINTER(TYPEATTR)()
            checked(call(info, 3, HRESULT, [C.POINTER(C.POINTER(TYPEATTR))], C.byref(attributes)))
            try:
                attr = attributes.contents
                methods = []
                for function in range(attr.functions):
                    description = C.POINTER(FUNCDESC)()
                    checked(call(info, 5, HRESULT, [W.UINT, C.POINTER(C.POINTER(FUNCDESC))],
                                 function, C.byref(description)))
                    try:
                        method = description.contents
                        assert method.vtable_offset % C.sizeof(C.c_void_p) == 0
                        names = (C.c_void_p * (method.count + 1))()
                        received = W.UINT()
                        checked(call(info, 7, HRESULT, [W.LONG, C.POINTER(C.c_void_p), W.UINT, C.POINTER(W.UINT)],
                                     method.id, names, len(names), C.byref(received)))
                        strings = [C.wstring_at(names[n]) for n in range(received.value)]
                        for n in range(received.value):
                            ole.SysFreeString(names[n])
                        methods.append(dict(names=strings, id=method.id, kind=method.kind,
                                            invoke=method.invoke, convention=method.convention,
                                            host_vtable_offset=method.vtable_offset,
                                            native_x86_vtable_offset=method.vtable_offset // C.sizeof(C.c_void_p) * 4,
                                            result=describe(info, method.result.type),
                                            parameters=[dict(type=describe(info, method.parameters[n].type),
                                                             flags=method.parameters[n].idl.flags)
                                                        for n in range(method.count)]))
                    finally:
                        call(info, 20, None, [C.POINTER(FUNCDESC)], description)
                assert attr.kind == 3  # TKIND_INTERFACE
                types[name] = dict(guid=str(uuid.UUID(bytes_le=bytes(attr.guid.bytes))), kind=attr.kind,
                                   flags=attr.flags, host_vtable_size=attr.vtable_size,
                                   native_x86_vtable_size=attr.vtable_size // C.sizeof(C.c_void_p) * 4,
                                   methods=methods)
            finally:
                call(info, 19, None, [C.POINTER(TYPEATTR)], attributes)
        finally:
            call(info, 2, W.ULONG, [])
finally:
    call(library, 2, W.ULONG, [])

assert types['IWorkspace']['guid'] == '0730c3c6-092d-4f45-b8b9-bdeb82de1c7b'
assert types['IContent']['guid'] == 'd63f927a-1170-4239-9c1d-06e8a658f300'
assert [m['names'][0] for m in types['IWorkspace']['methods']] == [
    'SaveToFile', 'SaveSelectionToFile', 'Insert', 'Write', 'WriteSelection', 'ExecScript', 'ExecUrlScript', 'Close']
assert types['IWorkspace']['native_x86_vtable_size'] == 60
assert types['IContent']['native_x86_vtable_size'] == 32
assert all(method['result'] == dict(vt=25) for value in types.values() for method in value['methods'])
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               original_sha256=hashlib.sha256(EXE.read_bytes()).hexdigest(),
               observer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
               interface_header_sha256=hashlib.sha256((ROOT / 'rebuild/2008-06/native-headers/RobloxLib.h').read_bytes()).hexdigest(),
               registration='REGKIND_NONE', automation_host_pointer_size=C.sizeof(C.c_void_p),
               native_x86_pointer_size=4, types=types)
output = ROOT / 'work/2008-06' / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + '\n')
for name, value in types.items():
    print(name, value['guid'], [(row['names'][0], row['native_x86_vtable_offset']) for row in value['methods']])
