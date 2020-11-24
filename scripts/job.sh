#!/bin/bash

if [[ $# -ne 0 ]]
then
    echo "ERROR: usage bash scripts/job.sh."
    exit 1
fi

for file in `ls src/`
do
    make run file=$file output=${file%.?}
done