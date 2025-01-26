#!/bin/bash

filesdir=$1
searchstr=$2

if [ -z "$filesdir" ] || [ -z "$searchstr" ]; then
  echo "Usage: writer.sh <filesdir> <searchstr>"
  exit 1
fi

if [ ! -d "$filesdir" ]; then
  echo "Error: $filesdir is not a directory"
  exit 1
fi

number_of_files=$(find "$filesdir" -type f  | wc -l)

matching_lines=$(grep -rF "$searchstr" "$filesdir" | wc -l )

echo "The number of files are $number_of_files and the number of matching lines are $matching_lines"
