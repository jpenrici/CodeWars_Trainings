<?php
/*
CODEWARS
https://www.codewars.com/kata/554e4a2f232cdd87d9000038

"Complementary DNA"
*/

function DNA_strand($dna) {

    $dna = strtoupper($dna);
    for ($i = 0; $i < strlen($dna); $i++) {
        switch ($dna{$i}) {
            case 'A': $dna{$i} = 'T'; break;
            case 'C': $dna{$i} = 'G'; break;
            case 'T': $dna{$i} = 'A'; break;
            case 'G': $dna{$i} = 'C'; break;
        }
    }
    return $dna;
}

function compare($line, $str1, $str2) {
    if (strcmp($str1, $str2) == 0) echo "test ok!\n";
    else echo $line . " error!\n";
}

compare(__LINE__, "TTTT", DNA_strand("AAAA"));
compare(__LINE__, "AAAA", DNA_strand("TTTT"));
compare(__LINE__, "TAACG", DNA_strand("ATTGC"));
compare(__LINE__, "ATTGC", DNA_strand("TAACG"));
compare(__LINE__, "CATA", DNA_strand("GTAT"));
compare(__LINE__, "GTAT", DNA_strand("CATA"));
?>