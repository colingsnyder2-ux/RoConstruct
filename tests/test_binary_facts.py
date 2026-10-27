from roc import analyze, agent


def test_import_symbols_preserve_ordinals_and_resolve_exact_iat_thunks():
    from types import SimpleNamespace as NS
    pe = NS(DIRECTORY_ENTRY_IMPORT=[NS(dll=b"mfc90.dll", imports=[
        NS(address=0x803bf4, name=None, ordinal=800),
        NS(address=0x803bf8, name=b"named", ordinal=None),
        NS(address=0, name=b"missing", ordinal=None)])])
    bodies = {0x6a067a: bytes.fromhex("ff25f43b8000"), 0x6a0680: bytes.fromhex("ff25f83b8000")}
    functions = [dict(addr="%08x" % addr, size=6, kind="thunk") for addr in bodies]
    imports = analyze.import_symbols(pe, functions, lambda addr, size: bodies[addr][:size])
    assert imports == {0x803bf4: "mfc90.dll!#800", 0x803bf8: "mfc90.dll!named",
                       0x6a067a: "mfc90.dll!#800", 0x6a0680: "mfc90.dll!named"}
    facts = analyze.binary_facts(None, b"", 0x400000, bodies[0x6a067a], 0x6a067a, imports)
    assert facts["imports"] == ["mfc90.dll!#800"]
    assert facts["external_calls"] == ["mfc90.dll!#800"]
    call = bytes.fromhex("e8d5a55d00c3")  # call 006a067a from 000c60a0
    facts = analyze.binary_facts(None, b"", 0x400000, call, 0xc60a0, imports)
    assert facts["imports"] == ["mfc90.dll!#800"]


def test_import_symbols_do_not_follow_chains_or_classify_reviewed_data_as_thunks():
    from types import SimpleNamespace as NS
    pe = NS(DIRECTORY_ENTRY_IMPORT=[NS(dll=b"lib", imports=[NS(address=0x5000, name=None, ordinal=0)])])
    bodies = {0x4000: bytes.fromhex("ff2500500000"), 0x4010: bytes.fromhex("ff2500400000"),
              0x4020: bytes.fromhex("ff2500500000"), 0x4030: bytes.fromhex("ff2500500000c3"),
              0x4040: bytes.fromhex("ff250050")}
    functions = [dict(addr="%08x" % addr, size=len(body), kind="data" if addr == 0x4020 else "code")
                 for addr, body in bodies.items()]
    functions[-1]["size"] = 6  # Truncated image read must not manufacture a valid IAT slot.
    imports = analyze.import_symbols(pe, functions, lambda addr, size: bodies[addr][:size])
    assert imports == {0x5000: "lib!#0", 0x4000: "lib!#0"}


def test_this_stores_and_loads_are_distinct():
    # mov [ecx+0x10], eax; mov edx, [ecx+0x14]; ret 0x14
    facts = analyze.binary_facts(None, b"", 0x400000,
                                bytes.fromhex("8941108b5114c21400"), 0x401000, {})
    assert facts["this_writes"] == [16]
    assert facts["this_reads"] == [20]
    assert facts["return_stack_bytes"] == [20]


def test_virtual_slots_use_loaded_vtable_and_numeric_displacement():
    for code, expected in [("8b01ff5018c3", [6]), ("8b01ff10c3", [0]),
                           ("8b0133c0ff5018c3", []), ("8b01e800000000ff5018c3", [])]:
        facts = analyze.binary_facts(None, b"", 0x400000, bytes.fromhex(code), 0x401000, {})
        assert facts["virtual_slots"] == expected


def test_return_bytes_preserve_bare_return_and_unknown_tail_jump():
    for code, expected in [("c3", [0]), ("ebfe", [])]:
        facts = analyze.binary_facts(None, b"", 0x400000, bytes.fromhex(code), 0x401000, {})
        assert facts["return_stack_bytes"] == expected


def test_virtual_slots_follow_method_load_and_register_copies():
    # Native 0067e358 shape: table in EDX, slot +D4 loaded into EDX, call EDX.
    for code, expected in [("8b118b92d4000000ffd2c3", [53]),
                           ("8b118bc28b7018ffd6c3", [6]),
                           ("8b118b12ffe2", [0])]:
        assert analyze.virtual_dispatch_slots(bytes.fromhex(code), 0x401000) == expected


def test_virtual_slots_drop_partial_writes_unknown_calls_and_control_flow_joins():
    for code in ["8b118b5218b200ffd2c3",  # DL overwrites method pointer
                 "8b118b5218e800000000ffd2c3",  # call clobbers EDX
                 "8b118b52187500ffd2c3",  # branch ends provenance
                 "74058b118b5218ffd2c3",  # jump bypasses method load
                 "8b118b5218f7e0ffd2c3",  # MUL implicitly overwrites EDX
                 "8b118b521933d2ffd2c3",  # explicit overwrite
                 "8b11ff5219c3"]:  # unaligned vtable displacement
        assert analyze.virtual_dispatch_slots(bytes.fromhex(code), 0x401000) == []


def test_virtual_slots_keep_nonvolatile_method_pointer_across_calls():
    code = bytes.fromhex("8bf98b118b7218e8000000008bcfffd6c3")
    assert analyze.virtual_dispatch_slots(code, 0x401000) == [6]


def test_virtual_slots_require_matching_this_object_and_follow_saved_object():
    assert analyze.virtual_dispatch_slots(bytes.fromhex("8b178b92d40000008bcfffd2c3"), 0x401000) == [53]
    assert analyze.virtual_dispatch_slots(bytes.fromhex("8b118b52188bceffd2c3"), 0x401000) == []


def test_agent_packet_retains_observed_neighbor_return_bytes():
    row = dict(call_targets=["00401000"], return_stack_bytes=[4])
    functions = {"00401000": dict(unit="helper", score=100, return_stack_bytes=[20])}
    facts = agent.function_evidence(row, functions)
    assert facts["return_stack_bytes"] == [4]
    assert facts["call_targets"][0]["return_stack_bytes"] == [20]
    assert facts["call_targets"][0]["matched_read_only"]


def test_agent_packet_omits_return_claims_for_bad_extents():
    facts = agent.function_evidence(dict(call_targets=["00401000"]),
                                   {"00401000": dict(kind="bad", return_stack_bytes=[20])})
    assert "return_stack_bytes" not in facts["call_targets"][0]


def test_agent_packet_keeps_later_callee_abi_clues_bounded():
    addresses = [f"{0x401000 + i * 16:08x}" for i in range(10)]
    facts = agent.function_evidence(dict(callers=addresses, call_targets=addresses),
                                   {addresses[5]: dict(return_stack_bytes=[20])})
    assert len(facts["callers"]) == 4
    assert len(facts["call_targets"]) == 8
    assert facts["call_targets"][5]["return_stack_bytes"] == [20]


def test_literals_start_at_the_referenced_address_not_later_in_the_chunk():
    image = bytearray(256)
    image[32:32 + 13] = b"StatsHud1\nOK\0"
    image[80:80 + 18] = b"\x01\x02\0Nearby decoy\0xx"
    # push literal; push binary data with a nearby printable string; ret
    code = bytes.fromhex("68200040006850004000c3")
    facts = analyze.binary_facts(None, bytes(image), 0x400000, code, 0x401000, {})
    assert facts["strings"] == ["StatsHud1\nOK"]
    assert "0x400050" in facts["data_refs"]


def test_code_destinations_and_imports_do_not_become_string_literals():
    image = bytearray(256)
    image[128:128 + 16] = b"Not an argument\0"
    # call base+128; jmp base+128; call [base+160]
    code = bytes.fromhex("e87bf0ffffe976f0ffffff15a0004000")
    facts = analyze.binary_facts(None, bytes(image), 0x400000, code, 0x401000,
                                 {0x4000a0: "runtime.dll!helper"})
    assert facts["strings"] == []
    assert facts["imports"] == ["runtime.dll!helper"]


def test_unterminated_or_binary_prefixes_are_not_literals():
    image = b"\x80Printable decoy\0" + b"x" * 300
    code = bytes.fromhex("68000040006811004000c3")
    facts = analyze.binary_facts(None, image, 0x400000, code, 0x401000, {})
    assert facts["strings"] == []


def test_literal_order_preserves_early_identity_clues_before_alphabetic_labels():
    image = bytearray(128)
    image[32:42] = b"StatsHud1\0"
    image[64:70] = b"AAAAA\0"
    facts = analyze.binary_facts(None, bytes(image), 0x400000,
                                 bytes.fromhex("68200040006840004000c3"), 0x401000, {})
    assert facts["strings"] == ["StatsHud1", "AAAAA"]


def test_printable_float_bits_are_data_not_a_literal_argument():
    image = bytearray(128)
    image[32:37] = b"333?\0"  # float 0.7 followed by zero, observed in the reverb switch
    facts = analyze.binary_facts(None, bytes(image), 0x400000,
                                 bytes.fromhex("d90520004000c3"), 0x401000, {})
    assert facts["strings"] == []
    assert facts["data_refs"] == ["0x400020"]


def test_constructor_prefix_keeps_nonvolatile_this_across_calls_and_stops_at_branch():
    # mov esi,ecx; lea ecx,[esi+4]; call [ctor]; lea ecx,[esi+0x10];
    # call [ctor]; jne; lea ecx,[esi+0x1c]; call [ctor] (outside straight-line prefix)
    code = bytes.fromhex("8bf18d4e04ff15000050008d4e10ff150000500075008d4e1cff1500005000")
    facts = analyze.binary_facts(None, b"", 0x400000, code, 0x401000,
                                 {0x500000: "rgmain.dll!??0TexturePtr@Ogre@@QAE@XZ"})
    assert [r["offset"] for r in facts["entry_ecx_constructors"]] == [4, 16]
    assert [r["call"] for r in facts["entry_ecx_constructors"]] == ["00401005", "0040100e"]
    packet = agent.function_evidence(facts, {})
    assert packet["entry_ecx_constructors"] == facts["entry_ecx_constructors"]


def test_constructor_origins_do_not_follow_dereferences_stack_or_clobbered_registers():
    for code in ["8bf18b4e04ff1500005000",  # member pointer load, not embedded object
                 "8d4c2404ff1500005000",  # local object on stack
                 "8bf133f68d4e04ff1500005000",  # saved register overwritten
                 "b100ff1500005000",  # CL write invalidates the entry ECX pointer
                 "8bf166be00008d4e04ff1500005000",  # SI write invalidates saved ESI
                 "8bf966bf00008d4f04ff1500005000",  # DI write invalidates saved EDI
                 "8be966bd00008d4d04ff1500005000",  # BP write invalidates saved EBP
                 "ff15040050008d4904ff1500005000"]:  # ECX clobbered by previous call
        assert analyze.entry_ecx_constructors(bytes.fromhex(code), 0x401000,
                  {0x500000: "rgmain.dll!??0TexturePtr@Ogre@@QAE@XZ"}) == []


def test_constructor_origins_track_pointer_adjustments_and_ignore_other_imports():
    # mov esi,ecx; add esi,0x20; mov ecx,esi; call [ctor]; lea ecx,[esi+4]; call [other]
    code = bytes.fromhex("8bf183c6208bceff15000050008d4e04ff1504005000c3")
    rows = analyze.entry_ecx_constructors(code, 0x401000,
                {0x500000: "rgmain.dll!??0MaterialPtr@Ogre@@QAE@XZ", 0x500004: "other"})
    assert [r["offset"] for r in rows] == [32]
