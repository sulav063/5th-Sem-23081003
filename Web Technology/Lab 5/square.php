<?php
// Assigning array of numbers
$numbers = array(2, 4, 6, 8, 10);
// Finding squares using foreach
foreach ($numbers as $num) {
    $square = $num * $num;
    echo "Square of $num is $square<br>";
}
