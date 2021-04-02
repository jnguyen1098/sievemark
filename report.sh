#!/usr/bin/env sh

benchmark() {
    for folder in */; do
        cd "$folder"
        printf "$(echo "$folder" | sed 's/.$//') $(./run.sh)\n"
        cd ..
    done
}

#!/usr/bin/env sh

benchmark | sort -n -k 3 > _data
cat _README.md _data > README.md
rm -rf _data
cat README.md
