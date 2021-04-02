#!/usr/bin/env bash

benchmark() {
    for folder in */; do
        cd "$folder"
        printf "%s\n" "$(echo "$folder" | sed 's/.$//') $(./run.sh)"
        cd ..
    done
}

echo '|language|time|' > _report
echo '|-|-|' >> _report
benchmark | sort -n -k 3 >> _data
paste -d '|' <(cut -d ' ' -f 1 < _data) <(cut -d ' ' -f 2 < _data) >> _report
cat _README.md _report > README.md
rm -rf _data
rm -rf _report
cat README.md
