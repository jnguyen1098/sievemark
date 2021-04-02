#!/usr/bin/env bash

benchmark() {
    for folder in */; do
        cd "$folder"
        printf "$(echo "$folder" | sed 's/.$//') $(./run.sh)\n"
        cd ..
    done
}

#!/usr/bin/env sh

echo '|language|time|' > _uhh
echo '|-|-|' >> _uhh
benchmark | sort -n -k 3 >> _data
paste -d '|' <(cut -d ' ' -f 1 < _data) <(cut -d ' ' -f 2 < _data) >> _uhh
cat _README.md _uhh > README.md
rm -rf _data
cat README.md
