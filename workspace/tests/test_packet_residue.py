from roc import match, packet


def test_relocated_zero_addend_renders_as_sym():
    # push imm32 whose COFF field holds addend 0, and mov edx, [4] (addend 4)
    code = b"\x68\x00\x00\x00\x00" + b"\x8b\x15\x04\x00\x00\x00"
    assert match.asm_lines(code, [1, 7]) == ["push sym", "mov edx, dword ptr [sym]"]
    assert match.asm_lines(code, []) == ["push 0", "mov edx, dword ptr [4]"]


def test_relocated_push_is_not_an_immediate_mismatch():
    target = b"\x68\x18\x88\x7c\x00\xc3"
    cand = b"\x68\x00\x00\x00\x00\xc3"
    assert match.diagnose(target, [1], cand, [1])["immediate_diffs"] == []


def test_residue_keeps_every_changed_hunk():
    wide = "\n".join(["--- target", "+++ yours", "@@ -1,9 +1,9 @@", " a", "-b", "+B", " c", " d", " e", " f",
                      " g", "-h", "+H", " i"])
    out = packet._residue(wide, context=1)
    assert "-b" in out and "-h" in out and " e" not in out


def test_large_packet_keeps_long_function_tail(monkeypatch, tmp_path):
    asm = ['00658000  90  nop'] * 140 + ['00658fa2  c3  ret']
    monkeypatch.setattr(match, 'target', lambda *args: (b'code', [], {'size': 141}))
    monkeypatch.setattr(match, 'disasm', lambda *args: asm)
    monkeypatch.setattr(packet.draft, 'target_data_facts', lambda *args: {})
    monkeypatch.setattr(packet, '_source', lambda *args: ('', '', 0))
    monkeypatch.setattr(packet, '_similar', lambda *args: [])
    monkeypatch.setattr(packet, '_lessons', lambda *args, **kwargs: [])
    monkeypatch.setattr(packet, '_failed', lambda *args, **kwargs: [])
    monkeypatch.setattr(packet.claim_state, 'load_claim', lambda *args, **kwargs: None)
    result = packet.build('2008-06', '00658d20', root=tmp_path, include_diff=False, max_tokens=12000)
    assert result['target']['asm'] == asm
    assert not result['truncated']
