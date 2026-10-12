"""RakNet-only source sweep for 2008-06; all submissions group-verified."""
import argparse
from pathlib import Path

from benchmarks.claude_continuation import run_sources
from benchmarks.match_campaign import Campaign
from roc import libs

ROOT = Path('work/raknet-2008')
CLIENT = '2008-06'


def sources(names, builds=(21022,)):
    for recipe in names:
        spec = libs.RECIPES[recipe]
        for file in libs.files_of(spec, libs.fetch(recipe)):
            for flags in spec.get('grid', libs.GRID):
                for build in builds:
                    yield libs.source_for(recipe, file, 'cpp', build, flags), dict(recipe=recipe, file=file, build=build)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('recipes', nargs='+')
    parser.add_argument('--server', default='http://127.0.0.1:8765')
    parser.add_argument('--jobs', type=int, default=3)
    parser.add_argument('--builds', default='21022')
    args = parser.parse_args()
    campaign = Campaign(ROOT, args.server)
    try:
        builds = tuple(int(x) for x in args.builds.split(','))
        run_sources(campaign, 'raknet-sweep', sources(args.recipes, builds), args.jobs)
    finally:
        campaign.api.close()
