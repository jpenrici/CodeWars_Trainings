<?php
/*
CODEWARS
https://www.codewars.com/kata/576b93db1129fcf2200001e6

"Sum without highest and lowest number"
*/

function sumArray($array) {
    if (empty($array))
        return 0;
    if ($array == NULL)
        return 0;
    if (count($array) <= 2)
        return 0;
    sort($array);
    return array_sum($array) - $array[0] - end($array);
}

function compare($num1, $num2) {
    echo $num1 == $num2 ? "true\n" : "false\n";
}

compare(16, sumArray([6, 2, 1, 8, 10]));
compare(6, sumArray([1, 1, 11, 2, 3]));
?>