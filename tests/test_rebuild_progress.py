import json

from roc import rebuild


def test_code_function_count_excludes_non_code_records(tmp_path):
    path = tmp_path / "functions.jsonl"
    path.write_text("\n".join(json.dumps({"kind": kind}) for kind in (
        "code", "code", "eh", "gen", "adjustor", "thunk", "data")))

    assert rebuild.code_function_count(path) == 2


def test_module_target_count_uses_unique_owned_addresses():
    assert rebuild.module_target_count({"owned_addrs": ["00401000", "00402000", "00401000"]}) == 2
