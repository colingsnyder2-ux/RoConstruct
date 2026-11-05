import struct

import pytest

from roc import match, rtti, agent_recovery


@pytest.fixture
def native(monkeypatch):
    base = 0x400000
    image = bytearray(0x3000)
    table, locator, descriptor, function = 0x402004, 0x402100, 0x402200, 0x401100
    def word(address, value):
        struct.pack_into("<I", image, address-base, value)
    word(table-4, locator)
    word(table, function)
    word(locator+12, descriptor)
    word(descriptor, 0x402300)
    image[descriptor-base+8:descriptor-base+19] = b".?AVMesh@@\0"
    sites = {table-4, table, locator+12}
    monkeypatch.setattr(rtti, "_image", lambda client: (base, bytes(image)))
    monkeypatch.setattr(match, "_base_relocs", lambda client: sites)
    monkeypatch.setattr(match, "_functions", lambda client: {"00401100": {"kind": "code"}})
    return image, sites, word, table, locator, descriptor


def store(table):
    return b"\xc7\x00" + struct.pack("<I", table) + b"\xc3"


def test_relocated_vptr_store_reports_exact_instruction_and_type(native):
    _, _, _, table, _, descriptor = native
    assert rtti.vtable_stores("C", "00401000", store(table), [2]) == [dict(
        instruction="00401000", destination="dword ptr [eax]", vtable="00402004",
        type_descriptor="00402200", type=".?AVMesh@@")]


def test_plain_pointer_load_and_unrelocated_store_are_not_vptr_stores(native):
    _, _, _, table, _, _ = native
    assert not rtti.vtable_stores("C", "00401000", store(table), [])
    assert not rtti.vtable_stores("C", "00401000", b"\xb8"+struct.pack("<I", table)+b"\xc3", [1])
    assert not rtti.vtable_stores("C", "00401000", b"\xc3"+store(table), [3])


@pytest.mark.parametrize("fault", ["locator_relocation", "type_relocation", "slot_relocation", "signature", "type", "non_ascii", "locator_bounds", "descriptor_bounds", "slot"])
def test_vtable_validation_rejects_unproven_data(native, fault):
    image, sites, word, table, locator, descriptor = native
    if fault == "locator_relocation": sites.remove(table-4)
    elif fault == "type_relocation": sites.remove(locator+12)
    elif fault == "slot_relocation": sites.remove(table)
    elif fault == "signature": word(locator, 1)
    elif fault == "type": image[descriptor-0x400000+8] = ord("x")
    elif fault == "non_ascii": image[descriptor-0x400000+13] = 255
    elif fault == "locator_bounds": word(table-4, 0x3ffffc)
    elif fault == "descriptor_bounds": word(locator+12, 0x500000)
    elif fault == "slot": word(table, 0x402400)
    assert not rtti.vtable_stores("C", "00401000", store(table), [2])


def test_subobject_store_keeps_raw_destination_without_claiming_this_offset(native):
    _, _, _, table, _, _ = native
    code = b"\xc7\x40\x04"+struct.pack("<I", table)+b"\xc3"
    evidence = rtti.vtable_stores("C", "00401000", code, [3])
    assert evidence[0]["destination"] == "dword ptr [eax + 4]"
    assert "this_offset" not in evidence[0]


def test_packet_finds_typed_callee_beyond_first_eight(tmp_path, monkeypatch):
    target = dict(addr="00401000", size=1, call_targets=["%08x" % (0x402000+i*16) for i in range(12)])
    rows = {target["addr"]: target, **{a: {"kind": "code"} for a in target["call_targets"]}}
    monkeypatch.setattr(match, "_functions", lambda client: rows)
    monkeypatch.setattr(match, "target", lambda client, addr: (b"\xc3", [], rows[addr]))
    monkeypatch.setattr(match, "disasm", lambda *args: ["ret"])
    last = target["call_targets"][-1]
    monkeypatch.setattr(rtti, "vtable_stores", lambda client, addr, *args: [{"type": ".?AVMesh@@"}] if addr == last else [])
    result = agent_recovery.packet(tmp_path, "C", target["addr"], "", {})
    assert len(result["neighbours"]) == 8
    assert result["callee_rtti_vtable_stores"] == [{"addr": last, "stores": [{"type": ".?AVMesh@@"}]}]
