import hashlib

from roc import client_templates, libs


def test_generated_units_preserve_source_reference_hashes_and_vendor_scope():
    units = client_templates.units()
    assert units
    for filename, source in units.items():
        assert filename == "roc_rtti_" + hashlib.sha256(source.encode()).hexdigest()[:16] + ".cpp"
        assert "template class boost::" in source
        assert "RBX::" not in source and "G3D::" not in source
    units.clear()
    assert client_templates.units()
    assert libs.RECIPES["templates-2008-06"]["generate"]() == client_templates.units()
