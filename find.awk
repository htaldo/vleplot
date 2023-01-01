BEGIN { FS = "\t+" }
$1 ~ query { print $3 "\t" $4 "\t" $5 "\t" $9 " (" $1 ")"}
