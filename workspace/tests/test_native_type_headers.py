from roc import agent_recovery as recovery


def header(root, folder, name, text):
    path = root / folder / name
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)
    return path


def test_native_declspec_class_is_indexed_under_real_type_name(tmp_path):
    path = header(tmp_path, "tools/rbxgs/Client/App/include/reflection", "property.h",
        "namespace RBX { class __declspec(novtable) PropertyDescriptor : public MemberDescriptor { int flags; }; }")
    rows = recovery.native_type_headers(tmp_path, "2008-06",
        [{"type": ".?AVPropertyDescriptor@Reflection@RBX@@"}])
    assert len(rows) == 1 and rows[0]["path"] == str(path)
    assert rows[0]["type"] == ".?AVPropertyDescriptor@Reflection@RBX@@" and rows[0]["origin"] == "rtti"
    assert rows[0]["candidate_only"] and rows[0]["read_only"]
    assert "__declspec(novtable) PropertyDescriptor" in rows[0]["excerpt"]


def test_native_type_candidates_preserve_conflicting_authentic_versions(tmp_path):
    first = header(tmp_path, "tools/rbxgs/Client/App/include/util", "IndexBox.h",
                   "namespace RBX { class IndexBox { private: Vector3 corner[8]; }; }")
    second = header(tmp_path, "tools/openrbx/Client/App/include/util", "IndexBox.h",
                    "namespace RBX { class IndexBox { public: virtual ~IndexBox() {} ; private: Vector3 corner[8]; }; }")
    rows = recovery.native_type_headers(tmp_path, "2008-06", [{"type": ".?AVIndexBox@RBX@@"}] * 2)
    assert [r["path"] for r in rows] == [str(first), str(second)]
    assert all(r["read_only"] and r["candidate_only"] for r in rows)
    assert "virtual ~IndexBox" not in rows[0]["excerpt"]
    assert "virtual ~IndexBox" in rows[1]["excerpt"]


def test_ogre_prefix_and_bounded_excerpt(tmp_path):
    header(tmp_path, "tools/libs/ogre-1.4.5/ogrenew/OgreMain/include", "OgreMesh.h",
           "/**" + "license " * 400 + "*/\nnamespace Ogre { class _OgreExport Mesh {" + "int x;" * 1000)
    rows = recovery.native_type_headers(tmp_path, "2008-06", [{"type": ".?AVMesh@Ogre@@"}])
    assert len(rows) == 1
    assert "class _OgreExport Mesh" in rows[0]["excerpt"]
    assert len(rows[0]["excerpt"]) == 2400
    assert rows[0]["truncated"]


def test_scope_templates_and_unproven_names_are_not_guessed(tmp_path):
    header(tmp_path, "tools/rbxgs/Client/App/include", "Foo.h", "class Foo {};")
    for typename in ["Foo", ".?AV?$Foo@H@RBX@@", ".?AV../../Foo@RBX@@", ".?AVFoo@Other@@"]:
        assert not recovery.native_type_headers(tmp_path, "2008-06", [{"type": typename}])
    assert not recovery.native_type_headers(tmp_path, "2009-12", [{"type": ".?AVFoo@RBX@@"}])


def test_candidate_limit_and_missing_headers(tmp_path):
    for name in ["Foo", "Bar", "Baz"]:
        header(tmp_path, "tools/rbxgs/Client/App/include", name + ".h", "class " + name + " {};")
    stores = [{"type": ".?AV" + name + "@RBX@@"} for name in ["Missing", "Foo", "Bar", "Baz"]]
    assert len(recovery.native_type_headers(tmp_path, "2008-06", stores, limit=2)) == 2


def test_nested_type_in_differently_named_header_ignores_forward_declaration(tmp_path):
    header(tmp_path, "tools/rbxgs/Client/App/include", "BoardData.h", "namespace RBX { class BoardData; }")
    path = header(tmp_path, "tools/rbxgs/Client/App/include/gui", "ScoreHud.h",
                  "namespace RBX { class BoardData { public: int count; }; }")
    rows = recovery.native_type_headers(tmp_path, "2008-06", [{"type": ".?AVBoardData@RBX@@"}])
    assert [r["path"] for r in rows] == [str(path)]


def test_indexed_header_excerpt_is_read_again(tmp_path):
    path = header(tmp_path, "tools/rbxgs/Client/App/include", "Bundle.hpp", "class Foo { int before; };")
    stores = [{"type": ".?AVFoo@RBX@@"}]
    assert "before" in recovery.native_type_headers(tmp_path, "2008-06", stores)[0]["excerpt"]
    path.write_text("class Foo { int after; };")
    assert "after" in recovery.native_type_headers(tmp_path, "2008-06", stores)[0]["excerpt"]


def test_packet_attaches_native_callee_headers(tmp_path, monkeypatch):
    from roc import match, rtti

    target = dict(addr="00401000", size=1, call_targets=["00402000"])
    rows = {target["addr"]: target, "00402000": {"kind": "code"}}
    monkeypatch.setattr(match, "_functions", lambda client: rows)
    monkeypatch.setattr(match, "target", lambda client, addr: (b"\xc3", [], rows[addr]))
    monkeypatch.setattr(match, "disasm", lambda *args: ["ret"])
    monkeypatch.setattr(rtti, "vtable_stores", lambda client, addr, *args:
                        [{"type": ".?AVIndexBox@RBX@@"}] if addr == "00402000" else [])
    path = header(tmp_path, "tools/openrbx/Client/App/include/util", "IndexBox.h",
                  "class IndexBox { public: virtual ~IndexBox() {} }; ")
    packet = recovery.packet(tmp_path, "2008-06", target["addr"], "", {})
    assert [r["path"] for r in packet["native_type_headers"]] == [str(path)]


def test_unit_hint_without_rtti_has_explicit_unproven_origin(tmp_path):
    path = header(tmp_path, "tools/rbxgs/Client/App/include/v8datamodel", "ToolMouseCommand.h",
                  "namespace RBX { class ToolMouseCommand { public: void update(); }; }")
    rows = recovery.native_type_headers(tmp_path, "2008-06", [], unit="RBX::ToolMouseCommand")
    assert len(rows) == 1
    assert rows[0]["path"] == str(path)
    assert rows[0]["type"] == "RBX::ToolMouseCommand"
    assert rows[0]["origin"] == "unit_hint"
    assert rows[0]["candidate_only"] and rows[0]["read_only"]
    for unit in ["RBX::VWidget::?$NonFactoryProduct", "RBX::../ToolMouseCommand", "Other::ToolMouseCommand"]:
        assert not recovery.native_type_headers(tmp_path, "2008-06", [], unit=unit)
    assert not recovery.native_type_headers(tmp_path, "2009-12", [], unit="RBX::ToolMouseCommand")


def test_rtti_candidates_precede_and_deduplicate_unit_hints(tmp_path):
    for name in ["Foo", "Bar"]:
        header(tmp_path, "tools/rbxgs/Client/App/include", name + ".h", "class " + name + " {};")
    stores = [{"type": ".?AVFoo@RBX@@"}]
    rows = recovery.native_type_headers(tmp_path, "2008-06", stores, unit="RBX::Foo")
    assert len(rows) == 1 and rows[0]["origin"] == "rtti"
    rows = recovery.native_type_headers(tmp_path, "2008-06", stores, limit=1, unit="RBX::Bar")
    assert len(rows) == 1 and rows[0]["origin"] == "rtti"


def test_packet_attaches_unit_hint_without_claiming_missing_header(tmp_path, monkeypatch):
    from roc import match, rtti

    target = dict(addr="00401000", size=1, unit="RBX::ToolMouseCommand")
    monkeypatch.setattr(match, "_functions", lambda client: {target["addr"]: target})
    monkeypatch.setattr(match, "target", lambda client, addr: (b"\xc3", [], target))
    monkeypatch.setattr(match, "disasm", lambda *args: ["ret"])
    monkeypatch.setattr(rtti, "vtable_stores", lambda *args: [])
    header(tmp_path, "tools/rbxgs/Client/App/include", "ToolMouseCommand.h", "class ToolMouseCommand {};")
    packet = recovery.packet(tmp_path, "2008-06", target["addr"], "", {})
    assert packet["native_type_headers"][0]["origin"] == "unit_hint"
    assert packet["rtti_vtable_stores"] == []
    assert packet["missing_evidence"] == []
