#!/usr/bin/env bash

TMP_REPORT=_report
TMP_DATA=_data

benchmark() {
    for folder in */; do
        cd "$folder" || return
        printf "%s\n" "$(echo "$folder" | sed 's/.$//') $(./run.sh)"
        cd ..
    done
}

trap 'rm -rf $TMP_REPORT $TMP_DATA; exit' 0 2 3 15

echo '|language|time (in s)|' > "$TMP_REPORT"
echo '|-|-|' >> "$TMP_REPORT"
benchmark | sort -n -k 3 >> "$TMP_DATA"
paste -d '|' <(cut -d ' ' -f 1 < $TMP_DATA) <(cut -d ' ' -f 2 < $TMP_DATA) >> $TMP_REPORT
cat _README.md _report > README.md
cat README.md
