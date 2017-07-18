<!-- CODEWARS https://www.codewars.com/kata/555eded1ad94b00403000071 -->
<?php
    function series_sum($n) {
        if ($n == 0)
            return "0.00";
        $sum = 0.0;
        for ($i = 0; $i < $n; $i++) {
            $sum += 1.0 / (1.0 + $i + (2.0 * $i));
        }
        $decimalPlace = number_format($sum, 2, ".", "");
        return "$decimalPlace";
    }
?>
