#!/bin/bash
while IFS=$'\n' read -r line; do
    trim=$(echo "$line" | tr -d "[:space:]")
    md5=$(echo -n "${trim%%\/\/*}" | md5sum)
    md5=${md5:0:4}
    [ "${trim:~0}" == "$" ] && md5="@$md5@"
    echo "$md5 $line"
done

