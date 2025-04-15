<?php
function sum() {
    $args = func_get_args(); // Get all passed arguments
    $total = 0;

    foreach ($args as $num) {
        $total += $num;
    }
    return $total;
}
// Sum of 2 numbers
echo "Sum of 5 and 10: " . sum(5, 10) . "<br>";

// Sum of 3 numbers
echo "Sum of 3, 7 and 9: " . sum(3, 7, 9);
?>
