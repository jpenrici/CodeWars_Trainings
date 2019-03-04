<!-- CODEWARS https://www.codewars.com/kata/563b662a59afc2b5120000c6 -->
<?php
    function nbYear($p0, $percent, $aug, $p) 
    {
        $years = 0;
        while ($p0 < $p){
            $p0 = $p0 + ($p0 * ($percent / 100) + $aug);
            $years++;
        }
        return $years;
    }
?>
