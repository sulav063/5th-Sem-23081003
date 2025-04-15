<?php
class Counter
{
    public static $count = 0;

    public static function increment()
    {
        self::$count++;
    }

    public static function display()
    {
        echo "Count: " . self::$count . "<br>";
    }
}

Counter::increment();
Counter::increment();
Counter::display();  // Output: Count: 2
