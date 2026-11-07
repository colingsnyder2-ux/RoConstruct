"""Check provider ownership without building or launching the diagnostic client."""
import ast
from pathlib import Path

import pytest


SOURCE = Path(__file__).resolve().parents[1] / "rebuild/2008-06/p6/build_client.py"


def selection():
    tree = ast.parse(SOURCE.read_text(encoding="utf-8"))
    lists = {}
    for node in ast.walk(tree):
        if not isinstance(node, ast.Assign):
            continue
        for target in node.targets:
            if not isinstance(target, ast.Name) or target.id not in ("doc_sources", "native_doc_objects"):
                continue
            value = node.value.body if isinstance(node.value, ast.IfExp) else node.value
            if isinstance(value, ast.List):
                lists[target.id] = [item.elts[0].value if isinstance(item, ast.Tuple) else item.value
                                    for item in value.elts]
    for node in ast.walk(tree):
        if isinstance(node, ast.If):
            body = node.body
            for index, stmt in enumerate(body):
                if (isinstance(stmt, ast.Assign) and isinstance(stmt.targets[0], ast.Name)
                        and stmt.targets[0].id == "compiled_doc_objects"):
                    guard = ast.fix_missing_locations(ast.Module(body=body[index:index + 3], type_ignores=[]))
                    return lists["doc_sources"], lists["native_doc_objects"], compile(guard, str(SOURCE), "exec")
    raise AssertionError("provider selection guard missing")


def check(doc, linked, units):
    _, _, guard = selection()
    exec(guard, {"doc_sources": [(name, None) for name in doc],
                 "native_doc_objects": linked, "units": [(name,) for name in units]})


def test_real_selection_and_extra_sources_agree():
    doc, linked, _ = selection()
    assert doc and linked
    check(doc, linked, [])
    check(doc + ["NativeDocExtra00.obj"], linked + ["NativeDocExtra00.obj"], [])


@pytest.mark.parametrize("defect", ["compiled", "linked", "missing", "overlap"])
def test_duplicate_or_missing_selection_is_rejected(defect):
    doc, linked, _ = selection()
    units = []
    if defect == "compiled":
        doc.append(doc[0].upper())
    elif defect == "linked":
        linked.append(linked[0].upper())
    elif defect == "missing":
        linked.pop()
    else:
        units.append(linked[0].upper())
    with pytest.raises(RuntimeError, match="object selection"):
        check(doc, linked, units)
