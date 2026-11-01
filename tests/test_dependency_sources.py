"""Optional historical-compiler checks against installed authentic dependency sources."""
from pathlib import Path

import pytest

from roc import libs, rebuild, setup

ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture
def compiler():
    if 21022 not in setup.compilers():
        pytest.skip('Historical MSVC 21022 not installed')


@pytest.mark.parametrize('module,filename', [('g3d-gl','GApp.cpp'), ('raknet','RakPeer.cpp')])
def test_dependency_source_configuration_compiles(compiler, tmp_path, monkeypatch, module, filename):
    spec = rebuild.load_module('2008-06', module)
    layer = next(layer for layer in spec['layers'] if layer['name']=='upstream')
    if module == 'g3d-gl':
        recipe = libs.RECIPES[layer['recipe']]
        original = libs._case_path(libs.LIBS / recipe['src'])
        if not (original/'GLG3Dcpp/GApp.cpp').exists():
            pytest.skip('G3D sources not installed')
        monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
        tree = rebuild.patched_tree('2008-06', layer['recipe'])
        source = tree/'GLG3Dcpp/GApp.cpp'
        includes = [tree] + [rebuild._in_tree(libs._case_path(libs.LIBS / path), original, tree)
                             for path in recipe['include'] if path!='WINSDK']
        defines = recipe.get('defines','') + ' ' + layer.get('extra_defines','')
    else:
        source = ROOT/layer['dir']/filename
        if not source.exists():
            pytest.skip('RakNet sources not installed')
        recipe = libs.RECIPES[layer['includes_from_recipe']]
        includes = [(libs.LIBS/path).resolve() for path in recipe['include'] if path!='WINSDK']
        includes += [(ROOT/path).resolve() for path in layer.get('extra_includes',[])]
        defines = libs.RECIPES[layer['defines_from_recipe']]['defines']
    result = rebuild.compile_direct('2008-06', [source], tmp_path/'objects', includes, defines, layer['flags'])
    assert result[str(source)][0], result[str(source)][1]


@pytest.mark.parametrize('filename', ['glue_humanoid_states.cpp','glue_replicator.cpp'])
def test_reported_glue_source_compiles(compiler, tmp_path, filename):
    spec = rebuild.load_module('2008-06','rbxgs-app')
    layer = next(layer for layer in spec['layers'] if layer['name']=='glue')
    source = ROOT/layer['dir']/filename
    if not (ROOT/'tools/rbxgs/Client/App/include').exists() or not (ROOT/'tools/openrbx').exists():
        pytest.skip('Native source dependencies not installed')
    overlay = rebuild.build_overlay('2008-06',spec['name'],spec['overlay'])
    recipe = libs.RECIPES[layer['includes_from_recipe']]
    includes = [(libs.LIBS/path).resolve() for path in recipe['include'] if path!='WINSDK']
    includes += [(ROOT/path).resolve() for path in layer.get('extra_includes',[])]
    defines = libs.RECIPES[layer['defines_from_recipe']]['defines'] + ' ' + layer.get('extra_defines','')
    result = rebuild.compile_direct('2008-06',[source],tmp_path/'objects',includes,defines,layer['flags'],overlay=overlay)
    assert result[str(source)][0],result[str(source)][1]
