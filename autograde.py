#!/usr/bin/env python

import click
import os
import json
import re
from csvtools import qcsv
from CSE142L.jextract import extract as qjson

@click.command()
@click.option("--submission", required=True,  type=click.Path(exists=True), help="Test directory")
@click.option("--results", required=True, type = click.File(mode="w"), help="Where to put results")
def autograde(submission=None, results=None):

    speedup = float(qcsv(os.path.join(submission, "benchmark.csv"), field="speedup",where=["function"], _is=["sum_of_locations_solution"]))
    failures = qjson(json.load(open(os.path.join(submission, "regressions.json"))), ["testsuites", 0, "failures"])
    score = (speedup)/40.0*100.0,

    output = "tests passed" if failures == 0 else "Your code is incorrect",
    # https://gradescope-autograders.readthedocs.io/en/latest/specs/#output-format
    json.dump(dict(output="The autograder ran.",
                   visibility="visible",
                   stdout_visibility="visible",
                   tests=[ dict(score=(score if failures == 0 else 0),
                                max_score=100,
                                number="1",
                                output=output,
                                tags=[],
                                visibility="visible"),
                           dict(score=(1 if failures == 0 else 0),
                                max_score=0,
                                number="1",
                                output=output,
                                tags=[],
                                visibility="visible")
                   ],
                   leaderboard=[
                       dict(name="speedup", value=speedup)
                   ]
        ), results, indent=4)
        
if __name__== "__main__":
    autograde()
