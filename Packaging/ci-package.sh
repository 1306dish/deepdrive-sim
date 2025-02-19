#!/usr/bin/env bash

set -e  # Abort script at first error, when a command exits with non-zero status (except in until or while loops, if-tests, list constructs)
set -u  # Attempt to use undefined variable outputs error message, and forces an exit
set -x  # Similar to verbose mode (-v), but expands commands
set -o pipefail  # Causes a pipeline to return the exit status of the last command in the pipe that returned a non-zero return value.

cd deepdrive-sim
git clean -fxd
git fetch origin ${DEEPDRIVE_BRANCH}
git checkout -qf ${DEEPDRIVE_COMMIT}

# https://stackoverflow.com/a/42982144/134077
export REQUESTS_CA_BUNDLE=/etc/ssl/certs/ca-certificates.crt

python3 -u Packaging/package.py --upload
