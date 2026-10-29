from roc import repair_scan


def test_extra_instruction_prevents_single_immediate_hint(monkeypatch):
    diff = "--- target\n+++ yours\n@@ -1,2 +1,3 @@\n-add eax, 4\n+add eax, 8\n+push ecx\n ret\n"
    monkeypatch.setattr(repair_scan.match, "check_text", lambda *a: (98, "f", diff, []))
    assert repair_scan.scan_one("2008-06", "00401000", "source") is None


def test_grouped_relocation_and_immediate_lines_remain_paired(monkeypatch):
    diff = "--- target\n+++ yours\n@@ -1,2 +1,2 @@\n-push sym\n-add eax, 4\n+push 0\n+add eax, 8\n"
    monkeypatch.setattr(repair_scan.match, "check_text", lambda *a: (98, "f", diff, []))
    hint = repair_scan.scan_one("2008-06", "00401000", "source")
    assert hint["fix"]["target_value"] == "4"
    assert hint["fix"]["ours_value"] == "8"


def test_simd_register_digit_is_not_an_immediate():
    assert repair_scan._single_immediate(("movss xmm0, dword ptr [eax + 4]",
                                        "movss xmm0, dword ptr [eax + 8]"))["target_value"] == "4"


def test_one_changed_operand_with_two_constants_is_reported():
    hint = repair_scan._single_immediate(("mov byte ptr [esp + 0x14], 3",
                                          "mov byte ptr [esp + 0x14], 4"))
    assert hint["target_value"] == "3" and hint["ours_value"] == "4"
    assert repair_scan._single_immediate(("mov byte ptr [esp + 0x14], 3",
                                         "mov byte ptr [esp + 0x18], 4")) is None


def test_scan_reports_function_unit_instead_of_score(tmp_path, monkeypatch):
    import json
    monkeypatch.setattr(repair_scan, "ROOT", tmp_path)
    work = tmp_path / "work/2008-06"
    work.mkdir(parents=True)
    (work / "scores.json").write_text(json.dumps({"00401000": 98}))
    (work / "functions.jsonl").write_text(json.dumps(dict(addr="00401000", kind="code", unit="RBX::Block")))
    source = tmp_path / "src/2008-06"
    source.mkdir(parents=True)
    (source / "00401000.cpp").write_text("source")
    monkeypatch.setattr(repair_scan, "scan_one", lambda *a: dict(score=98))
    assert repair_scan.scan("2008-06", jobs=1) == [dict(score=98, unit="RBX::Block")]


def test_live_scan_uses_server_source_and_skips_newly_exact(tmp_path, monkeypatch):
    import json
    monkeypatch.setattr(repair_scan, "ROOT", tmp_path)
    work = tmp_path / "work/2008-06"
    work.mkdir(parents=True)
    (work / "functions.jsonl").write_text("\n".join(json.dumps(dict(addr=a, kind="code", unit="RBX::Block"))
        for a in ("00401000", "00401010")))
    class Api:
        def __init__(self, *args):
            pass
        def call(self, endpoint, **kwargs):
            if endpoint.startswith("/v1/sources?"):
                return [dict(addr=a, score=98) for a in ("00401000", "00401010")]
            return dict(score=100 if endpoint.endswith("00401010") else 98, source="server source")
    monkeypatch.setattr(repair_scan.worker, "Api", Api)
    checked = []
    monkeypatch.setattr(repair_scan, "scan_one", lambda client, addr, text:
                        checked.append((addr, text)) or dict(score=98))
    assert len(repair_scan.scan("2008-06", max_score=100, jobs=1, server="https://server")) == 1
    assert checked == [("00401000", "server source")]
