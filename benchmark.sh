#!/usr/bin/env sh

for folder in */; do
    cd "$folder"
    printf "$(echo "$folder" | sed 's/.$//'): $(./run.sh)"
    cd ..
done
