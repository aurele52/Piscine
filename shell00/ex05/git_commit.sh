#!/bin/bash
git log | grep -m5 ^commit | sed -e "s/commit //g"
