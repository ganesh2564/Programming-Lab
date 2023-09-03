#!/bin/bash

output_file="latex_table.tex"
input_files="output1.txt output2.txt output3.txt"

echo "\\begin{tabular}{|c|$(for f in $input_files; do echo "c|"; done)}" > $output_file
echo "\\hline" >> $output_file
echo -n "Probab of Start/End & " >> $output_file
for f in $input_files; do
    prob=$(grep "Average Execution Time" $f | awk '{print $2}')
    echo -n "$prob & " >> $output_file
done
echo "\\" >> $output_file
echo "\\hline" >> $output_file

for f in $input_files; do
    prob=$(grep "Probability" $f | awk '{print $2}')
    echo -n "Probab of Ins/Del $prob & " >> $output_file
    for ff in $input_files; do
        time=$(grep "Probability $prob%" $ff | awk '{print $NF}' | cut -d' ' -f1)
        echo -n "$time & " >> $output_file
    done
    echo "\\" >> $output_file
    echo "\\hline" >> $output_file
done

echo "\\end{tabular}" >> $output_file
